#ifndef ROOMJOINREPLY
#define ROOMJOINREPLY

namespace EventId
{
    constexpr const char ROOM_JOIN_REP[] = "room:join_reply";
}

typedef JsonObjectEvent<
    EventId::ROOM_JOIN_REP,
    JsonObjectField<EventField::SUCCESS, bool>
> RoomJoinReply;

#endif // ROOMJOINREPLY

