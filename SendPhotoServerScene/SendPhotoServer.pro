#-------------------------------------------------
#
# Project created by QtCreator 2022-12-24T14:56:39
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SendPhotoServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp

HEADERS  += mainwindow.h \
    server.h

FORMS    += mainwindow.ui
