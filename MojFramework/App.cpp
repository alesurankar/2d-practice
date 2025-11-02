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
	for (int n = 0; n < enemyNum; n++)
	{
		enemy.emplace_back(xRand(rng), yRand(rng), dir(rng), dir(rng));
	}
	player = std::make_unique<Player>(xRand(rng), yRand(rng));
	collision = 100;
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
	objects.clear();
	objects.reserve(enemy.size() + 1);
	UpdateEnemy();
	UpdatePlayer();
	UpdateObjects();
}

void App::ComposeFrame()
{
	for (GameObject* obj : objects)
	{
		obj->Draw(gfx);
	}
}
/////////////////////////////////////////////////////////

void App::UpdatePlayer()
{
	player->Update(wnd.kbd);
	player->CheckBorder();
	if (collision < 100)
	{
		player->ChangeColor(Colors::Blue);
	}
	else
	{
		player->ChangeColor(Colors::Yellow);
	}
	collision++;
}

void App::UpdateEnemy()
{
	for (Enemy& e : enemy)
	{
		e.Update();
		e.CheckBorder();
		if (e.CheckCollision(*player))
		{
			collision = 0;
		}
		objects.push_back(&e);
	}
}

void App::UpdateObjects()
{
	EraseObjects();
	for (Enemy& e : enemy)
	{
		objects.push_back(&e);
	}
	objects.push_back(player.get());
}

void App::EraseObjects()
{
	enemy.erase(
		std::remove_if(enemy.begin(), enemy.end(),
			[&](Enemy& e)
			{
				if (e.CheckCollision(*player))
				{
					return true;
				}
				return false;
			}),
			enemy.end());
}