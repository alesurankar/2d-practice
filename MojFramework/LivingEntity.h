#pragma once
#include "GameObject.h"

class LivingEntity : public GameObject {
public:
	LivingEntity(Vec2 pos, Color color, Vec2 vel_in, int width, int height);
	void Update(float dt);
	void Update(Keyboard& kbd, float dt);
	void CheckBorder();
	void HandleCollision(const GameObject& other);
	bool DeadCheck();
	void SetDead();
private:
	Vec2 vel;
	bool dead;
};