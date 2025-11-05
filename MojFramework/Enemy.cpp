#include "Enemy.h"

Enemy::Enemy(Location loc, float vx, float vy)
	:
	LivingEntity(std::move(loc), Colors::Red, vx, vy, width, height)
{}
