#include <QDebug>
#include <QtNetwork/QNetworkReply>
#include <QThread>

#include "contentparser.h"

#include "Utils/utils.h"

ContentParser::ContentParser(QString name)
{
    nam = new QNetworkAccessManager(this);
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));
    connect(&unfrezeTimer, SIGNAL(timeout()), SLOT(exitLoop()));
    getGoogleData(name);
}

ContentParser::~ContentParser()
{
    delete nam;
}

void ContentParser::getGoogleData(QString query)
{
    QString q("https://www.google.com/images?hl=ru&q=");
    q.append(query);

    qDebug() << q;

    QUrl httpRequest(q);

    QNetworkRequest request;
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    request.setUrl(httpRequest);
    request.setRawHeader("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/32.0.1700.107 Safari/537.36");
    QNetworkReply * reply = nam->get(request);

    loop.exec();
    unfrezeTimer.start(1000 * 60 * 2);
}

QStringList ContentParser::getMediaLinks()
{
    QStringList list;

    QRegExp rx("imgurl=\s*([\"'][^\"']+[\"']|[^>]+)&amp;");

    int pos = 0;

    while ((pos = rx.indexIn(data, pos)) != -1)
    {
        if (Utils::isImageLink(rx.cap(1)))
        {
            list << Utils::cutImageLink(rx.cap(1));
        }
        pos += rx.matchedLength();
    }

    return list;
}

void ContentParser::finished(QNetworkReply * reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        data = reply->readAll();
        loop.exit();
        unfrezeTimer.stop();
        delete reply;
    }
    else
    {
        data = reply->readAll();
        loop.exit();
        unfrezeTimer.stop();
        delete reply;
    }
}

void ContentParser::exitLoop()
{
    loop.exit();
}
