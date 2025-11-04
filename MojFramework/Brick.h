#pragma once
#include "NonLivingObject.h"

class Brick : public NonLivingObject {
public:
	Brick(Location loc);
private:
	static constexpr int dimension = 10;
};