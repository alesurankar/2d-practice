#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"
#include <utility>

class GameObject {
public:
	GameObject(Vec2 pos_in, Color color_in, int width_in, int height_in);
	void Draw(Graphics& gfx) const;
	bool CheckCollision(const GameObject& other);
	void ChangeColor(Color color_in);
	Vec2 GetPosition() const;
	int GetWidth() const;
	int GetHeight() const;
protected:
	Vec2 pos;
	Color color;
	int width;
	int height;
};