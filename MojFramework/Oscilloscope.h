#pragma once
#include "Graphics.h"
#include "Mouse.h"
#include "Menu.h"
#include "Screen.h"
#include <memory>

class Oscilloscope
{
public:
	Oscilloscope();
	void Update(const Keyboard& kbd, const Mouse& mouse, float dt);
	void Draw(Graphics& gfx) const;
private:
	std::unique_ptr<Menu> menu;
	std::unique_ptr<Screen> screen;
};