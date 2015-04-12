#ifndef ROOMJOINREQUEST
#define ROOMJOINREQUEST

#include "JsonObjectEvent.h"
#include "EventField.h"
#include "EventReplyMapper.h"
#include "RoomJoinReply.h"

namespace EventId
{
    constexpr const char ROOM_JOIN_REQ[] = "room:join";
}

typedef JsonObjectEvent<
    EventId::ROOM_JOIN_REQ,
    JsonObjectField<EventField::NAME, QString>
> RoomJoinRequest;

template<>
struct EventReplyMapper<RoomJoinRequest>
{
    typedef RoomJoinReply Reply;
};

#endif // ROOMJOINREQUEST

