#include "MausEvent.h"
#include "EventManager.h"
#include "ButtonPressEvent.h"
#include "EventHandler.h"

#include <iostream>


#define FUNCTION_OneParam( funkce ) std::bind( (funkce), (this), std::placeholders::_1)

class Gui 
{
public:
    Gui() 
    {
        //EventHandler MausEventHandler(EventType::MausEvent, FUNCTION_OneParam(&Gui::OnMausEvent));
        EventHandler MausEventHandler(EventType::MausEvent, std::bind(&Gui::OnButtonPressEvent, this, std::placeholders::_1));
        EventManager::getInstance().deSubscribe(MausEventHandler);

        EventHandler MausEventHandler2(EventType::MausEvent, FUNCTION_OneParam(&Gui::OnMausEvent2));

        EventHandler ButtonPressEventHandler(EventType::ButtonEvent, FUNCTION_OneParam(&Gui::OnButtonPressEvent));
    }

    void OnMausEvent(const Event& event)
    {
        const MausEvent& mausEvent = static_cast<const MausEvent&>(event);

        std::cout << "Maus Event! cords:" << mausEvent.x << ":" << mausEvent.y << "\n";
    }

    void OnMausEvent2(const Event& event)
    {
        const MausEvent& mausEvent = static_cast<const MausEvent&>(event);

        std::cout << "Maus Event2! cords:" << mausEvent.x << ":" << mausEvent.y << "\n";
    }

    void OnButtonPressEvent(const Event& event)
    {
        const ButtonPressEvent& buttonPress = static_cast<const ButtonPressEvent&>(event);

        std::cout << "ButtonPress Event! Button Nr: " << buttonPress.ButtonId << " pressed...\n";
    }
};

int main()
{
    Gui gui;
    gui.RegForEvent();

    MausEvent MEvent(23, 12);
    MausEvent MEvent2(26, 92);
    ButtonPressEvent BEvent(64);
}
