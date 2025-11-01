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
		y-=2;
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		y+=2;
	}

	if (wnd.kbd.KeyIsPressed('A'))
	{
		x-=2;
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		x+=2;
	}

	if (x > gfx.ScreenWidth - width)
	{
		x = gfx.ScreenWidth - width;
	}
	if (x < 0)
	{
		x = 0;
	}
	if (y > gfx.ScreenHeight - height)
	{
		y = gfx.ScreenHeight - height;
	}
	if (y < 0)
	{
		y = 0;
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		color = Colors::Blue;
	}
	else
	{
		color = Colors::Green;
	}
}

void App::ComposeFrame()
{
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
		{
			gfx.PutPixel(i, j, color);
		}
	}
}