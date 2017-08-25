#-------------------------------------------------
#
# Project created by QtCreator 2017-04-17T00:20:56
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += gamepad

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cam_platform
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    joyreader.cpp \
    robo_proto.cpp

HEADERS  += mainwindow.h \
    joyreader.h \
    robo_proto.h

FORMS    += mainwindow.ui
