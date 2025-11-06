#include "Enemy.h"

Enemy::Enemy(Vei2 pos, Vec2 vel)
	:
	LivingEntity(RectI(pos, width, height), Colors::Red, vel),
	temp_rect(RectF((Vec2)pos, width, height))
{}

void Enemy::Update(float dt)
{
	Vec2 dir = { 0.0f, 0.0f };
	dir = GetVel() * dt;
	temp_rect.Translate(dir);
	rect = temp_rect;
}