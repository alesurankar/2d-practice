#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class GameObject {
public:
	enum class TYPE
	{
		PLAYER,
		BOT
	};
	GameObject(int x_in, int y_in, Color color_in);
	void Update();
	void Update(Keyboard& kbd);
	void Draw(Graphics& gfx) const;
	void CheckBorder();
private:
	int x;
	int y;
	int vx;
	int vy;
	int width = 12;
	int height = 12;
	Color color;
};