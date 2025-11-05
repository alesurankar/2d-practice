#include "NonLivingObject.h"

NonLivingObject::NonLivingObject(Vec2 pos_in, Color color)
	:
	GameObject(RectI((Vei2)pos_in, width, height), std::move(color))
{}
