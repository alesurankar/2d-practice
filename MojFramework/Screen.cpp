#include "Screen.h"

Screen::Screen()
{
	signal = std::make_unique<Signal>(Signal::SignalType::SIN, 100.0f, 50.0f);
}

void Screen::Update(float dt)
{
	signal->Update(dt);
}

void Screen::Draw(Graphics& gfx) const
{
	signal->Draw(gfx);
}