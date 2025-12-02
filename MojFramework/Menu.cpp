#include "Menu.h"
#include "ImageEffect.h"

Menu::Menu(MenuType type_in)
	:
	type(type_in)
{
	buttons.emplace_back(10, 10, 60, 40, "TEST");
}

void Menu::Draw(Graphics& gfx) const
{
	for (auto& b : buttons)
	{
		b.Draw(gfx);
	}
}

void Menu::Update(const Mouse& mouse)
{
	for (auto& b : buttons)
	{
		b.Update(mouse);
		if (b.GetEffect())
		{
			TakeEffect(b.GetButtonMessage());
		}
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
