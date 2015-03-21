#ifndef UNKNOWNEVENT_H
#define UNKNOWNEVENT_H

#include "AbstractEvent.h"
#include <QString>

class UnknownEvent : public AbstractEvent
{
public:
    UnknownEvent(const QString& id, const QJsonValue& data);
    ~UnknownEvent();

    QString id() const;

private:
    QString _id;
};

#endif // UNKNOWNEVENT_H
