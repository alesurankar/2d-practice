#include "Player.h"

Player::Player(Vec2 pos)
	:
	LivingEntity(std::move(pos), Colors::Yellow, { 0, 0 }, width, height)
{}
