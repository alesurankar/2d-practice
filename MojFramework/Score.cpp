#include "Score.h"

Score::Score(Vec2 pos)
	:
	NonLivingObject(std::move(pos), Colors::White, width, height)
{}
