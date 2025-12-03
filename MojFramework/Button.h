#pragma once
#include "Field.h"

class Button : public Field
{
public:
	Button(
		Vei2 pos, int width, int height, Field::THEME theme, std::string text);
	void Update(const Mouse& mouse, float dt) override;
	void Draw(Graphics& gfx) const override;
	bool GetEffect();
	bool GetToggle();
	//std::string GetButtonMessage();
private:
	void Pressed();
	void Released();
private:
	bool effect;
	bool onTop;
	bool pressed;
	bool toggle;
	bool released;
	Fonts smallFont = Fonts("Images\\Fonts8x14.bmp");
};