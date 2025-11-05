#include "Enemy.h"

Enemy::Enemy(Vec2 pos_in, Vec2 vel)
	:
	LivingEntity(RectI((Vei2)pos_in, width, height), Colors::Red, vel),
	pos(pos_in)
{}

void Enemy::Update(float dt)
{
	pos += GetVel() * dt;
	MakeRect();
}

void Enemy::MakeRect()
{
	rect = RectI((Vei2)pos, width, height);
}
