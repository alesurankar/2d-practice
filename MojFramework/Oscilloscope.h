#pragma once
#include "Graphics.h"
#include "Mouse.h"
#include "Button.h"
#include "Display.h"
#include <vector>
#include <memory>

class Oscilloscope
{
public:
	Oscilloscope();
	void Update(const Mouse& mouse, float dt);
	void Draw(Graphics& gfx) const;
private:
	std::vector<Button> button;
	std::unique_ptr<Button> grid_btn;
	std::unique_ptr<Display> screen_disp;
	//amplitude
	std::unique_ptr<Button> amp_btn;
	std::unique_ptr<Button> amp_up_btn;
	std::unique_ptr<Button> amp_dwn_btn;
	std::unique_ptr<Display> amp_disp;
};