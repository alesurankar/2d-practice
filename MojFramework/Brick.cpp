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
	gfx.DrawRect(rect, color);
}

bool Brick::DoBallCollision(Ball& ball)
{
	if (rect.IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}
}

bool Brick::DestroyedCheck()
{
	return destroyed;
}
