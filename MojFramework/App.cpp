#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xRand(10, 680),
	yRand(10, 580),
	dir(-1, 1)
{
	player = std::make_unique<Player>(xRand(rng), yRand(rng));
	for (int n = 0; n < enemyNum; n++)
	{
		enemy.emplace_back(xRand(rng), yRand(rng), dir(rng), dir(rng));
	}
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
	objects.clear();
	objects.reserve(enemy.size() + 1);
	UpdateEnemy();
	UpdatePlayer();
}

void App::UpdatePlayer()
{
	player->Update(wnd.kbd);
	player->CheckBorder();
	player->ChangeColor(Colors::Yellow);
	for (Enemy& e : enemy)
	{
		if (player->CheckCollision(e))
		{
			player->ChangeColor(Colors::Blue);
		}
	}
	objects.push_back(player.get());
}

void App::UpdateEnemy()
{
	for (Enemy& e : enemy)
	{
		e.Update();
		e.CheckBorder();
		objects.push_back(&e);
	}
}

void App::ComposeFrame()
{
	for (GameObject* obj : objects)
	{
		obj->Draw(gfx);
	}
}