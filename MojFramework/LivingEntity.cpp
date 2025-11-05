#include "LivingEntity.h"

LivingEntity::LivingEntity(RectI rect, Color color, Vec2 vel_in)
	:
	GameObject(std::move(rect), std::move(color)),
    vel(vel_in),
	dead(false)
{}

void LivingEntity::CheckBorder()
{
	if (rect.right > Graphics::ScreenWidth - 1)
	{
		rect.right = Graphics::ScreenWidth - 1;
		vel.x = -vel.x;
	}
	if (rect.left < 1)
	{
		rect.left = 1;
		vel.x = -vel.x;
	}
	if (rect.bottom > Graphics::ScreenHeight - 1)
	{
        rect.bottom = Graphics::ScreenHeight - 1;
		vel.y = -vel.y;
	}
	if (rect.top <= 1)
	{
		rect.top = 1;
		vel.y = -vel.y;
	}
}

//void LivingEntity::HandleCollision(const GameObject& other)
//{
//    if (!CheckCollision(other))
//        return;
//
//    const int left = rect.GetPos().x;
//    const int right = rect.GetPos().x + rect.GetWidth();
//    const int top = rect.GetPos().y;
//    const int bottom = rect.GetPos().y + rect.GetHeight();
//
//    const int other_left = (int)other.GetPosition().x;
//    const int other_right = (int)other_left + other.rect.GetHeight()();
//    const int other_top = (int)other.GetPosition().y;
//    const int other_bottom = (int)other_top + other.rect.GetHeight()();
//
//    int overlapLeft = right - other_left;
//    int overlapRight = other_right - left;
//    int overlapTop = bottom - other_top;
//    int overlapBottom = other_bottom - top;
//
//    int minOverlapX = std::min(overlapLeft, overlapRight);
//    int minOverlapY = std::min(overlapTop, overlapBottom);
//
//    if (minOverlapX < minOverlapY)
//    {
//        if (overlapLeft < overlapRight)
//        {
//            pos.x -= overlapLeft;
//        }
//        else
//        {
//			pos.x += overlapRight;
//        }
//        vel.x = -vel.x;
//    }
//    else
//    {
//        if (overlapTop < overlapBottom)
//        {
//			pos.y -= overlapTop;
//        }
//        else
//        {
//			pos.y += overlapBottom;
//        }
//        vel.y = --vel.y;
//    }
//}

bool LivingEntity::DeadCheck()
{
	return dead;
}

void LivingEntity::SetDead()
{
	dead = true;
}

Vec2 LivingEntity::GetVel()
{
	return vel;
}
