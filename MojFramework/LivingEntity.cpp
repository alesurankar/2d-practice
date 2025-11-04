#include "LivingEntity.h"

LivingEntity::LivingEntity(Location loc, Color color, int vx_in, int vy_in, int width, int height)
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
	int speed;
	if (kbd.KeyIsPressed(VK_SPACE))
		speed = 3;
	else
		speed = 1;
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
	if (loc.x > Graphics::ScreenWidth - width)
	{
		loc.x = Graphics::ScreenWidth - width;
		vx = -vx;
	}
	if (loc.x < 0)
	{
		loc.x = 0;
		vx = -vx;
	}
	if (loc.y > Graphics::ScreenHeight - height)
	{
		loc.y = Graphics::ScreenHeight - height;
		vy = -vy;
	}
	if (loc.y < 0)
	{
		loc.y = 0;
		vy = -vy;
	}
}

void LivingEntity::HandleCollision(const GameObject& other)
{
    if (!CheckCollision(other))
        return;

    const int left = loc.x;
    const int right = loc.x + width;
    const int top = loc.y;
    const int bottom = loc.y + height;

    const int other_left = other.GetLocation().x;
    const int other_right = other_left + other.GetWidth();
    const int other_top = other.GetLocation().y;
    const int other_bottom = other_top + other.GetHeight();

    // Compute overlap distances
    int overlapLeft = right - other_left;
    int overlapRight = other_right - left;
    int overlapTop = bottom - other_top;
    int overlapBottom = other_bottom - top;

    // Find the smallest overlap — that's the direction of correction
    int minOverlapX = std::min(overlapLeft, overlapRight);
    int minOverlapY = std::min(overlapTop, overlapBottom);

    if (minOverlapX < minOverlapY)
    {
        // Horizontal collision
        if (overlapLeft < overlapRight)
        {
            // collided from left
            loc.x -= overlapLeft;
        }
        else
        {
            // collided from right
            loc.x += overlapRight;
        }
        vx = -vx; // stop horizontal movement
    }
    else
    {
        // Vertical collision
        if (overlapTop < overlapBottom)
        {
            // collided from top
            loc.y -= overlapTop;
        }
        else
        {
            // collided from bottom
            loc.y += overlapBottom;
        }
        vy = --vy; // stop vertical movement
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
