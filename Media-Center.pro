QT += core
QT += network
QT -= gui

TARGET = Media-Center
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    MediaCenterMainApp.cpp \
    RSSReader.cpp

HEADERS += \
    RSSReader.h \
    MediaCenterMainApp.h

