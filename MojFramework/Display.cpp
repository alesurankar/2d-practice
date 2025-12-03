#include "Display.h"

Display::Display(Vei2 pos, int width, int height, Field::THEME theme, TYPE type_in, bool grid_in)
	:
	Field(pos, width, height, theme, ""),
	type(type_in),
	grid(grid_in)
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
	for (int i = GetPos().x; i < GetPos().x + GetWidth(); i+=8) {
		gfx.PutPixel(i, mid_y, grid_color);
	}
	for (int i = GetPos().y; i < GetPos().y + GetHeight(); i+=8) {
		gfx.PutPixel(mid_x, i, grid_color);
	}
}

void Display::SetGrid(bool effect)
{
	grid = effect;
}
