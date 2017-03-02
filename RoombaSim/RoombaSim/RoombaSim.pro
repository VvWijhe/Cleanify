#-------------------------------------------------
#
# Project created by QtCreator 2017-02-28T14:04:08
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RoombaSim
TEMPLATE = app


SOURCES += main.cpp \
    room.cpp \
    roomba.cpp \
    roombasim.cpp

HEADERS  += \
    room.h \
    roomba.h \
    roombasim.h

FORMS    += \
    roombasim.ui
