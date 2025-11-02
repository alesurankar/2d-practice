#include "GameObject.h"

GameObject::GameObject(int x_in, int y_in, Color color_in, int vx_in = 0, int vy_in = 0)
	:
	x(x_in),
	y(y_in),
	vx(vx_in),
	vy(vy_in),
	color(color_in)
{}

void GameObject::Update()
{
	x += vx;
	y += vy;
}

void GameObject::Update(Keyboard& kbd)
{
	if (kbd.KeyIsPressed('W'))
	{
		y--;
	}
	if (kbd.KeyIsPressed('S'))
	{
		y++;
	}

	if (kbd.KeyIsPressed('A'))
	{
		x--;
	}
	if (kbd.KeyIsPressed('D'))
	{
		x++;
	}
}

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

void GameObject::CheckBorder()
{
	if (x > Graphics::ScreenWidth - width)
	{
		x = Graphics::ScreenWidth - width;
		vx = -vx;
	}
	if (x < 0)
	{
		x = 0;
		vx = -vx;
	}
	if (y > Graphics::ScreenHeight - height)
	{
		y = Graphics::ScreenHeight - height;
		vy = -vy;
	}
	if (y < 0)
	{
		y = 0;
		vy = -vy;
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
