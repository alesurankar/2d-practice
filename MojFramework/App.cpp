#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	player = std::make_unique<Player>(100, 100);
	enemy.emplace_back(10, 10);
	enemy.emplace_back(100, 10);
	enemy.emplace_back(50, 50);
	enemy.emplace_back(10, 100);
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