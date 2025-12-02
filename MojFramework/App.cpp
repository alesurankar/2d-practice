#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
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
	dots.emplace_back(100, 20);
}


/////////////////////////////////////////////////////////
void App::ComposeFrame()
{
	for (auto& dot : dots)
	{
		gfx.PutPixel(dot, Colors::White);
	}
}