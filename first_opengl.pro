#-------------------------------------------------
#
# Project created by QtCreator 2015-11-19T19:44:34
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = first_opengl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    nehewidget.cpp

HEADERS  += mainwindow.h \
    nehewidget.h

FORMS    += mainwindow.ui

LIBS    += -lglut -lGLU
