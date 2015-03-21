#include "CurvytronSocket.h"
#include "Events/RawEvent.h"
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

void CurvytronSocket::sendEvent(const AbstractEvent &event)
{
    _socket.sendTextMessage(
        QString(QJsonDocument(
            QJsonArray{QJsonArray{event_prefix + event.id(), event.data()}}
        ).toJson(QJsonDocument::Compact))
    );
}

void CurvytronSocket::onSocketMessageReceived(const QString &message)
{
    auto json_doc = QJsonDocument::fromJson(message.toUtf8());
    Q_ASSERT(json_doc.isArray());
    for(auto msg : json_doc.array()) {
        Q_ASSERT(msg.isArray());
        auto json_array = msg.toArray();
        Q_ASSERT(json_array.size() == 2
            && json_array.first().isString()
            && json_array.first().toString().startsWith(event_prefix)
        );
        const QString event_id = json_array.first().toString().mid(event_prefix.size());
        const QJsonValue event_data = json_array.last();

        auto dispatcher = _dispatchers.find(event_id.toStdString());
        if(dispatcher != _dispatchers.end()) {
            dispatcher->second->dispatch(event_data);
            //TODO: emit generic event
        } else {
            emit eventReceived(RawEvent(event_id, event_data));
        }
    }
}

