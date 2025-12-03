#include "Button.h"
#include <utility>

Button::Button(Vei2 pos, int width, int height, Field::THEME theme, std::string text)
	:
	Field(pos, width, height, theme, std::move(text)),
	onTop(false),
	pressed(false),
	released(false),
	effect(false),
	toggle(true)
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
	smallFont.DrawText(GetText(), { mid_x, mid_y }, content_color, gfx);
}

bool Button::GetEffect()
{
	return effect;
}

bool Button::GetToggle()
{
	return toggle;
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
		toggle = !toggle;
	}
	pressed = false;
	released = true;
}