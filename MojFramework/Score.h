#pragma once
#include "NonLivingObject.h"

class Score : public NonLivingObject {
public:
	Score(int x, int y);
private:
	static constexpr int width = 14;
	static constexpr int height = 14;
};