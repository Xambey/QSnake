#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T23:03:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSnake
TEMPLATE = app
RESOURCES +=

SOURCES += main.cpp\
        mainwindow.cpp \
    itemsnake.cpp \
    snake.cpp \
    gamesystem.cpp

HEADERS  += mainwindow.h \
    itemsnake.h \
    snake.h \
    snakebase.h \
    gamesystem.h

FORMS    += mainwindow.ui
RC_FILE = qsnake.rc
