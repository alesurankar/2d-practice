#pragma once
#include "GameObject.h"

class NonLivingObject : public GameObject {
public:
	NonLivingObject(Vec2 pos_in, Color color = Colors::White);
private:
	void MakeRect();
private:
	Vec2 pos;
	RectI rect;
	static constexpr int width = 20;
	static constexpr int height = 20;
};