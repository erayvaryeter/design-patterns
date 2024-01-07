#pragma once

#include "interface/ui-interface.h"

namespace abstractfactory {

class WindowsButton : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class LinuxButton : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class MacButton : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class WindowsMenu : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class LinuxMenu : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class MacMenu : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class WindowsComboBox : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class LinuxComboBox : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class MacComboBox : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class WindowsScrollBar : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class LinuxScrollBar : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class MacScrollBar : public Widget {
public:
	void SetPosition(int posX, int posY, int width, int height) override;
	void SetVisibility(bool visibility) override;
	void SetDescription(const std::string& description) override;
};

class WindowsFactory : public WidgetFactory {
public:
	std::shared_ptr<Widget> CreateButton(const WidgetPosition& pos, bool visible, const std::string& description) override;
	std::shared_ptr<Widget> CreateMenu(const WidgetPosition& pos, bool visible, const std::string& description) override;
	std::shared_ptr<Widget> CreateComboBox(const WidgetPosition& pos, bool visible, const std::string& description) override;
	std::shared_ptr<Widget> CreateScrollBar(const WidgetPosition& pos, bool visible, const std::string& description) override;
};

class LinuxFactory : public WidgetFactory {
public:
	std::shared_ptr<Widget> CreateButton(const WidgetPosition& pos, bool visible, const std::string& description) override;
	std::shared_ptr<Widget> CreateMenu(const WidgetPosition& pos, bool visible, const std::string& description) override;
	std::shared_ptr<Widget> CreateComboBox(const WidgetPosition& pos, bool visible, const std::string& description) override;
	std::shared_ptr<Widget> CreateScrollBar(const WidgetPosition& pos, bool visible, const std::string& description) override;
};

class MacFactory : public WidgetFactory {
public:
	std::shared_ptr<Widget> CreateButton(const WidgetPosition& pos, bool visible, const std::string& description) override;
	std::shared_ptr<Widget> CreateMenu(const WidgetPosition& pos, bool visible, const std::string& description) override;
	std::shared_ptr<Widget> CreateComboBox(const WidgetPosition& pos, bool visible, const std::string& description) override;
	std::shared_ptr<Widget> CreateScrollBar(const WidgetPosition& pos, bool visible, const std::string& description) override;
};

}