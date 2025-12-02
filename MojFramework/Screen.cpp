#include "Screen.h"

Screen::Screen()
{
	display = std::make_unique<Field>(100, 250, 200, 200);
	signal = std::make_unique<Signal>(Signal::SignalType::SIN, 100.0f, 300.0f, 100.0f, 50.0f);
}

void Screen::Update(const Keyboard& kbd, const Mouse& mouse, float dt)
{
	display->Update(kbd, mouse, dt);
	signal->Update(dt);
}

void Screen::Draw(Graphics& gfx) const
{
	display->Draw(gfx);
	signal->Draw(gfx);
}