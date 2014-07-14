#-------------------------------------------------
#
# Project created by QtCreator 2014-07-01T14:21:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MotionStructure
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rotacionaldialog.cpp \
    globals.cpp \
    translacionaldialog.cpp

HEADERS  += mainwindow.h \
    rotacionaldialog.h \
    globals.h \
    translacionaldialog.h

FORMS    += mainwindow.ui \
    rotacionaldialog.ui \
    translacionaldialog.ui

RESOURCES += \
    icons/icons.qrc
