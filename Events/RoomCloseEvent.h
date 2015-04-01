#ifndef ROOMCLOSEEVENT_H
#define ROOMCLOSEEVENT_H

#include "JsonObjectEvent.h"
#include "EventField.h"

namespace EventId
{
    constexpr const char ROOM_CLOSE[] = "room:close";
}

typedef JsonObjectEvent<
    EventId::ROOM_CLOSE,
    JsonObjectField<EventField::NAME, QString>
> RoomCloseEvent;

#endif // ROOMCLOSEEVENT_H
