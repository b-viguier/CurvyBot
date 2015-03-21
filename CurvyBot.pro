#-------------------------------------------------
#
# Project created by QtCreator 2015-03-15T13:57:46
#
#-------------------------------------------------

QT       += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CurvyBot
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    MainWindow.cpp \
    SocketLogDockWidget.cpp \
    ServerDockWidget.cpp \
    CurvytronSocket.cpp \
    RoomsDockWidget.cpp \
    Events/AbstractEvent.cpp \
    Events/UnknownEvent.cpp \
    Events/RoomOpenEvent.cpp \
    Events/RoomFetchEvent.cpp

HEADERS  += \
    MainWindow.h \
    SocketLogDockWidget.h \
    ServerDockWidget.h \
    CurvytronSocket.h \
    RoomsDockWidget.h \
    Events/AbstractEvent.h \
    Events/EventDispatcher.h \
    Events/AbstractEventCommand.h \
    Events/AbstractEventDispatcher.h \
    Events/EventCommand.h \
    Events/UnknownEvent.h \
    Events/RoomOpenEvent.h \
    Events/RoomFetchEvent.h

FORMS    += \
    MainWindow.ui \
    SocketLogDockWidget.ui \
    ServerDockWidget.ui \
    RoomsDockWidget.ui
