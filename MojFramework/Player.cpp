#include "Player.h"

Player::Player(Vec2 pos_in)
	:
	LivingEntity(RectI((Vei2)pos_in, width, height), Colors::Yellow, { 0, 0 }),
	pos(pos_in)
{}

void Player::Update(Keyboard& kbd, float dt)
{
	float speed;
	if (kbd.KeyIsPressed(VK_SPACE))
		speed = 320.0f * dt;
	else
		speed = 160.0f * dt;
	if (kbd.KeyIsPressed('W'))
		pos.y -= speed;
	if (kbd.KeyIsPressed('S'))
		pos.y += speed;
	if (kbd.KeyIsPressed('A'))
		pos.x -= speed;
	if (kbd.KeyIsPressed('D'))
		pos.x += speed;
	MakeRect();
}

void Player::MakeRect()
{
	rect = RectI((Vei2)pos, width, height);
}
