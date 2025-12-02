#pragma once
#include "Graphics.h"
#include "Mouse.h"
#include "Fonts.h"
#include "Rect.h"
#include "Vec2.h"
#include <string>

class Button
{
public:
	Button(
		int x_in, int y_in,
		int width_in, int height_in,
		std::string text_in,
		Color btn_color = Colors::Blue,
		Color hover_color = Colors::Yellow,
		Color active_color = Colors::DarkBlue,
		Color text_color = Colors::Yellow
	);
	void Draw(Graphics& gfx) const;
	void Update(const Mouse& mouse);
	bool GetEffect();
	std::string GetButtonMessage();
	void Pressed();
	void Released();
private:
	int x;
	int y;
	int width;
	int height;
	std::string text;
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
	RectI outside;
	RectI inside;
	Fonts smallFont = Fonts("Images\\Fonts8x14.bmp");
};