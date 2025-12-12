#pragma once
#include "Rect.h"
#include "Graphics.h"
#include "Fonts.h"

class Obj
{
public:
	enum class THEME {
		LIGHT,
		LIGHTGRAY,
		DARK,
		RED,
		GREEN,
		BLUE
	};
	Obj(const RectI& rect, THEME theme);
	virtual void Draw(Graphics& gfx) const = 0;
	RectI GetOutsideRect() const;
	RectI GetInsideRect() const;
	void SetTheme(THEME theme);
protected:
	Color body_color;
	Color content_color;
	Color grid_color;
	Color action_color;
	Fonts smallFont = Fonts("Images\\Fonts8x14.bmp");
	Fonts bigFont = Fonts("Images\\Fonts16x28.bmp");
private:
	RectI inside;
	RectI outside;
	THEME theme;
};