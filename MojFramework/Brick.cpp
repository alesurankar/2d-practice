#include "Brick.h"
#include <utility>

Brick::Brick(RectI rect_in, Color color_in)
	:
	rect(std::move(rect_in)),
	color(color_in)
{}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, color);
}