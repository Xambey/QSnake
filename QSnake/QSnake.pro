#-------------------------------------------------
#
# Project created by QtCreator 2016-07-13T10:04:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSnake
TEMPLATE = app


SOURCES += \
    bin/itemsnake.cpp \
    bin/snake.cpp \
    Gui/mainwindow.cpp \
    System/gamesystem.cpp \
    System/main.cpp

HEADERS  += \
    Gui/mainwindow.h \
    Include/itemsnake.h \
    Include/snake.h \
    Include/snakebase.h \
    System/gamesystem.h \
    Include/mode.h

FORMS += \
    Gui/mainwindow.ui

RC_FILE = Resources/qsnake.rc
