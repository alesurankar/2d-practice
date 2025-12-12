#pragma once
#include "Obj.h"
#include "Vec2.h"
#include "Mouse.h"

class Input : public Obj
{
public:
	Input(const Vei2& pos, int width, int height);
	void Update(const Mouse& mouse, float dt);
	void Draw(Graphics& gfx) const override;
private:
	void Pressed();
	void Released();
private:
	bool effect;
	bool onTop;
	bool pressed;
	bool toggle;
	bool released;
};