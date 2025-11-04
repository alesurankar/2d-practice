#include "Enemy.h"

Enemy::Enemy(Location loc, int vx, int vy)
	:
	LivingEntity(std::move(loc), Colors::Red, vx, vy, width, height)
{}
