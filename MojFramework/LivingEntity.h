#pragma once
#include "GameObject.h"

class LivingEntity : public GameObject {
public:
	LivingEntity(RectI rect, Color color, Vec2 vel_in = { 0, 0 });
	void CheckBorder();
	void HandleCollision(const GameObject& other);
	const Vec2& GetVel() const;
private:
	Vec2 vel;
};