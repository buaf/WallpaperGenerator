#ifndef QDOWNLOAD_H
#define QDOWNLOAD_H

#include <QEventLoop>
#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTimer>

class QDownload : public QObject

{
    Q_OBJECT
public:
    explicit QDownload();
    ~QDownload();

    void setTarget(const QString & t);

private:
    QNetworkAccessManager manager;

    QString target;
    QString fileName;

    QEventLoop loop;
    QTimer unfrezeTimer;


public slots:
    void download();
    void downloadFinished(QNetworkReply* data);
    void downloadProgress(qint64 recieved, qint64 total);

    void exitLoop();
};

#endif // QDOWNLOAD_H
