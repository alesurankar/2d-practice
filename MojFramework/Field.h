#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Fonts.h"
#include <string>

class Field
{
public:
	Field(
		int x_in, int y_in,
		int width_in, int height_in,
		std::string text = "",
		Color color = Colors::Black,
		Color border_color = Colors::LightGray,
		Color text_color = Colors::White
	);
	void Update(const Keyboard& kbd, const Mouse& mouse, float dt);
	void Draw(Graphics& gfx) const;
private:
	int value = 11; 
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	std::string text = "";
	Color color;
	Color border_color;
	Color text_color;
	int len_x;
	int len_y;
	int middle_x;
	int middle_y;
	RectI outside;
	RectI inside;
	Fonts smallFont = Fonts("Images\\Fonts8x14.bmp");
};

