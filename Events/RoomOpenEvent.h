#ifndef ROOMOPENEVENT_H
#define ROOMOPENEVENT_H

#include "JsonObjectEvent.h"
#include "EventField.h"

namespace EventId
{
    constexpr const char ROOM_OPEN[] = "room:open";
}

typedef JsonObjectEvent<
    EventId::ROOM_OPEN,
    JsonObjectField<EventField::NAME, QString>,
    JsonObjectField<EventField::PLAYERS, int>,
    JsonObjectField<EventField::GAME, bool>
> RoomOpenEvent;

#endif // ROOMOPENEVENT_H
