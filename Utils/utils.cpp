#include "utils.h"

QString Utils::getRandomString(int strLen, bool numbers, bool symbols)
{
    QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    if (numbers)
    {
        possibleCharacters.append("123456789");
    }

    if (symbols)
    {
        possibleCharacters.append("!@#$%^&*()_+{}?><");
    }

    QString randomString;
    for(int i=0; i<strLen; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }

    return randomString;
}

QString Utils::getRusRandomString(int strLen)
{
    QString possibleCharacters("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ");

    QString randomString;
    for(int i=0; i<strLen; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }

    return randomString;
}

QString Utils::cutImageLink(QString str)
{
    if (str.indexOf(".jpg", 0, Qt::CaseInsensitive) != -1)
    {
        str.resize(str.indexOf(".jpg", 0, Qt::CaseInsensitive) + 4);
        return str;
    }

    if (str.indexOf(".png", 0, Qt::CaseInsensitive) != -1)
    {
        str.resize(str.indexOf(".png", 0, Qt::CaseInsensitive) + 4);
        return str;
    }

    if (str.indexOf(".gif", 0, Qt::CaseInsensitive) != -1)
    {
        str.resize(str.indexOf(".gif", 0, Qt::CaseInsensitive) + 4);
        return str;
    }

    if (str.indexOf(".jpeg", 0, Qt::CaseInsensitive) != -1)
    {
        str.resize(str.indexOf(".jpeg", 0, Qt::CaseInsensitive) + 5);
        return str;
    }

    return str;
}

bool Utils::isImageLink(QString str)
{
    if (str.indexOf(".jpg", 0, Qt::CaseInsensitive) != -1)
    {
        return true;
    }

    if (str.indexOf(".png", 0, Qt::CaseInsensitive) != -1)
    {
        return true;
    }

    if (str.indexOf(".gif", 0, Qt::CaseInsensitive) != -1)
    {
        return true;
    }

    if (str.indexOf(".jpeg", 0, Qt::CaseInsensitive) != -1)
    {
        return true;
    }

    return false;
}

QString Utils::linkToName(QString link)
{
    int i = link.lastIndexOf("/") + 1;
    return link.mid(i);
}
