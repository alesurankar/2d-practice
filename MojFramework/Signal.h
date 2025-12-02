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
	Signal(SignalType type = SignalType::SIN, float waveLength = 1.0f, int amplitude = 20);
	void Draw(Graphics& gfx);
	void Update();
	void UpdateSin();
	void UpdateCos();
	void UpdateSquere();
private:
	std::deque<Vec2> dots;
	static constexpr float headX = float(Graphics::ScreenWidth - 1);
	static constexpr float mid = float(Graphics::ScreenHeight / 2);
	float x = headX;
	float y = float (Graphics::ScreenHeight / 2);
	float waveLength = 1.0f;
	int amplitude; 
	bool rising = true;
	bool falling = false;
	SignalType type;
};