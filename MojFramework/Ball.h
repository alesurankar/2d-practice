#pragma once
#include "Graphics.h"
#include "Vec2.h"

class Ball {
public:
	Ball(Vei2 pos_in, Vec2 vel_in, Color color_in = Colors::White);
	void Draw(Graphics& gfx) const;
private:
	Vei2 pos;
	Vec2 vel;
	Color color;
	static constexpr int dim = 12;
};