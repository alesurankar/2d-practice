#include "Signal.h"

Signal::Signal(SignalType type_in, float waveLength_in, int amplitude_in)
	:
	type(type_in),
	waveLength(waveLength_in),
	amplitude(amplitude_in)
{}

void Signal::Draw(Graphics& gfx)
{
	for (auto& dot : dots)
	{
		gfx.PutPixel(dot, Colors::White);
	}
}

void Signal::Update()
{
	dots.emplace_back(headX, y);

	switch (type) {
	case SignalType::SIN:
		UpdateSin();
		break;
	case SignalType::COS:
		UpdateCos();
		break;
	case SignalType::SQUERE:
		UpdateSquere();
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
		dot.x -= waveLength;
	}
	// remove off-screen dots
	if (!dots.empty() && dots.front().x < 0) {
		dots.pop_front();
	}
}

void Signal::UpdateSin()
{
}

void Signal::UpdateCos()
{
}

void Signal::UpdateSquere()
{
	if (rising && !falling) {
		y--;
	}
	if (!rising && falling) {
		y++;
	}
}
