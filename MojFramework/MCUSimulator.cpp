#include "MCUSimulator.h"
#include <utility>

MCUSimulator::MCUSimulator(const Vei2& pos_in, int pinPairs_in, std::string text_in)
	:
	pos(pos_in),
	pinPairs(pinPairs_in),
	text(std::move(text_in))
{
	const int pinSpaceWidth = 12;
	const int pinWidth = 2;
	const int pinHeight = 4;
	const int width = pinSpaceWidth * pinPairs;
	const int height = 40;
	mcu = RectI(pos_in, width, height);
	//pins.emplace_back(Vei2(pos.x + pinSpace, pos.y + pinHeight), pinWidth, pinHeight, Colors::DarkGray);
}

void MCUSimulator::Draw(Graphics& gfx) const 
{
	gfx.DrawRect(mcu, Colors::Black);

	gfx.DrawCircle(pos.x + 12, pos.y + 12, 5, Colors::LightGray);
	smallFont.DrawText(text, { pos.x + 40, pos.y + 14 }, Colors::White, gfx);
	//for (auto& p : pins) {
	//	gfx.DrawRect(Vec2(p.GetLeftTop()), Colors::White);
	//}
}