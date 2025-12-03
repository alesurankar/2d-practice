#include "Oscilloscope.h"

Oscilloscope::Oscilloscope()
{
	//menu = std::make_unique<Menu>(Menu::MenuType::IN_APP);
	//screen = std::make_unique<Screen>();
	button.emplace_back(Vei2{ 20, 20 }, 60, 20, Field::THEME::LIGHT, "test");
	button.emplace_back(Vei2{ 20, 60 }, 60, 20, Field::THEME::DARK, "test2");
	button.emplace_back(Vei2{ 20, 100 }, 60, 20, Field::THEME::RED, "test");
	button.emplace_back(Vei2{ 20, 140 }, 60, 20, Field::THEME::GREEN, "test2");
	button.emplace_back(Vei2{ 20, 180 }, 60, 20, Field::THEME::BLUE, "test2");
	display.emplace_back(Vei2{ 200, 200 }, 60, 20, Field::THEME::LIGHT);
	display.emplace_back(Vei2{ 200, 240 }, 60, 20, Field::THEME::DARK);
	display.emplace_back(Vei2{ 200, 280 }, 60, 20, Field::THEME::RED);
	display.emplace_back(Vei2{ 200, 320 }, 60, 20, Field::THEME::GREEN);
	display.emplace_back(Vei2{ 200, 360 }, 60, 20, Field::THEME::BLUE);
}

void Oscilloscope::Update(const Mouse& mouse, float dt)
{
	for (auto& b : button)
	{
		b.Update(mouse, dt);
	}
	for (auto& d : display)
	{
		d.Update(mouse, dt);
	}
}

void Oscilloscope::Draw(Graphics& gfx) const
{
	for (auto& b : button)
	{
		b.Draw(gfx);
	}
	for (auto& d : display)
	{
		d.Draw(gfx);
	}
}