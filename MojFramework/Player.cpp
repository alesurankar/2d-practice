#include "Player.h"

Player::Player(Location loc)
	:
	LivingEntity(std::move(loc), Colors::Yellow, 0, 0, width, height)
{}
