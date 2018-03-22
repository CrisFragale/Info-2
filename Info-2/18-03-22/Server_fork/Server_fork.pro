QT += core
QT -= gui

TARGET = Server_fork
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    server.c \
    server_fnt.c \
    sock-lib.c

HEADERS += \
    defaults.h \
    sock-lib.h

