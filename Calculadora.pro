#-------------------------------------------------
#
# Project created by QtCreator 2018-09-24T10:11:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculadora
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Expression.cpp

HEADERS  += mainwindow.h \
    DoubleList.h \
    DobleNode.h \
    Expression.h \
    Expression.h

FORMS    += mainwindow.ui
