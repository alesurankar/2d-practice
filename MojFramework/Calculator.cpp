#include "Calculator.h"
#include "Case.h"

Calculator::Calculator(const Vei2& pos)
{
	cse = std::make_unique<Case>(pos, 400, 500);
	btn = std::make_unique<Input>(Vei2(pos.x + 30, pos.y + 200), 40, 40);
	disp = std::make_unique<Output>(Vei2(pos.x + 30, pos.y + 30), 300, 50);
}

void Calculator::Update(const Mouse& mouse, float dt)
{
	btn->Update(mouse, dt);
}

void Calculator::Draw(Graphics & gfx) const
{
	//gfx.DrawCircle({ 100,100 }, 10, Colors::Black);
	cse->Draw(gfx);
	btn->Draw(gfx);
	disp->Draw(gfx);
}