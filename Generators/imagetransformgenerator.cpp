#include <QPixmap>
#include <QImage>
#include <QPainter>
#include <QStaticText>
#include <QDir>
#include <QDebug>
#include <QVector>
#include <QTime>

#include <stdio.h>

#include "imagetransformgenerator.h"
#include "mainwindow.h"


void ImageTransformGenerator::mixedImageTransform(QPixmap & pixmap)
{
    QPainter paint(&pixmap);
    int width = pixmap.width();
    int height = pixmap.height();

    QVector<QDir> randomImages = ImageTransformGenerator::loadRandImageList(20);
    foreach (QDir img, randomImages)
    {
        for (int i = 0; i < 25; i++)
        {
            QPixmap pix = ImageTransformGenerator::getRandomImagePart(img.absolutePath());
            paint.rotate(qrand()%360);
            paint.drawPixmap(qrand()%width, qrand()%height, pix.width(), pix.height(), pix);
        }
    }
}

QVector<QDir> ImageTransformGenerator::loadRandImageList(int count)
{
    const char * currentPath = QDir::currentPath().toStdString().c_str();
    QString imagesPath(currentPath);
    imagesPath.append("/Data/Images");

    QDir imageDir(imagesPath.toStdString().c_str());
    QStringList imgs = imageDir.entryList(QDir::Files);
    qSort(imgs.begin(), imgs.end(), QRandComparer());

    QVector<QDir> randImages;
    foreach (QString img , imgs)
    {
        if (count-- > 0)
        {
            randImages.append(QString().append(imagesPath).append("/").append(img));
        }
        else
        {
            break;
        }
    }
    return randImages;
}

QPixmap ImageTransformGenerator::getRandomImagePart(QString file)
{
    QPixmap pixmap(file);

    if (pixmap.data_ptr() == NULL)
    {
        qDebug() << "BAD IMAGE : " << file;
        return QPixmap(1,1);
    }

    int width = pixmap.width();
    int height = pixmap.height();

    int x = qrand()%width;
    int y = qrand()%height;

    int wMaxSize = qrand()%(width - x);
    int hMaxSize = qrand()%(height - y);

    return pixmap.copy(x, y, wMaxSize, hMaxSize);
}
