#ifndef JSONOBJECTVALUE
#define JSONOBJECTVALUE

#include "JsonValue.h"
#include "JsonObjectField.h"
#include <QJsonObject>

template<const char* Name, class... Fields> struct JsonObjectValue;

template<const char* Name, const char* HeadName, typename HeadType, typename... Tail>
struct JsonObjectValue<Name, JsonObjectField<HeadName, HeadType>, Tail ... >
{
    typedef JsonObjectValue<Name, Tail...> NextElement;
    typedef typename NextElement::Type Type;

    static Type get(const QJsonObject& object) {
        return NextElement::get(object);
    }

    static void set(QJsonObject& object, const Type& value) {
        return NextElement::set(object, value);
    }

};

template<const char* Name, typename HeadType, typename... Tail>
struct JsonObjectValue<Name, JsonObjectField<Name, HeadType>, Tail...>
{
    typedef HeadType Type;

    static Type get(const QJsonObject& object) {
        return JsonValue::get<HeadType>(object.value(QString(Name)));
    }

    static void set(QJsonObject& object, const Type& value) {
        return JsonValue::set(object[Name], value);
    }
};


#endif // JSONOBJECTVALUE

