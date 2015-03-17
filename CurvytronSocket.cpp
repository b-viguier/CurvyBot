#include "CurvytronSocket.h"
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonArray>

namespace {

const QString event_prefix = "evt/";

}
CurvytronSocket::CurvytronSocket(QWebSocket &socket)
    : QObject(&socket)
    , _socket(socket)
{
    connect(
        &_socket, &QWebSocket::textMessageReceived,
        this, &CurvytronSocket::onSocketMessageReceived
    );
}

CurvytronSocket::~CurvytronSocket()
{

}

void CurvytronSocket::sendMessage(const QString &type, const QJsonValue &data)
{
    QJsonArray json_message{event_prefix + type, data};
    json_message = {json_message};
    _socket.sendTextMessage(
        QJsonDocument(json_message).toJson()
    );

}

void CurvytronSocket::onSocketMessageReceived(const QString &message)
{
    auto json_doc = QJsonDocument::fromJson(message.toUtf8());
    QJsonValue data(message);
    QString type = "Error";
    if(json_doc.isArray()
        && json_doc.array().size()==1
        && json_doc.array().first().isArray()
    ) {
        auto json_array = json_doc.array().first().toArray();
        if(json_array.size() == 2
            && json_array.first().isString()
            && json_array.first().toString().startsWith(event_prefix)
        ) {
            type = json_array.first().toString().mid(event_prefix.size());
            data = json_array.last();
        }
    }
    emit messageReceived(type, data);
}

