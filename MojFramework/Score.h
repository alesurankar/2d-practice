#pragma once
#include "NonLivingObject.h"

class Score : public NonLivingObject {
public:
	Score(Vec2 pos);
private:
	void MakeRect();
private:
	RectI rect;
	Vec2 pos;
};