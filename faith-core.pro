#-------------------------------------------------
#
# Project created by QtCreator 2014-04-23T16:15:46
#
#-------------------------------------------------

QT       -= gui
QT       += network

TARGET = faith-core
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += faithcore.cpp \
    faithmessage.cpp \
    faithdatabuilder.cpp \
    fdstring.cpp \
    fdstringlist.cpp \
    fdproposedip.cpp \
    fdhostinfo.cpp \
    fdfile.cpp \
    fdiplist.cpp

HEADERS += faithcore.h \
    faithmessage.h \
    faithdata.h \
    faithdatabuilder.h \
    fdstring.h \
    fdstringlist.h \
    fdproposedip.h \
    fdhostinfo.h \
    fdfile.h \
    faithMacro.h \
    fdiplist.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
