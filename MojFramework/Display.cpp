#include "Display.h"

Display::Display(Vei2 pos, int width, int height, Field::THEME theme)
	:
	Field(pos, width, height, theme, "")
	
	
{
	//display = std::make_unique<Field>(100, 250, 200, 200);
	//signal = std::make_unique<Signal>(Signal::SignalType::SIN, 100.0f, 300.0f, 100.0f, 50.0f);
}

void Display::Update(const Mouse& mouse, float dt)
{
	//display->Update(mouse, dt);
	//signal->Update(dt);
}

void Display::Draw(Graphics& gfx) const
{
	gfx.DrawRect(outside, border_color);
	gfx.DrawRect(inside, body_color);

	//display->Draw(gfx);
	//signal->Draw(gfx);
}