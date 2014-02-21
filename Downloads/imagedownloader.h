#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H

#include <QString>

class ImageDownloader
{
private:
    QString searchName;
    QStringList imageList;

public:
    ImageDownloader();
    void downloadNewImages();
};

#endif // IMAGEDOWNLOADER_H
