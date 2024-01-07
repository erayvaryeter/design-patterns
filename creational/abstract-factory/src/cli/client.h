#include <ui/interface/ui-interface.h>

class Client {

public:
    Client(std::shared_ptr<abstractfactory::WidgetFactory> factory);
    void GenerateAllUiElements();

private:
    std::shared_ptr<abstractfactory::WidgetFactory> m_factory;
};