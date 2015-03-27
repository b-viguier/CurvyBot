#ifndef ABSTRACTEVENTCOMMAND
#define ABSTRACTEVENTCOMMAND

template<class Event>
class AbstractEventCommand
{
public:
    virtual void execute(const Event&) = 0;
};

#endif // ABSTRACTEVENTCOMMAND

