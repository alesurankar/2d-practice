#pragma once
#include "NonLivingObject.h"

class Brick : public NonLivingObject {
public:
	Brick(Vec2 pos);
private:
	static constexpr int dimension = 10;
};