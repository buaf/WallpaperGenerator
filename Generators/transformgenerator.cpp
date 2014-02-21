#include <QPixmap>
#include <QImage>
#include <QPainter>
#include <QStaticText>

#include "transformgenerator.h"
#include "mainwindow.h"
#include "Utils/utils.h"

QPixmap TransformGenerator::generatePixmap()
{
    QImage img(MainWindow::desctopWidth, MainWindow::desctopHeight, QImage::Format_RGB32);
    img.fill(QColor(Qt::white).rgb());

    int r;
    int g;
    int b;

    for (int x = 0; x < MainWindow::desctopWidth; ++x) {
        for (int y = 0; y < MainWindow::desctopHeight; ++y) {
            r = qrand()%256;
            g = qrand()%256;
            b = qrand()%256;
            img.setPixel(x, y, qRgb(r, g, b));
        }
    }

    return QPixmap::fromImage(img);
}

void TransformGenerator::randTransform(QPixmap & pixmap)
{
    int desctopWidth = MainWindow::desctopWidth;
    int desctopHeight = MainWindow::desctopHeight;

    QPainter paint(&pixmap);

    for (int i = 0; i < 10000; i ++) {
        paint.drawArc(qrand()%desctopWidth, qrand()%desctopHeight, qrand()%50, qrand()%50, qrand()%100, qrand()%100);
        paint.drawRect(qrand()%desctopWidth, qrand()%desctopHeight, qrand()%50, qrand()%50);
        paint.drawChord(qrand()%desctopWidth, qrand()%desctopHeight, qrand()%50, qrand()%50, qrand()%100, qrand()%100);
        paint.drawEllipse(qrand()%desctopWidth, qrand()%desctopHeight, qrand()%50, qrand()%50);
        paint.drawPixmap(qrand()%desctopWidth, qrand()%desctopHeight, qrand()%200, qrand()%200, pixmap);
        paint.drawLine(QLine(qrand()%desctopWidth, qrand()%desctopHeight, qrand()%desctopWidth, qrand()%desctopHeight));
        paint.drawStaticText(qrand()%desctopWidth, qrand()%desctopHeight, QStaticText(Utils::getRandomString(50, true, true)));
        paint.rotate(qrand()%360);

        int r = qrand()%256;
        int g = qrand()%256;
        int b = qrand()%256;
        QBrush brush = QBrush(QColor(qRgb(r, g, b)));
        QPen pen = QPen(brush, qrand()%50);
        paint.setPen(pen);
    }
}
