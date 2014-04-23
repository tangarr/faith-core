#-------------------------------------------------
#
# Project created by QtCreator 2014-04-23T16:15:46
#
#-------------------------------------------------

QT       -= gui

TARGET = faith-core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += faithcore.cpp

HEADERS += faithcore.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
