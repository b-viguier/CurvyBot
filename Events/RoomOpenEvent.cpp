#include "RoomOpenEvent.h"
#include <QJsonObject>

const char* RoomOpenEvent::ID = "room:open";

RoomOpenEvent::RoomOpenEvent(const QJsonValue& data)
    :RoomPlayersEvent(data)
{
    Q_ASSERT(data.isObject());
    const QJsonObject room = data.toObject();
    Q_ASSERT(room["players"].isDouble());
    _game = room["players"].toInt();
}

RoomOpenEvent::~RoomOpenEvent()
{

}

QString RoomOpenEvent::id() const
{
    return ID;
}

bool RoomOpenEvent::game() const
{
    return _game;
}

