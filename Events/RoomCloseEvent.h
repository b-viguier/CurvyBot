#ifndef ROOMCLOSEEVENT_H
#define ROOMCLOSEEVENT_H

#include "AbstractEvent.h"

class QJsonValue;

class RoomCloseEvent : public AbstractEvent
{
public:
    static const char ID[];

    RoomCloseEvent(const QJsonValue&);
    ~RoomCloseEvent();

    QString id() const;
    QString name() const;

private:
    QString _name;
};

#endif // ROOMCLOSEEVENT_H
