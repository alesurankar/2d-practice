#include "Enemy.h"

Enemy::Enemy(Vec2 pos_in, Vec2 vel_in)
	:
	pos(pos_in),
	vel(vel_in),
	rect((Vei2)pos, width, height),
	LivingEntity(rect, Colors::Red)
{}

void Enemy::Update(float dt)
{
	pos += vel * dt;
}

void Enemy::MakeRect()
{
	rect = RectI((Vei2)pos, width, height);
}
