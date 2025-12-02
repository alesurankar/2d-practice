#pragma once
#include <deque>
#include "Graphics.h"

class Signal
{
public:
	enum class SignalType
	{
		SIN,
		COS,
		SQUERE
	};
	Signal(SignalType type, float waveLength, float amplitude);
	void Draw(Graphics& gfx);
	void Update(float dt);
	void UpdateSin();
	void UpdateCos();
private:
	std::deque<Vec2> dots;
	static constexpr float headX = float(Graphics::ScreenWidth - 1);
	static constexpr float mid = float(Graphics::ScreenHeight / 2);
	float x = headX;
	float y = float(Graphics::ScreenHeight / 2);
	float waveLength;
	float amplitude; 
	float phase = 0.0f;
	bool rising = true;
	bool falling = false;
	SignalType type;
};