#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Case.h"
#include "Input.h"
#include "Output.h"
#include "Values.h"
#include <string>
#include <memory>

class Calculator
{
public:
	Calculator(const Vei2& pos);
	void Update(const Mouse& mouse, float dt);
	void Draw(Graphics& gfx) const;
private:
	Values val;
	std::unique_ptr<Case> cse;
	std::unique_ptr<Input> btn1;
	std::unique_ptr<Input> btn2;
	std::unique_ptr<Input> btn3;
	std::unique_ptr<Output> disp;
	//std::string val = "0";
};