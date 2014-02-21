#include <QFile>
#include <QDebug>
#include <QDir>

#include "imagedownloader.h"
#include "contentparser.h"
#include "qdownload.h"

#include "Utils/utils.h"

ImageDownloader::ImageDownloader()
{
    int probability = qrand()%100;

    if (probability > 49)
    {
        searchName = Utils::getRandomString(5, false, false);
    }
    else
    {
        searchName = Utils::getRusRandomString(5);
    }

    ContentParser parser(searchName);
    imageList = parser.getMediaLinks();
}

void ImageDownloader::downloadNewImages()
{
    QDownload download;
    foreach (QString link, imageList)
    {
        download.setTarget(link);
        download.download();
    }
}

