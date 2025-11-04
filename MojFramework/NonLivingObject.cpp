#include "NonLivingObject.h"

NonLivingObject::NonLivingObject(Location loc, Color color, int width, int height)
	:
	GameObject(std::move(loc), std::move(color), width, height)
{}
