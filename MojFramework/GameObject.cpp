#include "GameObject.h"
#include <utility>

GameObject::GameObject(Vec2 pos_in, Color color_in, int width_in, int height_in)
	:
	pos(std::move(pos_in)),
	color(std::move(color_in)),
	width(width_in),
	height(height_in)
{}

void GameObject::Draw(Graphics& gfx) const
{
	for (int i = (int)pos.x; i < (int)pos.x + width; i++)
	{
		for (int j = (int)pos.y; j < (int)pos.y + height; j++)
		{
			gfx.PutPixel(i, j, color);
		}
	}
}

bool GameObject::CheckCollision(const GameObject& other)
{
	const int left = (int)pos.x;
	const int right = (int)pos.x + width;
	const int top = (int)pos.y;
	const int bottom = (int)pos.y + height;

	const int other_left = (int)other.pos.x;
	const int other_right = (int)other.pos.x + other.width;
	const int other_top = (int)other.pos.y;
	const int other_bottom = (int)other.pos.y + other.height;

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

Vec2 GameObject::GetPosition() const
{
	return pos;
}

int GameObject::GetWidth() const
{
	return width;
}

int GameObject::GetHeight() const
{
	return height;
}
