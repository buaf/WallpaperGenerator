#include <QLabel>
#include <QImage>
#include <QTime>
#include <QPixmap>
#include <QDesktopWidget>
#include <QDebug>
#include <QPainter>
#include <QStaticText>
#include <QFile>
#include <QFileInfo>
#include <QApplication>

#include <cstdio>
#include <stdio.h>

#include "mainwindow.h"
#include "Utils/utils.h"
#include "Generators/transformgenerator.h"
#include "Generators/imagetransformgenerator.h"
#include "Desktop/desktopmanager.h"
#include "Downloads/imagedownloader.h"

int MainWindow::desctopHeight = 600;
int MainWindow::desctopWidth = 600;

MainWindow::MainWindow()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QDesktopWidget desktop;
    MainWindow::desctopWidth = desktop.geometry().width();
    MainWindow::desctopHeight = desktop.geometry().height();

    QDir imgDir;
    imgDir.mkpath(QString("Data/Images"));

    deleteOldImages();

    ImageDownloader downloader;
    downloader.downloadNewImages();

    updateImage();

    std::exit(1);
}

MainWindow::~MainWindow()
{
}


void MainWindow::updateImage()
{
    QPixmap pixmap = TransformGenerator::generatePixmap();
    TransformGenerator::randTransform(pixmap);
    ImageTransformGenerator::mixedImageTransform(pixmap);

    pixmap.save("Data/CurrentImage.jpg");

    QFile file("Data/CurrentImage.jpg");
    QFileInfo info(file);
    
    qDebug() << info.absoluteFilePath();

    DesktopManager::setWallpapper(info.absoluteFilePath());
}

void MainWindow::deleteOldImages()
{
    QString imagesPath;
    imagesPath.append(QDir::currentPath());
    imagesPath.append("/Data/Images");

    qDebug() << "IMAGES_PATH:" << imagesPath;

    QDir imagesDir(imagesPath);
    QStringList imagesList = imagesDir.entryList(QDir::Files);

    qDebug() << "IMAGES_LIST_SIZE:" << imagesList.size();

    if (imagesList.size() > 500)
    {
        foreach (QString file, imagesList)
        {
            QString fileDir("Data/Images/");
            fileDir.append(file);

            if( std::remove(fileDir.toStdString().c_str()) != 0 )
            {
                qDebug() << "Error deleting file:" << fileDir;
            }
            else
            {
                qDebug() << "File successfully deleted" << fileDir;
            }
        }
    }
}
