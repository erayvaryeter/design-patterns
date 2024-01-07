#include "client.h"

Client::Client(std::shared_ptr<abstractfactory::WidgetFactory> factory)
	: m_factory(factory) 
{}

void 
Client::GenerateAllUiElements() {
	abstractfactory::WidgetPosition pos;
	pos.posStartX = 10;
	pos.posStartY = 20;
	pos.width = 10;
	pos.height = 10;
	bool visible = true;
	std::string description = "description";

	m_factory->CreateButton(pos, visible, description);
	m_factory->CreateMenu(pos, visible, description);
	m_factory->CreateComboBox(pos, visible, description);
	m_factory->CreateScrollBar(pos, visible, description);
}