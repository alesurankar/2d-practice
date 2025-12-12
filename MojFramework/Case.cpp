#include "Case.h"

Case::Case(const Vei2& pos, int width, int height)
	:
	Obj(RectI(pos, width, height), THEME::LIGHTGRAY)
{}

void Case::Draw(Graphics& gfx) const
{
	gfx.DrawRect(GetInsideRect(), body_color);
}