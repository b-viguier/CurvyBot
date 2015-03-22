#include "RoomCloseEvent.h"

#include <QJsonValue>
#include <QJsonObject>


const char RoomCloseEvent::ID[] = "room:close";

RoomCloseEvent::RoomCloseEvent(const QJsonValue& data)
    :AbstractEvent(data)
{
    Q_ASSERT(data.isObject());
    const QJsonObject room = data.toObject();
    Q_ASSERT(room["name"].isString());
    _name = room["name"].toString();
}

RoomCloseEvent::~RoomCloseEvent()
{

}

QString RoomCloseEvent::id() const
{
    return ID;
}

QString RoomCloseEvent::name() const
{
    return _name;
}

