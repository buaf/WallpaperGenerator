#ifndef IMAGETRANSFORMGENERATOR_H
#define IMAGETRANSFORMGENERATOR_H

#include <QPixmap>
#include <QVector>
#include <QDir>


struct QRandComparer
{
    template<typename T>
    bool operator()(const T & a, const T & b) const
    {
        Q_UNUSED(a)
        Q_UNUSED(b)
        int result = qrand()%50;
        return result > 25;
    }
};



class ImageTransformGenerator
{
public:
    static void mixedImageTransform(QPixmap & pixmap);
    static QVector<QDir> loadRandImageList(int count);
    static QPixmap getRandomImagePart(QString file);
};

#endif // IMAGETRANSFORMGENERATOR_H
