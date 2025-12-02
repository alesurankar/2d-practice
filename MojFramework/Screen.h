#pragma once
#include "Graphics.h"
#include "Signal.h"
#include <memory>

class Screen
{
public:
	Screen();
	void Update(float dt);
	void Draw(Graphics& gfx) const;
private:
	std::unique_ptr<Signal> signal;
};