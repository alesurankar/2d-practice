#pragma once
#include "GameObject.h"

class LivingEntity : public GameObject {
public:
	LivingEntity(RectI rect, Color color);
	void CheckBorder();
	void HandleCollision(const GameObject& other);
	bool DeadCheck();
	void SetDead();
private:
	bool dead;
};