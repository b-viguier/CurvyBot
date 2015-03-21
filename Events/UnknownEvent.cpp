#include "UnknownEvent.h"

UnknownEvent::UnknownEvent(const QString& id, const QJsonValue& data)
    : AbstractEvent(data)
    , _id(id)
{

}

UnknownEvent::~UnknownEvent()
{

}

QString UnknownEvent::id() const
{
    return _id;
}
