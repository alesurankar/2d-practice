#pragma once
#include "LivingEntity.h"

class Enemy : public LivingEntity {
public:
	Enemy(Vec2 pos_in, Vec2 vel_in);
	void Update(float dt);
private:
	void MakeRect();
private:
	Vec2 pos;
	Vec2 vel;
	RectI rect;
	static constexpr int width = 16;
	static constexpr int height = 16;
};