#pragma once
#include "LivingEntity.h"

class Player : public LivingEntity {
public:
	Player(Location loc);
private:
	static constexpr int width = 18;
	static constexpr int height = 18;
};