#include "MCUSimulator.h"
#include <utility>

MCUSimulator::MCUSimulator(const Vei2& pos_in, int pinPairs_in, std::string text_in)
	:
	pos(pos_in),
	pinPairs(pinPairs_in),
	text(std::move(text_in))
{
	const int pinSpaceWidth = 16;
	const int pinWidth = 10;
	const int pinHeight = 12;
	const int width = pinSpaceWidth * pinPairs;
	const int height = 50;
	mcu = RectI(pos_in, width, height);
	for (int i = 0; i < pinPairs; ++i) {
		pinsDwn.emplace_back(Vei2{ pos_in.x + (pinSpaceWidth / 2) - pinWidth/2 + (pinSpaceWidth * i), pos_in.y + height }, pinWidth, pinHeight, Field::THEME::BLUE, "");
		pinsUp.emplace_back(Vei2{ pos_in.x + (pinSpaceWidth / 2) - pinWidth/2 + (pinSpaceWidth * i), pos_in.y - pinHeight }, pinWidth, pinHeight, Field::THEME::BLUE, "");
	}
}

void MCUSimulator::Update(const Mouse& mouse, float dt)
{
	for (auto& p : pinsUp) {
		p.Update(mouse, dt);
		if (p.GetToggle()) {
			p.SetTheme(Field::THEME::BLUE);
		}
		else {
			p.SetTheme(Field::THEME::RED);
		}
	}
	for (auto& p : pinsDwn) {
		p.Update(mouse, dt); 
		if (p.GetToggle()) {
			p.SetTheme(Field::THEME::BLUE);
		}
		else {
			p.SetTheme(Field::THEME::RED);
		}
	}
}

void MCUSimulator::Draw(Graphics& gfx) const 
{
	gfx.DrawRect(mcu, Colors::Black);
	for (auto& p : pinsUp) {
		p.Draw(gfx);
	}
	for (auto& p : pinsDwn) {
		p.Draw(gfx);
	}

	//pinsDwn->Draw(gfx);
	//gfx.DrawRect(pinDwn, Colors::Black);

	gfx.DrawCircle(pos.x + 12, pos.y + 12, 5, Colors::LightGray);
	smallFont.DrawText(text, { pos.x + 40, pos.y + 14 }, Colors::White, gfx);
	
}