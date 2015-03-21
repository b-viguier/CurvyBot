#include "AbstractEvent.h"

#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

AbstractEvent::AbstractEvent(const QJsonValue &data)
    :_data(data)
{

}

AbstractEvent::~AbstractEvent()
{

}

QJsonArray AbstractEvent::message() const
{
    return QJsonArray{
        id(),
        _data,
    };
}

QString AbstractEvent::toString() const
{
    QString data("Unmatched type");
    switch(_data.type()) {
        case QJsonValue::Array:
            data = QJsonDocument(_data.toArray()).toJson(QJsonDocument::Compact);
            break;
        case QJsonValue::Object:
            data = QJsonDocument(_data.toObject()).toJson(QJsonDocument::Compact);
            break;
        case QJsonValue::String:
            data = QString("\"") + _data.toString() + "\"";
            break;
        case QJsonValue::Bool:
            data = _data.toBool() ? "true" : "false";
            break;
        case QJsonValue::Null:
            data = "null";
            break;
        case QJsonValue::Double:
            data = QString::number(_data.toDouble());
            break;
        case QJsonValue::Undefined:
            data = "undefined";
            break;
    }
    return QString("[%1] %2").arg(id()).arg(data);
}

