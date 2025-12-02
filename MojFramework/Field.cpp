#include "Field.h"
#include <utility>

Field::Field(
	int x_in, int y_in, 
	int width_in, int height_in,
	std::string text_in,
	Color color_in, 
	Color border_color_in,
	Color text_color_in
)
	:
	x(x_in),
	y(y_in),
	width(width_in),
	height(height_in),
	text(std::move(text_in)),
	color(color_in),
	border_color(border_color_in),
	text_color(text_color_in),
	outside(x - 1, y - 1, x + width + 1, y + height + 1),
	inside(x, y, x + width, y + height),
	len_x(8 * static_cast<int>(text.length())),
	len_y(14),
	middle_x(x + (width / 2) - (len_x / 2)),
	middle_y(y + (height / 2) - (len_y / 2))
{
}

void Field::Update(const Keyboard& kbd, const Mouse& mouse, float dt)
{
	text = std::to_string(value);
}

void Field::Draw(Graphics& gfx) const
{
	gfx.DrawRect(outside, border_color);
	gfx.DrawRect(inside, color);
	smallFont.DrawText(text, { middle_x, middle_y }, text_color, gfx);
}