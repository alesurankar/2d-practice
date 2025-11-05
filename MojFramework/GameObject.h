#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"
#include "Rect.h"
#include <utility>

class GameObject {
public:
	GameObject(RectI rect_in, Color color_in);
	void Draw(Graphics& gfx) const;
	bool CheckCollision(const GameObject& other) const;
	void ChangeColor(Color color_in);
protected:
	RectI rect;
	Color color;
};