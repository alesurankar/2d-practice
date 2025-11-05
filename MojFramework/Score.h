#pragma once
#include "NonLivingObject.h"

class Score : public NonLivingObject {
public:
	Score(Vec2 pos);
private:
	static constexpr int width = 20;
	static constexpr int height = 20;
};