#ifndef UTILS_H
#define UTILS_H

#include <QString>

class Utils
{
public:
    static QString getRandomString(int strLen, bool numbers, bool symbols);
    static QString getRusRandomString(int strLen);
    static QString cutImageLink(QString str);
    static bool isImageLink(QString str);
    static QString linkToName(QString link);
};

#endif // UTILS_H
