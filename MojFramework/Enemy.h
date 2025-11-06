#pragma once
#include "LivingEntity.h"

class Enemy : public LivingEntity {
public:
	Enemy(Vei2 pos, Vec2 vel);
	void Update(float dt);
private:
	RectF temp_rect;
	static constexpr int width = 16;
	static constexpr int height = 16;
};