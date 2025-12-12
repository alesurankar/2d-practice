#include "Outpur.h"

Output::Output(const Vei2& pos, int width, int height)
	:
	Obj(RectI(pos, width, height), THEME::DARK)
{}

void Output::Draw(Graphics & gfx) const
{
	gfx.DrawRect(GetInsideRect(), body_color);
}
