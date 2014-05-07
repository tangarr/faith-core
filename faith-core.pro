#-------------------------------------------------
#
# Project created by QtCreator 2014-04-23T16:15:46
#
#-------------------------------------------------

QT       -= gui
QT       += network

TARGET = faith-core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += faithcore.cpp \
    faithmessage.cpp \
    faithobject.cpp

HEADERS += faithcore.h \
    faithmessage.h \
    faithobject.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
