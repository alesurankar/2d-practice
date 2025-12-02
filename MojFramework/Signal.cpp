#include "Signal.h"

Signal::Signal(SignalType type_in, float waveLength_in, float amplitude_in)
	:
	type(type_in),
	waveLength(waveLength_in),
	amplitude(amplitude_in)
{}

void Signal::Draw(Graphics& gfx)
{
	for (auto& dot : dots)
	{
		gfx.PutPixel(Vei2(dot), Colors::White);
	}
}

void Signal::Update(float dt)
{
	switch (type) {
	case SignalType::SIN:
		UpdateSin(); 
		phase += dt;
		break;
	case SignalType::COS:
		UpdateCos(); 
		phase += dt;
		break;
	}

	if (y > mid + amplitude) {
		rising = true;
		falling = false;
	}
	else if (y < mid - amplitude) {
		rising = false;
		falling = true;
	}
	// scroll left
	for (auto& dot : dots) {
		dot.x -= waveLength * dt;
	}
	// remove off-screen dots
	if (!dots.empty() && dots.front().x < 0) {
		dots.pop_front();
	}

	dots.emplace_back(headX, y);
}

void Signal::UpdateSin()
{
	y = mid + std::sin(phase * 2.0f * 3.14159f) * amplitude;
}

void Signal::UpdateCos()
{
	y = mid + std::sin(phase * 2.0f * 3.14159f) * amplitude;
}