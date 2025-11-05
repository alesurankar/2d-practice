#pragma once
#include "LivingEntity.h"

class Enemy : public LivingEntity {
public:
	Enemy(Vec2 pos, Vec2 vel);
private:
	static constexpr int width = 16;
	static constexpr int height = 16;
};