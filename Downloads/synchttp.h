#ifndef SYNCHTTP_H
#define SYNCHTTP_H

#include <QNetworkReply>
#include <QEventLoop>
#include <QBuffer>

class SyncHTTP: public QNetworkReply
{
    Q_OBJECT
    public:
        SyncHTTP( QObject * parent = 0 )
        :QHttp(parent),requestID(-1),status(false){}

        SyncHTTP( const QString & hostName, quint16 port = 80, QObject * parent = 0 )
        :QHttp(hostName,port,parent),requestID(-1),status(false){}

        virtual ~SyncHTTP(){}

        /// send GET request and wait until finished
        bool syncGet ( const QString & path, QIODevice * to = 0 )
        {
            connect(this,SIGNAL(requestFinished(int,bool)),SLOT(finished(int,bool)));
            requestID = get(path, to );
            loop.exec();
            return status;
        }

        bool syncPost ( const QString & path, QIODevice * data, QIODevice * to = 0 )
        {
            connect(this,SIGNAL(requestFinished(int,bool)),SLOT(finished(int,bool)));
            requestID = post(path, data , to );
            loop.exec();
            return status;
        }

        bool syncPost ( const QString & path, const QByteArray& data, QIODevice * to = 0 )
        {
            QBuffer buffer;
            buffer.setData(data);
            return syncPost(path,&buffer,to);
        }

    protected slots:
        virtual void finished(int idx, bool err)
        {
            if(idx!=requestID)
                return;
            status = !err;
            loop.exit();
        }

    private:
        int requestID;
        bool status;
        QEventLoop loop;
};

#endif // SYNCHTTP_H
