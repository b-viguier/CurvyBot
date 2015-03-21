#ifndef ABSTRACTEVENT_H
#define ABSTRACTEVENT_H

#include <QJsonValue>

class QString;
class QJsonArray;

class AbstractEvent
{
public:
    AbstractEvent(const QJsonValue& data = QJsonValue());
    virtual ~AbstractEvent();

    QJsonArray message() const;
    QString toString() const;

    virtual QString id() const = 0;

protected:
    QJsonValue _data;

};

#endif // ABSTRACTEVENT_H
