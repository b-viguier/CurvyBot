#ifndef ROOMPLAYERSEVENT_H
#define ROOMPLAYERSEVENT_H

#include "JsonObjectEvent.h"
#include "EventField.h"

namespace EventId
{
    constexpr const char ROOM_PLAYERS[] = "room:players";
}

typedef JsonObjectEvent<
    EventId::ROOM_PLAYERS,
    JsonObjectField<EventField::NAME, QString>,
    JsonObjectField<EventField::PLAYERS, int>
> RoomPlayersEvent;

#endif // ROOMPLAYERSEVENT_H
