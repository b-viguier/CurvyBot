#include "RoomOpenEvent.h"
#include <QJsonObject>

const char* RoomOpenEvent::ID = "room:open";

RoomOpenEvent::RoomOpenEvent(const QJsonValue& data)
    :AbstractEvent(data)
{
    Q_ASSERT(data.isObject());
    const QJsonObject room = data.toObject();
    Q_ASSERT(room["name"].isString());
    _name = room["name"].toString();
}

RoomOpenEvent::~RoomOpenEvent()
{

}

QString RoomOpenEvent::id() const
{
    return ID;
}

QString RoomOpenEvent::name() const
{
    return _name;
}

