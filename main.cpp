#include "MainWindow.h"
#include <QApplication>
#include <QWebSocket>

#include "ServerDockWidget.h"
#include "SocketLogDockWidget.h"
#include "RoomsDockWidget.h"

#include "CurvytronSocket.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QWebSocket socket;
    CurvytronSocket c_socket(socket);

    auto server = new ServerDockWidget(socket, &w);
    auto log = new SocketLogDockWidget(c_socket, &w);
    auto rooms = new RoomsDockWidget(c_socket, &w);

    w.addDockWidget(Qt::RightDockWidgetArea, server);
    w.addDockWidget(Qt::BottomDockWidgetArea, log);
    w.addDockWidget(Qt::LeftDockWidgetArea, rooms);

    w.show();

    return a.exec();
}
