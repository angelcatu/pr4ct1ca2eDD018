#-------------------------------------------------
#
# Project created by QtCreator 2018-09-23T18:50:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Practica2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cliente_proveedor.cpp \
    nodoavl.cpp \
    nodobb.cpp \
    arbolbb.cpp \
    objetoarbol.cpp \
    uieliminar.cpp \
    instanciaarbole.cpp \
    arbolbinario_global.cpp


HEADERS += \
        mainwindow.h \
    cliente_proveedor.h \
    nodoavl.h \
    nodobb.h \
    arbolbb.h \
    objetoarbol.h \
    ventanaeliminar.h \
    uieliminar.h \
    instanciaarbole.h \
    arbolbinario_global.hpp

FORMS += \
        mainwindow.ui \
    uieliminar.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    entrada.csv
