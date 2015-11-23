#-------------------------------------------------
#
# Project created by QtCreator 2015-11-14T19:51:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LifeTime
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    timeribbon.cpp \
    mygraphicsview.cpp \
    periodetemps.cpp \
    periodetempsgraphicsitem.cpp \
    periodetempsmois.cpp \
    ruban.cpp \
    sceneruban.cpp

HEADERS  += mainwindow.h \
    timeribbon.h \
    mygraphicsview.h \
    periodetemps.h \
    periodetempsgraphicsitem.h \
    periodetempsmois.h \
    ruban.h \
    sceneruban.h

FORMS    += mainwindow.ui
