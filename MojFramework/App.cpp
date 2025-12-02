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

}


/////////////////////////////////////////////////////////
void App::ComposeFrame()
{
	gfx.PutPixel(10, 10, Colors::White);
	smallFont.DrawText("test",Vei2(20, 20), Colors::White, gfx);
}