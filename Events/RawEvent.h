#ifndef RAWEVENT_H
#define RAWEVENT_H

#include "AbstractEvent.h"
#include <QString>

class RawEvent : public AbstractEvent
{
public:
    RawEvent(const QString& id, const QJsonValue& data);
    ~RawEvent();

    QString id() const;

private:
    QString _id;
};

#endif // RAWEVENT_H
