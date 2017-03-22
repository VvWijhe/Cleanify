#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T11:40:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pc_applicatie
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    clientdialog.cpp

HEADERS  += mainwindow.h \
    client.h \
    clientdialog.h \
    roomba_commands.h

FORMS    += mainwindow.ui \
    clientdialog.ui

RESOURCES += \
    recources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/restbed/build/release/ -lrestbed
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/restbed/build/debug/ -lrestbed
else:unix: LIBS += -L$$PWD/restbed/build/ -lrestbed

INCLUDEPATH += $$PWD/restbed/build
DEPENDPATH += $$PWD/restbed/build

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/restbed/build/release/librestbed.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/restbed/build/debug/librestbed.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/restbed/build/release/restbed.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/restbed/build/debug/restbed.lib
else:unix: PRE_TARGETDEPS += $$PWD/restbed/build/librestbed.a
