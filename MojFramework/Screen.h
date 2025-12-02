#pragma once
#include "Graphics.h"
#include "Signal.h"
#include "Field.h"
#include <memory>

class Screen
{
public:
	Screen();
	void Update(const Keyboard& kbd, const Mouse& mouse, float dt);
	void Draw(Graphics& gfx) const;
private:
	std::unique_ptr<Signal> signal;
	std::unique_ptr<Field> display;
};