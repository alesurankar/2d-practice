#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Rect.h"
#include "Fonts.h"
//#include <vector>

class MCUSimulator
{
public:
	MCUSimulator(const Vei2& pos, int pinPairs, std::string text);
	void Draw(Graphics& gfx) const;
private:
	Vei2 pos;
	int pinPairs;
	std::string text;
	RectI mcu;
	//std::vector<RectI> pins;
	Fonts smallFont = Fonts("Images\\Fonts8x14.bmp");
};