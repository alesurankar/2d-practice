#include "Player.h"

Player::Player(Vei2 pos)
	:
	LivingEntity(RectI(pos, width, height), Colors::Yellow),
    temp_rect(RectF((Vec2)pos, width, height))
{}

void Player::Update(Keyboard& kbd, float dt)
{
    float baseSpeed = 160.0f;
    float speed = baseSpeed * dt;

    if (kbd.KeyIsPressed(VK_SPACE))
        speed *= 2.0f;

    Vec2 dir = { 0.0f, 0.0f };

    if (kbd.KeyIsPressed('W')) dir.y -= 1.0f;
    if (kbd.KeyIsPressed('S')) dir.y += 1.0f;
    if (kbd.KeyIsPressed('A')) dir.x -= 1.0f;
    if (kbd.KeyIsPressed('D')) dir.x += 1.0f;

    if (dir.x != 0.0f || dir.y != 0.0f)
    {
        dir = dir.GetNormalized() * speed;

        temp_rect.Translate(dir);
        rect = temp_rect;
    }
}