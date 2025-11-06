#pragma once
#include "GameObject.h"

class NonLivingObject : public GameObject {
public:
	NonLivingObject(Vei2 pos, Color color = Colors::White);
private:
	static constexpr int width = 18;
	static constexpr int height = 18;
};