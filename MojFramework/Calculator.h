#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Case.h"
#include "Input.h"
#include "Outpur.h"
#include <memory>

class Calculator
{
public:
	Calculator(const Vei2& pos);
	void Update(const Mouse& mouse, float dt);
	void Draw(Graphics& gfx) const;
private:
	std::unique_ptr<Case> cse;
	std::unique_ptr<Input> btn;
	std::unique_ptr<Output> disp;
};