#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"
#include "Ball.h"
#include "Keyboard.h"

class Pad {
public:
	Pad(Vei2 pos_in);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball) const;
	void DoWallCollision(const RectI& walls);
	void Update(const Keyboard& kbd, float dt);
	RectI GetRect() const;
private:
	Color color = Colors::White;
	static constexpr int width = 120;
	static constexpr int height = 30;
	Vei2 pos;
	Vec2 pos_temp;
};