#include "GameObject.h"

GameObject::GameObject(int x_in, int y_in, Color color_in, int width_in, int height_in)
	:
	x(x_in),
	y(y_in),
	color(color_in),
	width(width_in),
	height(height_in)
{}

void GameObject::Draw(Graphics& gfx) const
{
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
		{
			gfx.PutPixel(i, j, color);
		}
	}
}

bool GameObject::CheckCollision(const GameObject& other)
{
	const int left = x;
	const int right = x + width;
	const int top = y;
	const int bottom = y + height;

	const int other_left = other.x;
	const int other_right = other.x + other.width;
	const int other_top = other.y;
	const int other_bottom = other.y + other.height;

	return 
		(left <= other_right &&
		 right >= other_left &&
		 top <= other_bottom &&
		 bottom >= other_top);
}

void GameObject::ChangeColor(Color color_in)
{
	color = color_in;
}

int GameObject::GetX()
{
	return x;
}

int GameObject::GetY()
{
	return y;
}

