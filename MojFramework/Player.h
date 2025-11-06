#pragma once
#include "LivingEntity.h"

class Player : public LivingEntity {
public:
	Player(Vei2 pos);
	void Update(Keyboard& kbd, float dt);
private:
	RectF temp_rect;
	static constexpr int width = 18;
	static constexpr int height = 18;
};