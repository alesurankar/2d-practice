#pragma once
#include "Graphics.h"
#include "Mouse.h"
#include "Menu.h"
#include "Signal.h"
#include <memory>

class Oscilloscope
{
public:
	Oscilloscope();
	void Update(const Mouse& mouse, float dt);
	void Draw(Graphics& gfx);
private:
	std::unique_ptr<Menu> menu;
	std::unique_ptr<Signal> signal;
};