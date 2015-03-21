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
    ui->listWidget->insertItem(
        0,
        QString("[%1] %2").arg(QTime::currentTime().toString()).arg(event.toString())
    );
}
