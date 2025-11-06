#include "LivingEntity.h"

LivingEntity::LivingEntity(RectI rect, Color color, Vec2 vel_in)
	:
	GameObject(std::move(rect), std::move(color)),
    vel(std::move(vel_in))
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

void LivingEntity::HandleCollision(const GameObject& other)
{
	if (rect.IsOverlappingWith(other.GetRect()))
	{
		// TO DO
	}
}

const Vec2& LivingEntity::GetVel() const
{
	return vel;
}
