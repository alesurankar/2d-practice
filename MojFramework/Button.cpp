#include "Button.h"
#include <utility>

Button::Button(Vei2 pos, int width, int height, Field::THEME theme, std::string text)
	:
	Field(pos, width, height, theme, std::move(text)),
	len_x(8 * static_cast<int>(text.length())),
	len_y(14),
	middle_x(GetPos().x + (width/2) - (len_x/2)),
	middle_y(GetPos().y + (height/2) - (len_y/2)),
	onTop(false),
	pressed(false),
	released(false),
	effect(false)
{}

void Button::Update(const Mouse& mouse, float dt)
{
	Vei2 mousePos = mouse.GetPos();
	if (mousePos.y > GetPos().y && mousePos.y < (GetPos().y + GetHeight()) &&
		mousePos.x > GetPos().x && mousePos.x < (GetPos().x + GetWidth()))
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

void Button::Draw(Graphics& gfx) const
{
	if (onTop)
	{
		gfx.DrawRect(outside, border_color);
	}
	if (pressed)
	{
		gfx.DrawRect(inside, action_color);
	}
	else
	{
		gfx.DrawRect(inside, body_color);
	}
	smallFont.DrawText(text, {middle_x, middle_y}, content_color, gfx);
}



bool Button::GetEffect()
{
	return effect;
}

//std::string Button::GetButtonMessage()
//{
//	return text;
//}

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