#include <ui/ui.h>
#include "client.h"

int main() {
	std::shared_ptr<abstractfactory::WidgetFactory> factory;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	abstractfactory::LOG("Creating Windows Client");
	factory = std::make_shared<abstractfactory::WindowsFactory>();
#elif __linux__
	abstractfactory::LOG("Creating Linux Client");
	factory = std::make_shared<abstractfactory::LinuxFactory>();
#elif TARGET_OS_MAC
	abstractfactory::LOG("Creating Mac Client");
	factory = std::make_shared<abstractfactory::MacFactory>();
#endif

	auto client = std::make_shared<Client>(factory);
	client->GenerateAllUiElements();

	return 0;
}