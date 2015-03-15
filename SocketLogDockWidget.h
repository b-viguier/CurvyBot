#ifndef SOCKETLOGDOCKWIDGET_H
#define SOCKETLOGDOCKWIDGET_H

#include <QDockWidget>

class QWebSocket;

namespace Ui {
class SocketLogDockWidget;
}

class SocketLogDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit SocketLogDockWidget(QWebSocket& socket, QWidget *parent = 0);
    ~SocketLogDockWidget();

private slots:
    void onTextMessageReceived(const QString&);

private:
    Ui::SocketLogDockWidget *ui;
    QWebSocket& _socket;
};

#endif // SOCKETLOGDOCKWIDGET_H
