#include "NonLivingObject.h"

NonLivingObject::NonLivingObject(Vec2 pos_in, Color color)
	:
	pos(pos_in),
	rect(Vei2(pos), width, height),
	GameObject(rect, std::move(color))
{}
