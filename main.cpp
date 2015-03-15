#include "MainWindow.h"
#include <QApplication>

#include "ServerDockWidget.h"
#include "SocketLogDockWidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    ServerDockWidget* server = new ServerDockWidget(&w);
    SocketLogDockWidget* log = new SocketLogDockWidget(server->socket(), &w);

    w.addDockWidget(Qt::RightDockWidgetArea, server);
    w.addDockWidget(Qt::RightDockWidgetArea, log);

    w.show();

    return a.exec();
}
