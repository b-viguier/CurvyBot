#ifndef JSONOBJECTEVENT
#define JSONOBJECTEVENT

#include "AbstractEvent.h"
#include "../Json/JsonObjectValue.h"

template<const char* Id, class... Fields>
class JsonObjectEvent : public AbstractEvent
{
public:
    static const char* ID;

    JsonObjectEvent(const QJsonValue& data)
        : AbstractEvent(data)
        , _jsonObject(data.toObject())
    {
        Q_ASSERT(data.isObject());
    }

    template<const char* Name>
    typename JsonObjectValue<Name, Fields...>::Type get() const
    {
        return JsonObjectValue<Name, Fields...>::get(_jsonObject);
    }

    QString id() const
    {
        return QString(Id);
    }

private:
    QJsonObject _jsonObject;
};

template<const char* Id, class... Fields>
const char* JsonObjectEvent<Id, Fields...>::ID = Id;


#endif // JSONOBJECTEVENT

