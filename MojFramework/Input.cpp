#include "Input.h"
#include <utility>

Input::Input(const Vei2& pos_in, int width, int height, std::string text)
	:
	Obj(RectI(pos_in, width, height), THEME::BLUE, std::move(text)),
	onTop(true),
	pressed(false),
	released(false),
	effect(false),
	toggle(true)
{}

void Input::Update(const Mouse& mouse, float dt)
{
	Vei2 mousePos = mouse.GetPos();
	if (mousePos.y > GetOutsideRect().GetLeftTop().y && mousePos.y < (GetOutsideRect().GetLeftTop().y + GetOutsideRect().GetHeight()) &&
		mousePos.x > GetOutsideRect().GetLeftTop().x && mousePos.x < (GetOutsideRect().GetLeftTop().x + GetOutsideRect().GetWidth()))
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

void Input::Draw(Graphics & gfx) const
{
	if (onTop)
	{
		gfx.DrawRect(GetOutsideRect(), body_color);
	}
	if (pressed)
	{
		gfx.DrawRect(GetInsideRect(), action_color);
	}
	else
	{
		gfx.DrawRect(GetInsideRect(), body_color);
	}
	smallFont.DrawText(GetText(), { mid_x, mid_y }, content_color, gfx);
}

void Input::Pressed()
{
	if (released)
	{
		pressed = true;
		released = false;
	}
}

void Input::Released()
{
	if (pressed)
	{
		effect = true;
		toggle = !toggle;
	}
	pressed = false;
	released = true;
}