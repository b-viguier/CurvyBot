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

QWebSocket &CurvytronSocket::socket() const
{
    return _socket;
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
    if(!json_doc.isArray()) {
        emit messageReceived("GlobalError", message);
    }
    for(auto msg : json_doc.array()) {
        if( ! msg.isArray()) {
            emit messageReceived("EventError", msg);
            break;
        }
        auto json_array = msg.toArray();
        if(json_array.size() != 2
            || !json_array.first().isString()
            || !json_array.first().toString().startsWith(event_prefix)
        ) {
            emit messageReceived("TypeError", json_array);
            break;
        }
        emit messageReceived(
            json_array.first().toString().mid(event_prefix.size()),
            json_array.last()
        );
    }
}

