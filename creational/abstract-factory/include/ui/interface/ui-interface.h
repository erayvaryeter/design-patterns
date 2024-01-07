#pragma once

#include <iostream>
#include <string>
#include <memory>

namespace abstractfactory {

void LOG(const std::string& message);

struct WidgetPosition {
	int posStartX = 0;
	int posStartY = 0;
	int width = 0;
	int height = 0;
};

class Widget {
public:
	virtual void SetPosition(int posX, int posY, int width, int height) = 0;
	virtual void SetVisibility(bool visibility) = 0;
	virtual void SetDescription(const std::string& description) = 0;

protected:
	WidgetPosition m_position;
	bool m_visible;
	std::string m_description;
};

class WidgetFactory {
public:
	virtual std::shared_ptr<Widget> CreateButton(const WidgetPosition& pos, bool visible, const std::string& description) = 0;
	virtual std::shared_ptr<Widget> CreateMenu(const WidgetPosition& pos, bool visible, const std::string& description) = 0;
	virtual std::shared_ptr<Widget> CreateComboBox(const WidgetPosition& pos, bool visible, const std::string& description) = 0;
	virtual std::shared_ptr<Widget> CreateScrollBar(const WidgetPosition& pos, bool visible, const std::string& description) = 0;
};

}