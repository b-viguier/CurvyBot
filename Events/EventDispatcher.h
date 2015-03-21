#ifndef EVENTDISPATCHER
#define EVENTDISPATCHER

#include <memory>
#include <vector>
#include "AbstractEventDispatcher.h"
#include "AbstractEventCommand.h"

class QJsonValue;

template<class Event>
class EventDispatcher : public AbstractEventDispatcher
{
public:
    typedef AbstractEventCommand<Event> Command;

    void dispatch(const QJsonValue &json)
    {
        const Event event(json);
        for(auto& cmd :_commands) {
            cmd->execute(event);
        }
    }

    void addCommand(Command* command)
    {
        _commands.push_back(std::unique_ptr<Command>(command));
    }

private:
    std::vector<std::unique_ptr<Command>> _commands;
};

#endif // EVENTDISPATCHER

