TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    item.cpp \
    jogador.cpp \
    monstro.cpp \
    engine.cpp \
    interface.cpp

HEADERS += \
    item.h \
    jogador.h \
    monstro.h \
    interface.h \
    engine.h

DISTFILES += \
    status_basicos.txt
