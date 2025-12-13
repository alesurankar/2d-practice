#pragma once
#include "Obj.h"
#include "Vec2.h"
#include <string>

class Output : public Obj
{
public:
	Output(const Vei2& pos, int width, int height);
	void Update(std::string val);
	void Draw(Graphics& gfx) const override;
private:
	std::string text;
	int len_x = (16 * int(text.length()));
	int len_y = (28);
	int mid_y = (GetInsideRect().top + (GetInsideRect().GetHeight() / 2) - (len_y / 2));
};