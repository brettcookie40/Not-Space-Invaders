#-------------------------------------------------
#
# Project created by QtCreator 2017-04-24T02:39:18
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FirstGame
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


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    score.cpp \
    game.cpp \
    player.cpp \
    health.cpp \
    enemy2.cpp \
    endscreen.cpp \
    homescreen.cpp \
    enemy3.cpp \
    enemy4.cpp \
    enemy5.cpp \
    bullet2.cpp \
    bullet3.cpp \
    bullet4.cpp \
    enemy6.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    score.h \
    game.h \
    player.h \
    health.h \
    enemy2.h \
    endscreen.h \
    homescreen.h \
    enemy3.h \
    enemy4.h \
    enemy5.h \
    bullet2.h \
    bullet3.h \
    bullet4.h \
    enemy6.h

FORMS    +=

RESOURCES += \
    res.qrc
