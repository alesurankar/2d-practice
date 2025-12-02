#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	menu = std::make_unique<Menu>(Menu::MenuType::IN_APP);
	signal = std::make_unique<Signal>(Signal::SignalType::SIN, 100.0f, 50.0f);
}

void App::Go()
{
	gfx.BeginFrame(Colors::DarkGray);
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame(1);
}

////////////////////////////////////////////////////////////
void App::UpdateModel()
{
	const float dt = ft.Mark();
	signal->Update(dt);
	menu->Update(wnd.mouse);
}


/////////////////////////////////////////////////////////
void App::ComposeFrame()
{
	signal->Draw(gfx);
	menu->Draw(gfx);
}