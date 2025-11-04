#include "Score.h"

Score::Score(Location loc)
	:
	NonLivingObject(std::move(loc), Colors::White, width, height)
{}
