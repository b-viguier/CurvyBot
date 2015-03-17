#ifndef SERVERDOCKWIDGET_H
#define SERVERDOCKWIDGET_H

#include <QDockWidget>

class QWebSocket;

namespace Ui {
class ServerDockWidget;
}

class ServerDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit ServerDockWidget(QWebSocket& _socket, QWidget *parent = 0);
    ~ServerDockWidget();

    QWebSocket& socket();

private slots:
    void on_connectButton_clicked();
    void on_disconnectButton_clicked();
    void onSocketConnected();
    void onSocketDisconnected();

private:
    Ui::ServerDockWidget *ui;

    QWebSocket &_socket;
};

#endif // SERVERDOCKWIDGET_H
