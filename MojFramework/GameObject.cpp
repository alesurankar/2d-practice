#include "GameObject.h"
#include <utility>

GameObject::GameObject(Location loc_in, Color color_in, int width_in, int height_in)
	:
	loc(std::move(loc_in)),
	color(std::move(color_in)),
	width(width_in),
	height(height_in)
{}

void GameObject::Draw(Graphics& gfx) const
{
	for (int i = (int)loc.x; i < (int)loc.x + width; i++)
	{
		for (int j = (int)loc.y; j < (int)loc.y + height; j++)
		{
			gfx.PutPixel(i, j, color);
		}
	}
}

bool GameObject::CheckCollision(const GameObject& other)
{
	const int left = (int)loc.x;
	const int right = (int)loc.x + width;
	const int top = (int)loc.y;
	const int bottom = (int)loc.y + height;

	const int other_left = (int)other.loc.x;
	const int other_right = (int)other.loc.x + other.width;
	const int other_top = (int)other.loc.y;
	const int other_bottom = (int)other.loc.y + other.height;

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

Location GameObject::GetLocation() const
{
	return loc;
}

int GameObject::GetWidth() const
{
	return width;
}

int GameObject::GetHeight() const
{
	return height;
}
