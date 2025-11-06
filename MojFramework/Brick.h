#pragma once
#include "Graphics.h"
#include "Rect.h"

class Brick {
public:
	Brick(RectI rect_in, Color color_in = Colors::White);
	void Draw(Graphics& gfx) const;
private:
	RectI rect;
	Color color;
};