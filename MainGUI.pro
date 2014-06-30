#-------------------------------------------------
#
# Project created by QtCreator 2014-06-27T16:13:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainGUI
TEMPLATE = app


SOURCES += main.cpp\
        maingui.cpp \
    jhtoolbox.cpp \
    picwidget.cpp

HEADERS  += maingui.h \
    jhtoolbox.h \
    picwidget.h

FORMS    += maingui.ui \
    picwidget.ui

OTHER_FILES +=

RESOURCES += \
    MainGUI.qrc
