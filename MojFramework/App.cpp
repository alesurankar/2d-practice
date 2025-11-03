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
	enemy.emplace_back(xRand(rng), yRand(rng), dir(rng), dir(rng));
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
	//Player
	player->Update(wnd.kbd);
	player->CheckBorder();

	//Enemy
	if (enemy.size() < enemyNum)
	{
		enemySpawnTimeLeft--;
		if (enemySpawnTimeLeft <= 0)
		{
			enemy.emplace_back(xRand(rng), yRand(rng), dir(rng), dir(rng));
			enemySpawnTimeLeft = enemySpawnTime;
		}
	}
	for (Enemy& e : enemy)
	{
		e.Update();
		e.CheckBorder(); 
		if (e.CheckCollision(*player))
		{
			e.SetDead();
			score.emplace_back(xRand(rng), yRand(rng));
			collision = 0;
		}
	}
	if (collision < 100)
	{
		player->ChangeColor(Colors::Blue);
	}
	else
	{
		player->ChangeColor(Colors::Yellow);
	}
	collision++;
	UpdateObjects();
}

void App::UpdateObjects()
{
	EraseObjects();
	objects.clear();
	objects.reserve(score.size() + enemy.size() + 1);
	for (Score& s : score)
	{
		objects.push_back(&s);
	}
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
				return e.DeadCheck();
			}),
		enemy.end());
}

/////////////////////////////////////////////////////////
void App::ComposeFrame()
{
	for (GameObject* obj : objects)
	{
		obj->Draw(gfx);
	}
}