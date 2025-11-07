#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xRand(30, 770),
	yRand(30, 570)
{
	const Color colors[4] = { Colors::Red, Colors::Green, Colors::Blue, Colors::Cyan };
	Vei2 topLeft{ 0, 0 };
	for (int y = 0; y < nBricksDown; y++)
	{
		const int width = 80;
		const int height = 20;
		const Color c = colors[y];
		for (int x = 0; x < nBricksAcross; x++)
		{
			topLeft.x = width * x;
			topLeft.y = height * y;
			brick.emplace_back(RectI(topLeft, width, height), c);
		}
	}
	ball = std::make_unique<Ball>(Vei2(xRand(rng), yRand(rng)), Vec2{300.0f, 300.0f}, Colors::Green);
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
	for (const auto& br : brick)
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