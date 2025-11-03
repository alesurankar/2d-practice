#pragma once
#include "NonLivingObject.h"

class Score : public NonLivingObject {
public:
	Score(int x, int y);
private:
	static constexpr int width = 20;
	static constexpr int height = 20;
};