#ifndef ROOMPLAYERSEVENT_H
#define ROOMPLAYERSEVENT_H

#include "AbstractEvent.h"

class QJsonValue;

class RoomPlayersEvent : public AbstractEvent
{
public:
    RoomPlayersEvent(const QJsonValue&);
    ~RoomPlayersEvent();

    static const char *ID;

    QString id() const;

    QString name() const;
    int players() const;

private:
    QString _name;
    int _players;
};

#endif // ROOMPLAYERSEVENT_H
