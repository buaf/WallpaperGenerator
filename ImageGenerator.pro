#-------------------------------------------------
#
# Project created by QtCreator 2014-02-16T16:48:27
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageGenerator
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    Utils/utils.cpp \
    Generators/transformgenerator.cpp \
    Desktop/desktopmanager.cpp \
    Generators/imagetransformgenerator.cpp \
    Downloads/imagedownloader.cpp \
    Downloads/contentparser.cpp \
    Downloads/qdownload.cpp

HEADERS  += \
    mainwindow.h \
    Utils/utils.h \
    Generators/transformgenerator.h \
    Desktop/desktopmanager.h \
    Generators/imagetransformgenerator.h \
    Downloads/imagedownloader.h \
    Downloads/contentparser.h \
    Downloads/qdownload.h
