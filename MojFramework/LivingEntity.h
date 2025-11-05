#pragma once
#include "GameObject.h"

class LivingEntity : public GameObject {
public:
	LivingEntity(Location loc, Color color, float vx_in, float vy_in, int width, int height);
	void Update();
	void Update(Keyboard& kbd);
	void CheckBorder();
	void HandleCollision(const GameObject& other);
	bool DeadCheck();
	void SetDead();
private:
	float vx;
	float vy;
	bool dead;
};