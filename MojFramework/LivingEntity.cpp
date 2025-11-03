#include "LivingEntity.h"

LivingEntity::LivingEntity(int x, int y, Color color, int vx_in, int vy_in, int width, int height)
	:
	GameObject(x, y, color, width, height),
	vx(vx_in),
	vy(vy_in),
	dead(false)
{}

void LivingEntity::Update()
{
	x += vx;
	y += vy;
}

void LivingEntity::Update(Keyboard& kbd)
{
	int speed;
	if (kbd.KeyIsPressed(VK_SPACE))
		speed = 3;
	else
		speed = 1;
	if (kbd.KeyIsPressed('W'))
		y -= speed;
	if (kbd.KeyIsPressed('S'))
		y += speed;
	if (kbd.KeyIsPressed('A'))
		x -= speed;
	if (kbd.KeyIsPressed('D'))
		x += speed;
}

void LivingEntity::CheckBorder()
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

bool LivingEntity::DeadCheck()
{
	return dead;
}

void LivingEntity::SetDead()
{
	dead = true;
}
