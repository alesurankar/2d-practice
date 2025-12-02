#pragma once
#include <deque>
#include "Graphics.h"

class Signal
{
public:
	enum class SignalType
	{
		SIN,
		COS
	};
	Signal(SignalType type, float leftBorder, float rightBorder, float waveLength, float amplitude);
	void Draw(Graphics& gfx);
	void Update(float dt);
	void UpdateSin();
	void UpdateCos();
private:
	std::deque<Vec2> dots;
	float rightBorder = float(Graphics::ScreenWidth - 1);
	float mid = float(Graphics::ScreenHeight / 2);
	float leftBorder;
	float x = rightBorder;
	float y = mid;
	float waveLength;
	float amplitude; 
	float phase = 0.0f;
	bool rising = true;
	bool falling = false;
	SignalType type;
};