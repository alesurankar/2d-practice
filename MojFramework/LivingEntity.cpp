#include "LivingEntity.h"

LivingEntity::LivingEntity(Location loc, Color color, float vx_in, float vy_in, int width, int height)
	:
	GameObject(std::move(loc), std::move(color), width, height),
	vx(vx_in),
	vy(vy_in),
	dead(false)
{}

void LivingEntity::Update()
{
	loc.x += vx;
	loc.y += vy;
}

void LivingEntity::Update(Keyboard& kbd)
{
	float speed;
	if (kbd.KeyIsPressed(VK_SPACE))
		speed = 3.0f;
	else
		speed = 1.0f;
	if (kbd.KeyIsPressed('W'))
		loc.y -= speed;
	if (kbd.KeyIsPressed('S'))
		loc.y += speed;
	if (kbd.KeyIsPressed('A'))
		loc.x -= speed;
	if (kbd.KeyIsPressed('D'))
		loc.x += speed;
}

void LivingEntity::CheckBorder()
{
	if ((int)loc.x > Graphics::ScreenWidth - width)
	{
		loc.x = float(Graphics::ScreenWidth - width);
		vx = -vx;
	}
	if ((int)loc.x < 0)
	{
		loc.x = 0.0f;
		vx = -vx;
	}
	if ((int)loc.y > Graphics::ScreenHeight - height)
	{
		loc.y = float(Graphics::ScreenHeight - height);
		vy = -vy;
	}
	if ((int)loc.y < 0)
	{
		loc.y = 0.0f;
		vy = -vy;
	}
}

void LivingEntity::HandleCollision(const GameObject& other)
{
    if (!CheckCollision(other))
        return;

    const int left = (int)loc.x;
    const int right = (int)loc.x + width;
    const int top = (int)loc.y;
    const int bottom = (int)loc.y + height;

    const int other_left = (int)other.GetLocation().x;
    const int other_right = (int)other_left + other.GetWidth();
    const int other_top = (int)other.GetLocation().y;
    const int other_bottom = (int)other_top + other.GetHeight();

    int overlapLeft = right - other_left;
    int overlapRight = other_right - left;
    int overlapTop = bottom - other_top;
    int overlapBottom = other_bottom - top;

    int minOverlapX = std::min(overlapLeft, overlapRight);
    int minOverlapY = std::min(overlapTop, overlapBottom);

    if (minOverlapX < minOverlapY)
    {
        if (overlapLeft < overlapRight)
        {
            loc.x -= overlapLeft;
        }
        else
        {
            loc.x += overlapRight;
        }
        vx = -vx;
    }
    else
    {
        if (overlapTop < overlapBottom)
        {
            loc.y -= overlapTop;
        }
        else
        {
            loc.y += overlapBottom;
        }
        vy = --vy;
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
