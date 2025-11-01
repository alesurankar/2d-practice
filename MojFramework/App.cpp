#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	player = std::make_unique<Player>(100, 100);
	enemy.emplace_back(10, 10);
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