#include <QCoreApplication>
#include <QUrl>
#include <QNetworkRequest>
#include <QFile>
#include <QDebug>
#include <QDir>

#include "qdownload.h"
#include "Utils/utils.h"

QDownload::QDownload() : QObject(0)
{
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
    QObject::connect(&unfrezeTimer, SIGNAL(timeout()), SLOT(exitLoop()));
}

QDownload::~QDownload()
{
}


void QDownload::setTarget(const QString & t)
{
    this->target = t;

    QString path;
    path.append(QDir::currentPath());
    path.append("/Data/Images/");
    path.append(Utils::linkToName(target));

    fileName = path;


    qDebug() << "Target:" << target;
    qDebug() << "Path:" << fileName;
}

void QDownload::downloadFinished(QNetworkReply * data)
{
    QFile localFile(fileName);
    if (!localFile.open(QIODevice::WriteOnly))
    {
        return;
    }

    const QByteArray sdata = data->readAll();
    localFile.write(sdata);
    localFile.close();

    loop.exit();
    unfrezeTimer.stop();
}

void QDownload::download()
{
    QUrl url = QUrl::fromEncoded(this->target.toLocal8Bit());
    QNetworkRequest request(url);
    QObject::connect(manager.get(request), SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));

    loop.exec();
    unfrezeTimer.start(1000 * 60 * 2);
}

void QDownload::downloadProgress(qint64 recieved, qint64 total)
{
    //qDebug() << fileName;
    //qDebug() << "  " << recieved << "/" << total << " bytes";
}

void QDownload::exitLoop()
{
    loop.exit();
}
