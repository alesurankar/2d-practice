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
	//std::string GetButtonMessage();
private:
	void Pressed();
	void Released();
private:
	Color btn_color;
	Color hover_color;
	Color active_color;
	Color text_color;
	bool effect;
	bool onTop;
	bool pressed;
	bool released;
	int len_x;
	int len_y;
	int middle_x;
	int middle_y;
	Fonts smallFont = Fonts("Images\\Fonts8x14.bmp");
};