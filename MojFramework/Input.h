#pragma once
#include "Obj.h"
#include "Vec2.h"
#include "Mouse.h"
#include <optional>

class Input : public Obj
{
public:
	Input(const Vei2& pos, int width, int height, std::string text);
	std::optional<std::string> Update(const Mouse& mouse, float dt);
	void Draw(Graphics& gfx) const override;
private:
	void Pressed();
	void Released();
private:
	std::string text;
	int len_x;
	int len_y;
	int mid_x;
	int mid_y;
	bool effect;
	bool onTop;
	bool pressed;
	bool toggle;
	bool released;
};