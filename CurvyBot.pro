#-------------------------------------------------
#
# Project created by QtCreator 2015-03-15T13:57:46
#
#-------------------------------------------------

QT       += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CurvyBot
TEMPLATE = app


SOURCES += main.cpp \
    MainWindow.cpp \
    SocketLogDockWidget.cpp \
    ServerDockWidget.cpp

HEADERS  += \
    MainWindow.h \
    SocketLogDockWidget.h \
    ServerDockWidget.h

FORMS    += \
    MainWindow.ui \
    SocketLogDockWidget.ui \
    ServerDockWidget.ui
