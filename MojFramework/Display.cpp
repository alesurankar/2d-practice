#include "Display.h"

Display::Display(Vei2 pos, int width, int height, Field::THEME theme, TYPE type_in)
	:
	Field(pos, width, height, theme, ""),
	type(type_in)
{
}

void Display::Update(const Mouse& mouse, float dt)
{
}

void Display::Draw(Graphics& gfx) const
{
    gfx.DrawRect(outside, border_color);
    gfx.DrawRect(inside, body_color);
	if (grid) {
		DrawGrid(gfx);
	}
}

void Display::DrawGrid(Graphics& gfx) const
{
	gfx.DrawLine(Vec2(float(GetPos().x), float(mid_y)), Vec2(float(GetPos().x + GetWidth()), (float)mid_y), content_color);
	gfx.DrawLine(Vec2(float(mid_x), (float)GetPos().y), Vec2((float)mid_x, float(GetPos().y + GetHeight())), content_color);
}

void Display::SetGrid(bool effect)
{
	grid = effect;
}
