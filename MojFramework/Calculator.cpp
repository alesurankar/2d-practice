#include "Calculator.h"
#include "Case.h"

Calculator::Calculator(const Vei2& pos)
{
	cse = std::make_unique<Case>(pos, 400, 500);
	btn1 = std::make_unique<Input>(Vei2(pos.x + 30, pos.y + 200), 40, 40, "1");
	btn2 = std::make_unique<Input>(Vei2(pos.x + 80, pos.y + 200), 40, 40, "2");
	btn3 = std::make_unique<Input>(Vei2(pos.x + 130, pos.y + 200), 40, 40, "3");
	disp = std::make_unique<Output>(Vei2(pos.x + 30, pos.y + 30), 300, 50);
}

void Calculator::Update(const Mouse& mouse, float dt)
{
	if (auto v = btn1->Update(mouse, dt)) {
		val.TakeValue(v.value());
	}
	if (auto v = btn2->Update(mouse, dt)) {
		val.TakeValue(v.value());
	}
	if (auto v = btn3->Update(mouse, dt)) {
		val.TakeValue(v.value());
	}
	disp->Update(val.GetValue());
}

void Calculator::Draw(Graphics & gfx) const
{
	//gfx.DrawCircle({ 100,100 }, 10, Colors::Black);
	cse->Draw(gfx);
	btn1->Draw(gfx);
	btn2->Draw(gfx);
	btn3->Draw(gfx);
	disp->Draw(gfx);
}