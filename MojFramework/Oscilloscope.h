#pragma once
#include "Graphics.h"
#include "Mouse.h"
#include "Button.h"
#include "Display.h"
#include <vector>

class Oscilloscope
{
public:
	Oscilloscope();
	void Update(const Mouse& mouse, float dt);
	void Draw(Graphics& gfx) const;
private:
	std::vector<Button> button;
	std::vector<Display> display;
};