#ifndef JSONVALUE_H
#define JSONVALUE_H

#include <QJsonValue>

struct JsonValue
{
    template<class T>
    static T get(const QJsonValue&);

    template<class T>
    static void set(QJsonValueRef jsonValue, const T& value)
    {
        jsonValue = QJsonValue(value);
    }
};

#endif // JSONVALUE_H
