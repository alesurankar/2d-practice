#pragma once
#include "GameObject.h"

class NonLivingObject : public GameObject {
public:
	NonLivingObject(Location loc, Color color, int width, int height);
private:
};