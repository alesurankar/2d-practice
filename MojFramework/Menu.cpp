#include "Menu.h"
#include "ImageEffect.h"

Menu::Menu(MenuType type_in)
	:
	type(type_in)
{
	buttons.emplace_back(10, 10, 60, 40, "TEST", Colors::Red, Colors::Green, Colors::Gray, Colors::Black);
	buttons.emplace_back(100, 100, 60, 40, "TEST");
	field.emplace_back(80, 10, 60, 40, "0");
}

void Menu::Update(const Keyboard& kbd, const Mouse& mouse, float dt)
{
	for (auto& b : buttons)
	{
		b.Update(mouse);
		if (b.GetEffect())
		{
			TakeEffect(b.GetButtonMessage());
		}
	}
	for (auto& f : field)
	{
		f.Update(kbd, mouse, dt);
	}
}

void Menu::Draw(Graphics& gfx) const
{
	for (auto& b : buttons)
	{
		b.Draw(gfx);
	}
	for (auto& f : field)
	{
		f.Draw(gfx);
	}
}

std::string Menu::GetMenuMessage()
{
	return message;
}

void Menu::TakeEffect(const std::string& effect)
{
	message = effect;
}
