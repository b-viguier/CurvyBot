#include "RoomPlayersEvent.h"
#include <QJsonObject>

const char* RoomPlayersEvent::ID = "room:players";

RoomPlayersEvent::RoomPlayersEvent(const QJsonValue& data)
    :AbstractEvent(data)
{
    Q_ASSERT(data.isObject());
    const QJsonObject room = data.toObject();
    Q_ASSERT(room["name"].isString());
    _name = room["name"].toString();
    Q_ASSERT(room["players"].isDouble());
    _players = room["players"].toInt();
}

RoomPlayersEvent::~RoomPlayersEvent()
{

}

QString RoomPlayersEvent::id() const
{
    return ID;
}

QString RoomPlayersEvent::name() const
{
    return _name;
}

int RoomPlayersEvent::players() const
{
    return _players;
}
