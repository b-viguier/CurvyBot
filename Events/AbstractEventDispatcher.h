#ifndef ABSTRACTEVENTDISPATCHER
#define ABSTRACTEVENTDISPATCHER

#include <memory>
class QJsonValue;
class QString;
class AbstractEvent;

class AbstractEventDispatcher
{
public:
    virtual void dispatch(const QJsonValue& json) = 0;
};

#endif // ABSTRACTEVENTDISPATCHER

