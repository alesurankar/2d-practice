#include "Ball.h"

Ball::Ball(Vei2 pos_in, Vec2 vel_in, Color color_in)
	:
	pos(pos_in),
	vel(vel_in),
	color(color_in)
{}

void Ball::Draw(Graphics& gfx) const
{
	gfx.DrawRect(RectI(pos, dim, dim), color);
}
