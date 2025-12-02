#include "Oscilloscope.h"

Oscilloscope::Oscilloscope()
{
	menu = std::make_unique<Menu>(Menu::MenuType::IN_APP);
	screen = std::make_unique<Screen>();
}

void Oscilloscope::Update(const Keyboard& kbd, const Mouse& mouse, float dt)
{
	menu->Update(kbd, mouse, dt);
	screen->Update(kbd, mouse, dt);
}

void Oscilloscope::Draw(Graphics& gfx) const
{
	menu->Draw(gfx);
	screen->Draw(gfx);
}