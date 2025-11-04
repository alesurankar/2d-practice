#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Location.h"
#include <utility>

class GameObject {
public:
	GameObject(Location loc_in, Color color_in, int width_in, int height_in);
	void Draw(Graphics& gfx) const;
	bool CheckCollision(const GameObject& other);
	void ChangeColor(Color color_in);
	Location GetLocation() const;
	int GetWidth() const;
	int GetHeight() const;
protected:
	Location loc;
	Color color;
	int width;
	int height;
};