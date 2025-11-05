#include "LivingEntity.h"

LivingEntity::LivingEntity(RectI rect, Color color)
	:
	GameObject(std::move(rect), std::move(color)),
	dead(false)
{}

void LivingEntity::CheckBorder()
{
	if ((int)pos.x > Graphics::ScreenWidth - width)
	{
		pos.x = float(Graphics::ScreenWidth - width);
		vel.x = -vel.x;
	}
	if ((int)pos.x < 0)
	{
		pos.x = 0.0f;
		vel.x = -vel.x;
	}
	if ((int)pos.y > Graphics::ScreenHeight - height)
	{
		pos.y = float(Graphics::ScreenHeight - height);
		vel.y = -vel.y;
	}
	if ((int)pos.y < 0)
	{
		pos.y = 0.0f;
		vel.y = -vel.y;
	}
}

void LivingEntity::HandleCollision(const GameObject& other)
{
    if (!CheckCollision(other))
        return;

    const int left = (int)pos.x;
    const int right = (int)pos.x + width;
    const int top = (int)pos.y;
    const int bottom = (int)pos.y + height;

    const int other_left = (int)other.GetPosition().x;
    const int other_right = (int)other_left + other.GetWidth();
    const int other_top = (int)other.GetPosition().y;
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
            pos.x -= overlapLeft;
        }
        else
        {
			pos.x += overlapRight;
        }
        vel.x = -vel.x;
    }
    else
    {
        if (overlapTop < overlapBottom)
        {
			pos.y -= overlapTop;
        }
        else
        {
			pos.y += overlapBottom;
        }
        vel.y = --vel.y;
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
