#include "Oscilloscope.h"

Oscilloscope::Oscilloscope()
{
	grid_btn = std::make_unique<Button>(Vei2{ 700, 40 }, 120, 20, Field::THEME::LIGHT, "Grid ON/OFF");	
	screen_disp = std::make_unique<Display>(Vei2{ 150, 100 }, Graphics::ScreenWidth - 300, Graphics::ScreenHeight - 200, Field::THEME::DARK, Display::TYPE::WAVEFORM);

	amp_btn = std::make_unique<Button>(Vei2{ 10, 10 }, 60, 20, Field::THEME::LIGHT, "Amp");
	amp_up_btn = std::make_unique<Button>(Vei2{ 70, 10 }, 19, 20, Field::THEME::BLUE, "<");
	amp_dwn_btn = std::make_unique<Button>(Vei2{ 90, 10 }, 19, 20, Field::THEME::BLUE, ">");
	amp_disp = std::make_unique<Display>(Vei2{ 11, 35 }, 98, 38, Field::THEME::DARK, Display::TYPE::VALUE);
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

	//amplitude
	amp_up_btn->Update(mouse, dt);
	amp_dwn_btn->Update(mouse, dt);
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

	//amplitude
	amp_btn->Draw(gfx);
	amp_up_btn->Draw(gfx);
	amp_dwn_btn->Draw(gfx);
	amp_disp->Draw(gfx);
}