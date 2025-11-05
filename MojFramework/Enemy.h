#pragma once
#include "LivingEntity.h"

class Enemy : public LivingEntity {
public:
	Enemy(Location loc, float vx, float vy);
private:
	static constexpr int width = 16;
	static constexpr int height = 16;
};