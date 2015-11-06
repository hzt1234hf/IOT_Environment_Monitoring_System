#-------------------------------------------------
#
# Project created by QtCreator 2015-03-17T01:31:52
#
#-------------------------------------------------

QT += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qextserialbase.cpp \
    posix_qextserialport.cpp \
    linecharwidget.cpp \
    clientserver.cpp \
    signin_gui.cpp

HEADERS  += mainwindow.h \
    qextserialbase.h \
    posix_qextserialport.h \
    linecharwidget.h \
    clientserver.h \
    comDef.h \
    signin_gui.h

FORMS    += mainwindow.ui \
    signin_gui.ui

RESOURCES += \
    myImg.qrc

QT += sql
