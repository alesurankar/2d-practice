#pragma once
#include "Graphics.h"
#include "Rect.h"
#include "Ball.h"

class Brick {
public:
	Brick(RectI rect_in, Color color_in = Colors::White);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);
	bool DestroyedCheck();
private:
	RectI rect;
	Color color;
	bool destroyed;
};