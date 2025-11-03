#pragma once
#include "Graphics.h"
#include "Location.h"

class Wall {
public:
	Wall(Graphics& gfx);
	void DrawBrick(Location& loc, Color c);
	int GetGridWidth() const;
	int GetGridHeight() const;
private:
	static constexpr int dimension = 20;
	static constexpr int width = 10;
	static constexpr int height = 10;
	Graphics& gfx;
};