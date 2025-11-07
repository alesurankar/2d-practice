#include "Brick.h"
#include <utility>

Brick::Brick(RectI rect_in, Color color_in)
	:
	rect(std::move(rect_in)),
	color(color_in),
	destroyed(false)
{}

void Brick::Draw(Graphics& gfx) const
{
	RectI inner = RectI{ rect.left + 2, rect.top + 2, rect.right - 2, rect.bottom - 2 };
	gfx.DrawRect(rect, Colors::DarkGray);
	gfx.DrawRect(inner, color);
}

bool Brick::DoBallCollision(Ball& ball)
{
	if (rect.IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}
	return false;
}

bool Brick::DestroyedCheck()
{
	return destroyed;
}
