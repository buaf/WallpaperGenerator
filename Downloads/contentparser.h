#ifndef CONTENTPARSER_H
#define CONTENTPARSER_H

#include <QStringList>
#include <QObject>
#include <QEventLoop>
#include <QNetworkReply>
#include <QTimer>

class ContentParser : QObject
{
    Q_OBJECT

private:
    QNetworkAccessManager * nam;

    QEventLoop loop;
    QTimer unfrezeTimer;

    QString data;

public:
    ContentParser(QString name);
    ~ContentParser();

    void getGoogleData(QString query);
    QStringList getMediaLinks();

private slots:
    void exitLoop();
    void finished(QNetworkReply *reply);
};

#endif // CONTENTPARSER_H
