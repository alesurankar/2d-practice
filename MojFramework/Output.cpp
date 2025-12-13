#include "Output.h"
#include <utility>

Output::Output(const Vei2& pos, int width, int height)
	:
	Obj(RectI(pos, width, height), THEME::DARK)
{}

void Output::Update(std::string val)
{
	text = val;
	len_x = (16 * int(text.length()));
}

void Output::Draw(Graphics & gfx) const
{
	gfx.DrawRect(GetInsideRect(), body_color);
	bigFont.DrawText(text, { GetInsideRect().left + 20, mid_y}, content_color, gfx);
}
