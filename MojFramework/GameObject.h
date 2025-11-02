#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class GameObject {
public:
	GameObject(int x_in, int y_in, Color color_in, int vx_in, int vy_in);
	void Update();
	void Update(Keyboard& kbd);
	void Draw(Graphics& gfx) const;
	void CheckBorder();
	bool CheckCollision(const GameObject& other);
	void ChangeColor(Color color_in);
private:
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int width = 12;
	static constexpr int height = 12;
	Color color;
};