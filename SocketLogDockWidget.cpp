#include "SocketLogDockWidget.h"
#include "ui_SocketLogDockWidget.h"
#include "CurvytronSocket.h"
#include "Events/AbstractEvent.h"
#include <QTime>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

SocketLogDockWidget::SocketLogDockWidget(CurvytronSocket& socket, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::SocketLogDockWidget),
    _socket(socket)
{
    ui->setupUi(this);
    connect(
        &_socket, &CurvytronSocket::eventReceived,
        this, &SocketLogDockWidget::onEventReceived
    );
}

SocketLogDockWidget::~SocketLogDockWidget()
{
    delete ui;
}

void SocketLogDockWidget::onEventReceived(const AbstractEvent &event)
{
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QTime::currentTime().toString()));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(event.id()));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(event.toString()));
}
