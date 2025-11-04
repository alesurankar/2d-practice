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
	brick.emplace_back(Location{ xRand(rng), yRand(rng) });
	enemy.emplace_back(Location{ xRand(rng), yRand(rng) }, dir(rng), dir(rng));
	player = std::make_unique<Player>(Location{ xRand(rng), yRand(rng) });
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
	for (auto& b : brick)
	{
		player->HandleCollision(b);
	}
	//Enemy
	if (enemy.size() < enemyNum)
	{
		enemySpawnTimeLeft--;
		if (enemySpawnTimeLeft <= 0)
		{
			enemy.emplace_back(Location{ xRand(rng), yRand(rng) }, dir(rng), dir(rng));
			enemySpawnTimeLeft = enemySpawnTime;
		}
	}
	for (Enemy& e : enemy)
	{
		e.Update();
		e.CheckBorder(); 
		for (auto& b : brick)
		{
			e.HandleCollision(b);
		}
		if (e.CheckCollision(*player))
		{
			e.SetDead();
			score.emplace_back(Location{ scoreX, scoreY });
			brick.emplace_back(Location{ xRand(rng), yRand(rng) });
			scoreX += 20;
			if (scoreX + 20 > Graphics::ScreenWidth)
			{
				scoreX = 0;
				scoreY += 20;
			}
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
	objects.reserve(score.size() + enemy.size() + 1 + brick.size());
	for (Score& s : score)
	{
		objects.push_back(&s);
	}
	for (Enemy& e : enemy)
	{
		objects.push_back(&e);
	}
	objects.push_back(player.get());
	for (Brick& b : brick)
	{
		objects.push_back(&b);
	}
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