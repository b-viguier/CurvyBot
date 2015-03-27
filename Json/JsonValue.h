#ifndef JSONVALUE_H
#define JSONVALUE_H

class QJsonValue;
class QString;

struct JsonValue
{
    template<class T>
    static T get(const QJsonValue&);
};

#endif // JSONVALUE_H
