#include <QDebug>
#include <iostream>
#include <QSettings>

#include "desktopmanager.h"

//LINUX
#if defined(Q_OS_LINUX)
void DesktopManager::setWallpapper(QString link)
{
    QString conCommand = QString("gsettings set org.gnome.desktop.background picture-uri 'file://%1'").arg(link.toStdString().c_str());
    std::system(conCommand.toStdString().c_str());
}
#endif


//WINDOWS
#if defined(Q_OS_WIN32)
#include <windows.h>
void DesktopManager::setWallpapper(QString link)
{
    link.replace("/","\\\\");

    QSettings appSettings( "HKEY_CURRENT_USER\\Control Panel\\Desktop", QSettings::NativeFormat);

    //Set new background path
    appSettings.setValue("Wallpaper", link);
    QByteArray ba = link.toLatin1();
    SystemParametersInfoA(SPI_SETDESKWALLPAPER,
                          0,
                          (void*)ba.data(),
                          SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);
}
#endif
