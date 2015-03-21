#ifndef EVENTCOMMAND
#define EVENTCOMMAND

#include "AbstractEventCommand.h"

template<class Event, class Listener>
class EventCommand : public AbstractEventCommand<Event>
{
public:
    typedef void (Listener::*MemberFunction)(const Event&);

    EventCommand(Listener& listener, MemberFunction function)
        : _listener(listener)
        , _function(function)
    {
    }

    void execute(const Event &event)
    {
        (_listener.*_function)(event);
    }

private:
    Listener& _listener;
    MemberFunction _function;
};


#endif // EVENTCOMMAND

