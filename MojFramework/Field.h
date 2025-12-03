#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Fonts.h"
#include "Rect.h"
#include "Vec2.h"
#include <string>

class Field
{
public:
	enum class THEME {
		LIGHT,
		DARK,
		RED,
		GREEN,
		BLUE
	};
	Field(
		Vei2 pos, int width, int height, THEME theme, std::string text);
	virtual void Update(const Mouse& mouse, float dt) = 0;
	virtual void Draw(Graphics& gfx) const = 0;
	void SetTheme(THEME theme);
	const Vei2& GetPos();
	const int& GetWidth();
	const int& GetHeight();
private:
	Vei2 pos;
	int width = 0;
	int height = 0;
protected:
	std::string text;
	Color body_color;
	Color border_color;
	Color content_color;
	Color action_color;
	RectI outside;
	RectI inside;
private:
	int len_x;
	int len_y;
	int middle_x;
	int middle_y;
	Fonts smallFont = Fonts("Images\\Fonts8x14.bmp");
};

