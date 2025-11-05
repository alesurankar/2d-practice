#pragma once
#include "GameObject.h"

class LivingEntity : public GameObject {
public:
	LivingEntity(RectI rect, Color color, Vec2 vel_in);
	void CheckBorder();
	//void HandleCollision(const GameObject& other);
	bool DeadCheck();
	void SetDead();
	Vec2 GetVel();
private:
	Vec2 vel;
	bool dead;
};