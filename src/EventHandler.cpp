#include "EventHandler.h"
#include "EventManager.h"

EventHandler::EventHandler(EventType Type, std::function<void(const Event&)> Func)
    :uuid(sole::uuid0()),
    type(Type),
    func(Func)
{
    EventManager::getInstance().subscribe(*this);
}

bool EventHandler::operator==(const EventHandler& other)
{
    return (this->uuid == other.uuid);
}