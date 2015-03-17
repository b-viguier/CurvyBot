#include "ServerDockWidget.h"
#include "ui_ServerDockWidget.h"
#include <QWebSocket>

ServerDockWidget::ServerDockWidget(QWebSocket& socket, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ServerDockWidget),
    _socket(socket)
{
    ui->setupUi(this);
    connect(
        &_socket, &QWebSocket::connected,
        this, &ServerDockWidget::onSocketConnected
    );
    connect(
        &_socket, &QWebSocket::disconnected,
        this, &ServerDockWidget::onSocketDisconnected
    );
}

ServerDockWidget::~ServerDockWidget()
{
    delete ui;
}

QWebSocket &ServerDockWidget::socket()
{
    return _socket;
}

void ServerDockWidget::on_connectButton_clicked()
{
    ui->connectButton->setEnabled(false);
    ui->state->setText(tr("Connecting..."));
    _socket.open(QUrl(ui->url->text()));
}

void ServerDockWidget::on_disconnectButton_clicked()
{
    ui->state->setText(tr("Disconnecting..."));
    ui->disconnectButton->setEnabled(false);
    _socket.close();
}

void ServerDockWidget::onSocketConnected()
{
    ui->disconnectButton->setEnabled(true);
    ui->state->setText(tr("Connected"));
}

void ServerDockWidget::onSocketDisconnected()
{
    ui->connectButton->setEnabled(true);
    ui->state->setText(tr("Disconnected"));
}
