#include "Button.h"
#include <utility>

Button::Button(
	int x_in, int y_in, 
	int width_in, int height_in, 
	std::string text_in, 
	Color btn_color_in,
	Color hover_color_in,
	Color active_color_in,
	Color text_color_in
)
	:
	x(x_in),
	y(y_in),
	width(width_in),
	height(height_in),
	text(std::move(text_in)),
	btn_color(btn_color_in),
	hover_color(hover_color_in),
	active_color(active_color_in),
	text_color(text_color_in),
	outside(x - 1, y - 1, x + width + 1, y + height + 1),
	inside(x, y, x + width, y + height),
	len_x(8 * static_cast<int>(text.length())),
	len_y(14),
	middle_x(x + (width/2) - (len_x/2)),
	middle_y(y + (height/2) - (len_y/2)),
	onTop(false),
	pressed(false),
	released(false),
	effect(false)
{}

void Button::Draw(Graphics& gfx) const
{
	if (onTop)
	{
		gfx.DrawRect(outside, hover_color);
	}
	if (pressed)
	{
		gfx.DrawRect(inside, active_color);
	}
	else
	{
		gfx.DrawRect(inside, btn_color);
	}
	smallFont.DrawText(text, {middle_x, middle_y}, text_color, gfx);
}

void Button::Update(const Mouse& mouse)
{
	Vei2 mousePos = mouse.GetPos();
	if (mousePos.y > y && mousePos.y < (y + height) &&
		mousePos.x > x && mousePos.x < (x + width))
	{
		onTop = true;
	}
	else
	{
		onTop = false;
		pressed = false;
	}
	if (onTop)
	{
		if (mouse.LeftIsPressed())
		{
			Pressed();
		}
		else
		{
			Released();
		}
	}
}

bool Button::GetEffect()
{
	return effect;
}

std::string Button::GetButtonMessage()
{
	return text;
}

void Button::Pressed()
{
	if (released)
	{
		pressed = true;
		released = false;
	}
}

void Button::Released()
{
	if (pressed)
	{
		effect = true;
	}
	pressed = false;
	released = true;
}