#include "Oscilloscope.h"

Oscilloscope::Oscilloscope()
{
	button.emplace_back(Vei2{ 20, 20 }, 60, 20, Field::THEME::LIGHT, "test");
	button.emplace_back(Vei2{ 20, 60 }, 60, 20, Field::THEME::DARK, "test2");
	button.emplace_back(Vei2{ 20, 100 }, 60, 20, Field::THEME::RED, "test");
	button.emplace_back(Vei2{ 20, 140 }, 60, 20, Field::THEME::GREEN, "test2");
	grid_btn = std::make_unique<Button>(Vei2{ 700, 40 }, 120, 20, Field::THEME::LIGHT, "Grid ON/OFF");
	screen_disp = std::make_unique<Display>(Vei2{ 150, 100 }, Graphics::ScreenWidth - 300, Graphics::ScreenHeight - 200, Field::THEME::DARK, Display::TYPE::WAVEFORM);
}

void Oscilloscope::Update(const Mouse& mouse, float dt)
{
	for (auto& b : button)
	{
		b.Update(mouse, dt);
	}
	//for (auto& d : display)
	//{
	//	d.Update(mouse, dt);
	//}
	grid_btn->Update(mouse, dt);
	screen_disp->Update(mouse, dt);
	screen_disp->SetGrid(grid_btn->GetToggle());
}

void Oscilloscope::Draw(Graphics& gfx) const
{
	for (auto& b : button)
	{
		b.Draw(gfx);
	}
	//for (auto& d : display)
	//{
	//	d.Draw(gfx);
	//}
	grid_btn->Draw(gfx);
	screen_disp->Draw(gfx);
}