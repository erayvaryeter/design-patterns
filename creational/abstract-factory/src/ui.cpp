#include "ui/ui.h"

namespace abstractfactory {

void LOG(const std::string& message) {
	std::cout << message << std::endl;
}

void
WindowsButton::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Windows Button");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
WindowsButton::SetVisibility(bool visibility) {
	LOG("Setting visibility for Windows Button");
	m_visible = visibility;
}

void
WindowsButton::SetDescription(const std::string& description) {
	LOG("Setting description for Windows Button");
	m_description = description;
}

void
LinuxButton::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Linux Button");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
LinuxButton::SetVisibility(bool visibility) {
	LOG("Setting visibility for Linux Button");
	m_visible = visibility;
}

void
LinuxButton::SetDescription(const std::string& description) {
	LOG("Setting description for Linux Button");
	m_description = description;
}

void
MacButton::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Mac Button");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
MacButton::SetVisibility(bool visibility) {
	LOG("Setting visibility for Mac Button");
	m_visible = visibility;
}

void
MacButton::SetDescription(const std::string& description) {
	LOG("Setting description for Mac Button");
	m_description = description;
}

void
WindowsMenu::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Windows Menu");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
WindowsMenu::SetVisibility(bool visibility) {
	LOG("Setting visibility for Windows Menu");
	m_visible = visibility;
}

void
WindowsMenu::SetDescription(const std::string& description) {
	LOG("Setting description for Windows Menu");
	m_description = description;
}

void
LinuxMenu::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Linux Menu");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
LinuxMenu::SetVisibility(bool visibility) {
	LOG("Setting visibility for Linux Menu");
	m_visible = visibility;
}

void
LinuxMenu::SetDescription(const std::string& description) {
	LOG("Setting description for Linux Menu");
	m_description = description;
}

void
MacMenu::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Mac Menu");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
MacMenu::SetVisibility(bool visibility) {
	LOG("Setting visibility for Mac Menu");
	m_visible = visibility;
}

void
MacMenu::SetDescription(const std::string& description) {
	LOG("Setting description for Mac Menu");
	m_description = description;
}

void
WindowsComboBox::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Windows ComboBox");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
WindowsComboBox::SetVisibility(bool visibility) {
	LOG("Setting visibility for Windows ComboBox");
	m_visible = visibility;
}

void
WindowsComboBox::SetDescription(const std::string& description) {
	LOG("Setting description for Windows ComboBox");
	m_description = description;
}

void
LinuxComboBox::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Linux ComboBox");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
LinuxComboBox::SetVisibility(bool visibility) {
	LOG("Setting visibility for Linux ComboBox");
	m_visible = visibility;
}

void
LinuxComboBox::SetDescription(const std::string& description) {
	LOG("Setting description for Linux ComboBox");
	m_description = description;
}

void
MacComboBox::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Mac ComboBox");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
MacComboBox::SetVisibility(bool visibility) {
	LOG("Setting visibility for Mac ComboBox");
	m_visible = visibility;
}

void
MacComboBox::SetDescription(const std::string& description) {
	LOG("Setting description for Mac ComboBox");
	m_description = description;
}

void
WindowsScrollBar::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Windows ScrollBar");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
WindowsScrollBar::SetVisibility(bool visibility) {
	LOG("Setting visibility for Windows ScrollBar");
	m_visible = visibility;
}

void
WindowsScrollBar::SetDescription(const std::string& description) {
	LOG("Setting description for Windows ScrollBar");
	m_description = description;
}

void
LinuxScrollBar::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Linux ScrollBar");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
LinuxScrollBar::SetVisibility(bool visibility) {
	LOG("Setting visibility for Linux ScrollBar");
	m_visible = visibility;
}

void
LinuxScrollBar::SetDescription(const std::string& description) {
	LOG("Setting description for Linux ScrollBar");
	m_description = description;
}

void
MacScrollBar::SetPosition(int posX, int posY, int width, int height) {
	LOG("Setting position for Mac ScrollBar");
	m_position.posStartX = posX;
	m_position.posStartY = posY;
	m_position.width = width;
	m_position.height = height;
}

void
MacScrollBar::SetVisibility(bool visibility) {
	LOG("Setting visibility for Mac ScrollBar");
	m_visible = visibility;
}

void
MacScrollBar::SetDescription(const std::string& description) {
	LOG("Setting description for Mac ScrollBar");
	m_description = description;
}

std::shared_ptr<Widget>
WindowsFactory::CreateButton(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Windows Button");
	auto widget = std::make_shared<WindowsButton>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

std::shared_ptr<Widget>
WindowsFactory::CreateMenu(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Windows Menu");
	auto widget = std::make_shared<WindowsMenu>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

std::shared_ptr<Widget>
WindowsFactory::CreateComboBox(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Windows ComboBox");
	auto widget = std::make_shared<WindowsComboBox>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

std::shared_ptr<Widget>
WindowsFactory::CreateScrollBar(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Windows ScrollBar");
	auto widget = std::make_shared<WindowsScrollBar>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

std::shared_ptr<Widget>
LinuxFactory::CreateButton(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Linux Button");
	auto widget = std::make_shared<LinuxButton>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

std::shared_ptr<Widget>
LinuxFactory::CreateMenu(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Linux Menu");
	auto widget = std::make_shared<LinuxMenu>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

std::shared_ptr<Widget> 
LinuxFactory::CreateComboBox(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Linux ComboBox");
	auto widget = std::make_shared<LinuxComboBox>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

std::shared_ptr<Widget> 
LinuxFactory::CreateScrollBar(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Linux ScrollBar");
	auto widget = std::make_shared<LinuxScrollBar>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

std::shared_ptr<Widget> 
MacFactory::CreateButton(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Mac Button");
	auto widget = std::make_shared<MacButton>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

std::shared_ptr<Widget> 
MacFactory::CreateMenu(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Mac Menu");
	auto widget = std::make_shared<MacMenu>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

std::shared_ptr<Widget> 
MacFactory::CreateComboBox(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Mac ComboBox");
	auto widget = std::make_shared<MacComboBox>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

std::shared_ptr<Widget> 
MacFactory::CreateScrollBar(const WidgetPosition& pos, bool visible, const std::string& description) {
	LOG("Creating Mac ScrollBar");
	auto widget = std::make_shared<MacScrollBar>();
	widget->SetPosition(pos.posStartX, pos.posStartY, pos.width, pos.height);
	widget->SetVisibility(visible);
	widget->SetDescription(description);
	return widget;
}

}