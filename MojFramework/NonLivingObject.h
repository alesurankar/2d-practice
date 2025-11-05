#pragma once
#include "GameObject.h"

class NonLivingObject : public GameObject {
public:
	NonLivingObject(Vec2 pos, Color color, int width, int height);
private:
};