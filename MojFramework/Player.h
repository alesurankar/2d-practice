#pragma once
#include "LivingEntity.h"

class Player : public LivingEntity {
public:
	Player(Vec2 pos_in);
	void Update(Keyboard& kbd, float dt);
private:
	void MakeRect();
private:
	Vec2 pos;
	RectI rect;
	static constexpr int width = 18;
	static constexpr int height = 18;
};