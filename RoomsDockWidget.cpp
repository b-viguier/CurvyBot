#include "RoomsDockWidget.h"
#include "ui_RoomsDockWidget.h"

#include "CurvytronSocket.h"
#include "Events/RoomOpenEvent.h"
#include <QWebSocket>
#include <QJsonObject>


RoomsDockWidget::RoomsDockWidget(CurvytronSocket& socket, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::RoomsDockWidget),
    _socket(socket)
{
    ui->setupUi(this);
    _socket.registerListener<RoomOpenEvent>(*this, &RoomsDockWidget::onRoomOpen);
}

RoomsDockWidget::~RoomsDockWidget()
{
    delete ui;
}

void RoomsDockWidget::onRoomOpen(const RoomOpenEvent& event)
{
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(event.name()));
}

