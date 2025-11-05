#include "Brick.h"

Brick::Brick(Vec2 pos)
	:
	NonLivingObject(std::move(pos), Colors::Gray, dimension, dimension)
{}