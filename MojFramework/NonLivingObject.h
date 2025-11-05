#pragma once
#include "GameObject.h"

class NonLivingObject : public GameObject {
public:
	NonLivingObject(Vec2 pos_in, Color color = Colors::White);
private:
	static constexpr int width = 18;
	static constexpr int height = 18;
};