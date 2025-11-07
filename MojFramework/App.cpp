#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xRand(30, 770),
	yRand(30, 570),
	dir(-300.0f, 300.0f)
{
	ball = std::make_unique<Ball>(Vei2(xRand(rng), yRand(rng)), Vec2(dir(rng), dir(rng)), Colors::Green);
	brick.emplace_back(RectI{ 20,20,160,80 }, Colors::Cyan);
	walls = std::make_unique<RectI>(0, 0, gfx.ScreenWidth, gfx.ScreenHeight);
	pad = std::make_unique<Pad>(Vei2{ 400, 540 });
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
	ball->Update(dt);
	ball->DoWallCollision(*walls);
	for (auto& b : brick)
	{
		b.DoBallCollision(*ball);
	}
	pad->Update(wnd.kbd, dt);
	pad->DoBallCollision(*ball);
	pad->DoWallCollision(*walls);

	EraseObjects();
}


/////////////////////////////////////////////////////////
void App::ComposeFrame()
{
	for (auto& br : brick)
	{
		br.Draw(gfx);
	}
	ball->Draw(gfx);
	pad->Draw(gfx);
}

void App::EraseObjects()
{
	auto erase_destroyed = [](auto& container)
		{
			container.erase(
				std::remove_if(container.begin(), container.end(),
					[](auto& obj) { return obj.DestroyedCheck(); }),
				container.end());
		};

	erase_destroyed(brick);
}