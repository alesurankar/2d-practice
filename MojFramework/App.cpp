#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xRand(30.0f, 670.0f),
	yRand(30.0f, 570.0f),
	dir(-200.0f, 200.0f)
{
	enemy.emplace_back(Vec2{ xRand(rng), yRand(rng) }, Vec2{ dir(rng), dir(rng) });
	player = std::make_unique<Player>(Vec2{ xRand(rng), yRand(rng) });
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
	const float dt = ft.Mark();

	//Player
	player->Update(wnd.kbd, dt);
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
			enemy.emplace_back(Vec2{ xRand(rng), yRand(rng) }, Vec2{ dir(rng), dir(rng) });
			enemySpawnTimeLeft = enemySpawnTime;
		}
	}
	for (auto& e : enemy)
	{
		e.Update(dt);
		e.CheckBorder(); 
		for (auto& b : brick)
		{
			e.HandleCollision(b);
		}
		if (e.CheckCollision(*player))
		{
			e.SetDead();
			score.emplace_back(Vec2{ scoreX, scoreY });
			brick.emplace_back(Vec2{ xRand(rng), yRand(rng) });
			scoreX += 20.0f;
			if (scoreX + 20.0f > Graphics::ScreenWidth)
			{
				scoreX = 0.0f;
				scoreY += 20.0f;
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
	for (auto& s : score)
	{
		objects.push_back(&s);
	}
	for (auto& e : enemy)
	{
		objects.push_back(&e);
	}
	objects.push_back(player.get());
	for (auto& b : brick)
	{
		objects.push_back(&b);
	}
}

void App::EraseObjects()
{
	enemy.erase(
		std::remove_if(enemy.begin(), enemy.end(),
			[&](auto& e)
			{
				return e.DeadCheck();
			}),
		enemy.end());
}

/////////////////////////////////////////////////////////
void App::ComposeFrame()
{
	for (auto* obj : objects)
	{
		obj->Draw(gfx);
	}
}