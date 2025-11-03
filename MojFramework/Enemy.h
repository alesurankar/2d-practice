#pragma once
#include "LivingEntity.h"

class Enemy : public LivingEntity {
public:
	Enemy(int x, int y, int vx, int vy);
private:
	static constexpr int width = 16;
	static constexpr int height = 16;
};