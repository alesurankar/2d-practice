#include "NonLivingObject.h"

NonLivingObject::NonLivingObject(Vei2 pos, Color color)
	:
	GameObject(RectI(pos, width, height), std::move(color))
{}
