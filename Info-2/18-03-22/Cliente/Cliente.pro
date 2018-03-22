QT += core
QT -= gui

TARGET = Cliente
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    client.c \
    sock-lib.c

HEADERS += \
    sock-lib.h \
    defaults.h

