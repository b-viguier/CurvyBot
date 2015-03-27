#include "JsonValue.h"
#include <QJsonValue>

template<>
QString JsonValue::get<QString>(const QJsonValue& value)
{
    Q_ASSERT(value.isString());
    return value.toString();
}

template<>
double JsonValue::get<double>(const QJsonValue& value)
{
    Q_ASSERT(value.isDouble());
    return value.toDouble();
}

template<>
int JsonValue::get<int>(const QJsonValue& value)
{
    Q_ASSERT(value.isDouble());
    return value.toInt();
}

template<>
bool JsonValue::get<bool>(const QJsonValue& value)
{
    Q_ASSERT(value.isBool());
    return value.toBool();
}
