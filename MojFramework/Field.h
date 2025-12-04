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
	Field(Vei2 pos, int width, int height, THEME theme, std::string text);
	virtual ~Field() = default;
	virtual void Update(const Mouse& mouse, float dt) = 0;
	virtual void Draw(Graphics& gfx) const = 0;
	void SetTheme(THEME theme);
	Vei2 GetPos() const;
	int GetWidth() const;
	int GetHeight() const;
	std::string GetText() const;
	void TakeEffect(const std::string& effect);
	void ChangeTheme(THEME theme);
protected:
	Vei2 pos;
	int width = 0;
	int height = 0;
	THEME theme;
protected:
	std::string text;
	Color body_color;
	Color border_color;
	Color content_color;
	Color grid_color;
	Color action_color;
	RectI outside;
	RectI inside;
	Fonts smallFont = Fonts("Images\\Fonts8x14.bmp");
private:
	int len_x;
	int len_y;
protected:
	int mid_x;
	int mid_y;
};

