#pragma once
#include "Field.h"

class Display : public Field
{
public:
	Display(Vei2 pos, int width, int height, Field::THEME theme);
	void Update(const Mouse& mouse, float dt) override;
	void Draw(Graphics& gfx) const override;
private:
	//std::unique_ptr<Signal> signal;
};