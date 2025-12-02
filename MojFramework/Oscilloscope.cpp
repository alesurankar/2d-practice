#include "Oscilloscope.h"

Oscilloscope::Oscilloscope()
{
	menu = std::make_unique<Menu>(Menu::MenuType::IN_APP);
	signal = std::make_unique<Signal>(Signal::SignalType::SIN, 100.0f, 50.0f);
}

void Oscilloscope::Update(const Mouse& mouse, float dt)
{
	signal->Update(dt);
	menu->Update(mouse);
}

void Oscilloscope::Draw(Graphics& gfx)
{
	signal->Draw(gfx);
	menu->Draw(gfx);
}