#ifndef TRANSFORMGENERATOR_H
#define TRANSFORMGENERATOR_H

#include <QPixmap>

class TransformGenerator
{
public:
    static QPixmap generatePixmap();
    static void randTransform(QPixmap & pixmap);
};

#endif // IMAGETRANSFORMGENERATOR_H
