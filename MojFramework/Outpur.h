#pragma once
#include "Obj.h"
#include "Vec2.h"

class Output : public Obj
{
public:
	Output(const Vei2& pos, int width, int height);
	void Draw(Graphics& gfx) const override;
private:
};