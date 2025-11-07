#include "Ball.h"

Ball::Ball(Vei2 pos_in, Vec2 vel_in, Color color_in)
	:
	pos(pos_in),
	vel(vel_in),
	color(color_in),
	pos_temp(pos)
{}

void Ball::Draw(Graphics& gfx) const
{
	gfx.DrawRect(RectI(pos, dim, dim), color);
}

void Ball::Update(float dt)
{
	pos_temp += vel * dt;
	pos = pos_temp;
}

bool Ball::DoWallCollision(const RectI& walls)
{
	bool collided = false;
	const RectI rect = GetRect();
	if (rect.left < walls.left)
	{
		pos_temp.x = 1;
		ReboundX();
		collided = true;
	}
	if (rect.right >= walls.right)
	{
		pos_temp.x = float(Graphics::ScreenWidth - dim - 1);
		ReboundX();
		collided = true;
	}
	if (rect.top < walls.top)
	{
		pos_temp.y = 1;
		ReboundY();
		collided = true;
	}
	if (rect.bottom >= walls.bottom) 
	{
		pos_temp.y = float(Graphics::ScreenHeight - dim -1);
		ReboundY();
		collided = true;
	}
	pos = pos_temp;
	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectI Ball::GetRect() const
{
	return RectI(pos, dim, dim);
}

Vec2 Ball::GetVelocity() const
{
	return vel;
}
