#pragma once
#include "Graphics.h"
#include "Vec2.h"

class Ball {
public:
	Ball(Vei2 pos_in, Vec2 vel_in, Color color_in = Colors::White);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	bool DoWallCollision(const RectI& walls);
	void ReboundX();
	void ReboundY();
	RectI GetRect();
private:
	static constexpr int dim = 12;
	Vei2 pos;
	Vec2 vel;
	Color color;
	Vec2 pos_temp;
};