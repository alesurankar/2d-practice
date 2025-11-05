#include "Enemy.h"

Enemy::Enemy(Vec2 pos, Vec2 vel)
	:
	LivingEntity(std::move(pos), Colors::Red, std::move(vel), width, height)
{}
