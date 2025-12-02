#pragma once
#include "Graphics.h"
#include "Surface.h"
#include "Fonts.h"
#include "Button.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Vec2.h"
#include "Field.h"
#include <vector>
#include <string>

class Menu
{
public:
	enum class MenuType
	{
		MAIN,
		IN_APP
	};
	Menu(MenuType type_in);
	void Update(const Keyboard& kbd, const Mouse& mouse, float dt);
	void Draw(Graphics& gfx) const;
	std::string GetMenuMessage();
private:
	void TakeEffect(const std::string& effect);
private:
	std::string message;
	MenuType type;
	std::vector<Button> buttons;
	std::vector<Field> field;
};