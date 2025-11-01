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
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void App::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed('W'))
	{
		y--;
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		y++;
	}

	if (wnd.kbd.KeyIsPressed('A'))
	{
		x--;
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		x++;
	}
}

void App::ComposeFrame()
{

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		gfx.PutPixel(x - 1, y + 3, Colors::Green);
		gfx.PutPixel(x + 0, y + 3, Colors::Green);
		gfx.PutPixel(x + 1, y + 3, Colors::Green);
		gfx.PutPixel(x + 2, y + 3, Colors::Green);
		gfx.PutPixel(x + 4, y + 3, Colors::Green);
		gfx.PutPixel(x + 5, y + 3, Colors::Green);
		gfx.PutPixel(x + 6, y + 3, Colors::Green);
		gfx.PutPixel(x + 7, y + 3, Colors::Green);

		gfx.PutPixel(x + 3, y - 1, Colors::Green);
		gfx.PutPixel(x + 3, y + 0, Colors::Green);
		gfx.PutPixel(x + 3, y + 1, Colors::Green);
		gfx.PutPixel(x + 3, y + 2, Colors::Green);
		gfx.PutPixel(x + 3, y + 4, Colors::Green);
		gfx.PutPixel(x + 3, y + 5, Colors::Green);
		gfx.PutPixel(x + 3, y + 6, Colors::Green);
		gfx.PutPixel(x + 3, y + 7, Colors::Green);
	}
	else {
		gfx.PutPixel(x - 1, y + 3, Colors::Blue);
		gfx.PutPixel(x + 0, y + 3, Colors::Blue);
		gfx.PutPixel(x + 1, y + 3, Colors::Blue);
		gfx.PutPixel(x + 2, y + 3, Colors::Blue);
		gfx.PutPixel(x + 4, y + 3, Colors::Blue);
		gfx.PutPixel(x + 5, y + 3, Colors::Blue);
		gfx.PutPixel(x + 6, y + 3, Colors::Blue);
		gfx.PutPixel(x + 7, y + 3, Colors::Blue);
										  
		gfx.PutPixel(x + 3, y - 1, Colors::Blue);
		gfx.PutPixel(x + 3, y + 0, Colors::Blue);
		gfx.PutPixel(x + 3, y + 1, Colors::Blue);
		gfx.PutPixel(x + 3, y + 2, Colors::Blue);
		gfx.PutPixel(x + 3, y + 4, Colors::Blue);
		gfx.PutPixel(x + 3, y + 5, Colors::Blue);
		gfx.PutPixel(x + 3, y + 6, Colors::Blue);
		gfx.PutPixel(x + 3, y + 7, Colors::Blue);
	}
}