#include "Event.h"
#include "EventManager.h"

Event::Event(EventType type)
    :type(type)
{}

void Event::callEvent()
{
    EventManager::getInstance().callEvent(*this);
}