#include "NonLivingObject.h"

NonLivingObject::NonLivingObject(Vec2 pos, Color color, int width, int height)
	:
	GameObject(std::move(pos), std::move(color), width, height)
{}
