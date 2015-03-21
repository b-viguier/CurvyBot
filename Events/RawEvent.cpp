#include "RawEvent.h"

RawEvent::RawEvent(const QString& id, const QJsonValue& data)
    : AbstractEvent(data)
    , _id(id)
{

}

RawEvent::~RawEvent()
{

}

QString RawEvent::id() const
{
    return _id;
}
