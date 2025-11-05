#pragma once
#include "GameObject.h"

class NonLivingObject : public GameObject {
public:
	NonLivingObject(Vec2 pos_in, Color color = Colors::White);
private:
	void MakeRect();
private:
	RectI rect;
	Vec2 pos;
	static constexpr int width = 20;
	static constexpr int height = 20;
};