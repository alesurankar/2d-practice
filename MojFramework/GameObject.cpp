#include "GameObject.h"

GameObject::GameObject(int x_in, int y_in, Color color_in)
	:
	x(x_in),
	y(y_in),
	vx(1),
	vy(1),
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
		y-=2;
	}
	if (kbd.KeyIsPressed('S'))
	{
		y+=2;
	}

	if (kbd.KeyIsPressed('A'))
	{
		x-=2;
	}
	if (kbd.KeyIsPressed('D'))
	{
		x+=2;
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
