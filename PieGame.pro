#-------------------------------------------------
#
# Project created by QtCreator 2015-12-12T15:30:31
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PieGame
TEMPLATE = app


SOURCES += main.cpp \
    pie.cpp \
    game.cpp \
    score.cpp \
    player.cpp \
    timer.cpp \
    global.cpp \
    startbutton.cpp \
    paul.cpp \
    enemy.cpp

HEADERS  += \
    pie.h \
    game.h \
    score.h \
    player.h \
    timer.h \
    global.h \
    startbutton.h \
    paul.h \
    enemy.h

FORMS    +=

RESOURCES += \
    res.qrc
