#ifndef ROOMJOINREQUEST
#define ROOMJOINREQUEST

#include "JsonObjectEvent.h"
#include "EventField.h"

namespace EventId
{
    constexpr const char ROOM_JOIN_REQ[] = "room:join";
}

typedef JsonObjectEvent<
    EventId::ROOM_JOIN_REQ,
    JsonObjectField<EventField::NAME, QString>
> RoomJoinRequest;

#endif // ROOMJOINREQUEST

