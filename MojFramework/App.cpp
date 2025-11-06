#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xRand(30, 770),
	yRand(30, 570),
	dir(-200.0f, 200.0f)
{
	brick.emplace_back(RectI{ 20,20,400,400 }, Colors::Cyan);
	ball = std::make_unique<Ball>(Vei2(xRand(rng), yRand(rng)), Vec2(dir(rng), dir(rng)), Colors::Green);
}

void App::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

////////////////////////////////////////////////////////////
void App::UpdateModel()
{
	const float dt = ft.Mark();
}


/////////////////////////////////////////////////////////
void App::ComposeFrame()
{
	for (auto& b : brick)
	{
		b.Draw(gfx);
	}
	ball->Draw(gfx);
}