#include "Field.h"
#include <utility>

Field::Field(
	Vei2 pos_in, int width_in, int height_in, THEME theme, std::string text_in)
	:
	pos(pos_in),
	width(width_in),
	height(height_in),
	text(std::move(text_in)),
	outside(pos.x - 2, pos.y - 1, pos.x + width + 1, pos.y + height + 1),
	inside(pos.x, pos.y, pos.x + width, pos.y + height),
	len_x(8 * int(text.length())),
	len_y(14),
	middle_x(pos.x + (width / 2) - (len_x / 2)),
	middle_y(pos.y + (height / 2) - (len_y / 2))
{
	SetTheme(theme);
}

void Field::SetTheme(THEME theme)
{
	switch (theme) {
	case THEME::LIGHT:
		body_color = Colors::White;
		border_color = Colors::LightGray;
		content_color = Colors::Black;
		action_color = Colors::LightGray;
		break;
	case THEME::DARK:
		body_color = Colors::Black;
		border_color = Colors::LightGray;
		content_color = Colors::White;
		action_color = Colors::DarkGray;
		break;
	case THEME::RED:
		body_color = Colors::Red;
		border_color = Colors::Red;
		content_color = Colors::Cyan;
		action_color = Colors::DarkRed;
		break;
	case THEME::GREEN:
		body_color = Colors::Green;
		border_color = Colors::Green;
		content_color = Colors::Magenta;
		action_color = Colors::DarkGreen;
		break;
	case THEME::BLUE:
		body_color = Colors::Blue;
		border_color = Colors::Yellow;
		content_color = Colors::Yellow;
		action_color = Colors::DarkBlue;
		break;
	}
}

const Vei2& Field::GetPos()
{
	return pos;
}

const int& Field::GetWidth()
{
	return width;
}

const int& Field::GetHeight()
{
	return height;
}