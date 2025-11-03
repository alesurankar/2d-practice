#pragma once
#include "GameObject.h"

class LivingEntity : public GameObject {
public:
	LivingEntity(int x, int y, Color color, int vx_in, int vy_in, int width, int height);
	void Update();
	void Update(Keyboard& kbd);
	void CheckBorder();
	bool DeadCheck();
	void SetDead();
private:
	int vx;
	int vy;
	bool dead;
};