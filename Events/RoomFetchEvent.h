#ifndef ROOMFETCHEVENT_H
#define ROOMFETCHEVENT_H

#include "AbstractEvent.h"

class RoomFetchEvent : public AbstractEvent
{
public:
    RoomFetchEvent();
    ~RoomFetchEvent();

    QString id() const;
};

#endif // ROOMFETCHEVENT_H
