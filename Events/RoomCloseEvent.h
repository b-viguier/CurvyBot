#ifndef ROOMCLOSEEVENT_H
#define ROOMCLOSEEVENT_H

#include "JsonObjectEvent.h"

struct RoomCloseFields {
    static const char ID[];
    static const char NAME[];
};

typedef JsonObjectEvent<
    RoomCloseFields::ID,
    JsonObjectField<RoomCloseFields::NAME, QString>
> RoomCloseEvent;

#endif // ROOMCLOSEEVENT_H
