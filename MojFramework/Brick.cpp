#include "Brick.h"

Brick::Brick(Location loc)
	:
	NonLivingObject(std::move(loc), Colors::Gray, dimension, dimension)
{}