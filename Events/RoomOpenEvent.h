#ifndef ROOMOPENEVENT_H
#define ROOMOPENEVENT_H

#include "AbstractEvent.h"

class RoomOpenEvent : public AbstractEvent
{
public:
    RoomOpenEvent(const QJsonValue& data);
    ~RoomOpenEvent();

    static const char *ID;

    QString id() const;

    QString name() const;

private:
    QString _name;
};

#endif // ROOMOPENEVENT_H
