#ifndef CURVYTRONSOCKET_H
#define CURVYTRONSOCKET_H

#include "Events/EventDispatcher.h"
#include "Events/EventCommand.h"
#include <memory>
#include <unordered_map>
#include <QObject>
#include <QJsonValue>

class QString;
class QWebSocket;

class CurvytronSocket : public QObject
{
    Q_OBJECT
public:
    explicit CurvytronSocket(QWebSocket& socket);
    ~CurvytronSocket();

    QWebSocket &socket() const;

    template<class Event, class Listener>
    void registerListener(Listener& listener, typename EventCommand<Event,Listener>::MemberFunction function)
    {
        EventDispatcher<Event> *dispatcher = nullptr;
        auto& registered_dispatcher = _dispatchers[Event::ID];
        if( registered_dispatcher.get() == nullptr) {
            dispatcher = new EventDispatcher<Event>;
            registered_dispatcher = std::unique_ptr<AbstractEventDispatcher>(dispatcher);
        } else {
            dispatcher = static_cast<EventDispatcher<Event>*>(registered_dispatcher.get());
        }
        dispatcher->addCommand(new EventCommand<Event,Listener>(listener, function));
    }

public slots:
    void sendEvent(const AbstractEvent& event);

signals:
    void eventIgnored(const AbstractEvent& event);
    void eventDispatched(const AbstractEvent& event);
    void eventSent(const AbstractEvent& event);

private slots:
    void onSocketMessageReceived(const QString&);

private:
    QWebSocket& _socket;
    std::unordered_map<std::string, std::unique_ptr<AbstractEventDispatcher>> _dispatchers;
};

#endif // CURVYTRONSOCKET_H
