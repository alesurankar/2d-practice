#include "Obj.h"

Obj::Obj(const RectI& rect_in, THEME theme_in)
	:
	outside(rect_in),
	theme(theme_in)
{
	inside = outside.GetShrinkedBy(1);
	SetTheme(theme);
}

RectI Obj::GetOutsideRect() const
{
	return outside;
}

RectI Obj::GetInsideRect() const
{
	return inside;
}

void Obj::SetTheme(THEME theme)
{
	switch (theme) {
	case THEME::LIGHT:
		body_color = Colors::White;
		content_color = Colors::Black;
		grid_color = Colors::DarkGray;
		action_color = Colors::LightGray;
		break;
	case THEME::LIGHTGRAY:
		body_color = Colors::LightGray;
		content_color = Colors::Black;
		grid_color = Colors::DarkGray;
		action_color = Colors::DarkGray;
		break;
	case THEME::DARK:
		body_color = Colors::Black;
		content_color = Colors::White;
		grid_color = Colors::LightGray;
		action_color = Colors::DarkGray;
		break;
	case THEME::RED:
		body_color = Colors::Red;
		content_color = Colors::Cyan;
		grid_color = Colors::Cyan2;
		action_color = Colors::DarkRed;
		break;
	case THEME::GREEN:
		body_color = Colors::Green;
		content_color = Colors::Magenta;
		grid_color = Colors::Magenta2;
		action_color = Colors::DarkGreen;
		break;
	case THEME::BLUE:
		body_color = Colors::Blue;
		content_color = Colors::Yellow;
		grid_color = Colors::Yellow2;
		action_color = Colors::DarkBlue;
		break;
	}
}