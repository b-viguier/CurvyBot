#include "SocketLogDockWidget.h"
#include "ui_SocketLogDockWidget.h"
#include <QWebSocket>

SocketLogDockWidget::SocketLogDockWidget(QWebSocket& socket, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::SocketLogDockWidget),
    _socket(socket)
{
    ui->setupUi(this);
    connect(
        &_socket, &QWebSocket::textMessageReceived,
        this, &SocketLogDockWidget::onTextMessageReceived
    );
}

SocketLogDockWidget::~SocketLogDockWidget()
{
    delete ui;
}

void SocketLogDockWidget::onTextMessageReceived(const QString &msg)
{
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QTime::currentTime().toString()));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(msg));
}
