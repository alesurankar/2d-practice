#pragma once
#include "LivingEntity.h"

class Enemy : public LivingEntity {
public:
	Enemy(Vec2 pos_in, Vec2 vel);
	void Update(float dt);
public:
	void MakeRect();
private:
	Vec2 pos;
	static constexpr int width = 16;
	static constexpr int height = 16;
};