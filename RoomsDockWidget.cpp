#include "RoomsDockWidget.h"
#include "ui_RoomsDockWidget.h"

#include "CurvytronSocket.h"
#include "Events/RoomOpenEvent.h"
#include "Events/RoomFetchEvent.h"
#include "Events/RoomCloseEvent.h"
#include "Events/RoomJoinRequest.h"
#include <QWebSocket>
#include <QJsonObject>


RoomsDockWidget::RoomsDockWidget(CurvytronSocket& socket, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::RoomsDockWidget),
    _socket(socket)
{
    ui->setupUi(this);
    _socket.registerListener<RoomOpenEvent>(*this, &RoomsDockWidget::onRoomOpen);
    _socket.registerListener<RoomPlayersEvent>(*this, &RoomsDockWidget::onRoomPlayers);
    _socket.registerListener<RoomCloseEvent>(*this, &RoomsDockWidget::onRoomClose);
    connect(&_socket.socket(), &QWebSocket::connected, this, &RoomsDockWidget::onSocketConnected);
}

RoomsDockWidget::~RoomsDockWidget()
{
    delete ui;
}

void RoomsDockWidget::onRoomOpen(const RoomOpenEvent& event)
{
    int item_id = ui->roomsList->findData(event.get<EventField::NAME>());
    if(item_id >= 0) {
        return;
    }
    ui->roomsList->addItem(
        QString("%1 (%2)").arg(event.get<EventField::NAME>()).arg(event.get<EventField::PLAYERS>()),
        event.get<EventField::NAME>()
    );
}

void RoomsDockWidget::onRoomPlayers(const RoomPlayersEvent &event)
{
    int item_id = ui->roomsList->findData(event.get<EventField::NAME>());
    if(item_id < 0) {
        return;
    }
    ui->roomsList->setItemText(
        item_id,
        QString("%1 (%2)").arg(event.get<EventField::NAME>()).arg(event.get<EventField::PLAYERS>())
    );
}

void RoomsDockWidget::onRoomClose(const RoomCloseEvent &event)
{
    int item_id = ui->roomsList->findData(event.get<EventField::NAME>());
    if(item_id < 0) {
        return;
    }
    ui->roomsList->removeItem(item_id);
}

void RoomsDockWidget::onSocketConnected()
{
    _socket.sendEvent(RoomFetchEvent());
}

void RoomsDockWidget::on_roomsList_currentIndexChanged(int index)
{
    const QString room = ui->roomsList->itemData(index).toString();
    RoomJoinRequest request;
    request.set<EventField::NAME>(room);
    QString test = request.get<EventField::NAME>();
    _socket.sendRequest(request);
}

void RoomsDockWidget::on_createButton_clicked()
{
    //TODO: create room, and select it
}

