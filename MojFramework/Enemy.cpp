#include "Enemy.h"

Enemy::Enemy(int x, int y, int vx, int vy)
	:
	LivingEntity(x, y, Colors::Red, vx, vy, width, height)
{}
