#ifndef ROOMOPENEVENT_H
#define ROOMOPENEVENT_H

#include "RoomPlayersEvent.h"

class RoomOpenEvent : public RoomPlayersEvent
{
public:
    RoomOpenEvent(const QJsonValue& data);
    ~RoomOpenEvent();

    static const char *ID;

    QString id() const;
    bool game() const;

private:
    bool _game;
};

#endif // ROOMOPENEVENT_H
