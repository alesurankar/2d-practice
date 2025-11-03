#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class GameObject {
public:
	GameObject(int x_in, int y_in, Color color_in, int width_in, int height_in);
	void Draw(Graphics& gfx) const;
	bool CheckCollision(const GameObject& other);
	void ChangeColor(Color color_in);
	int GetX();
	int GetY();
protected:
	int x;
	int y;
	Color color;
	int width;
	int height;
};