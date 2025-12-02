#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	osc = std::make_unique<Oscilloscope>();
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
	osc->Update(wnd.kbd, wnd.mouse, dt);
}


/////////////////////////////////////////////////////////
void App::ComposeFrame()
{
	osc->Draw(gfx);
}