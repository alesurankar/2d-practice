#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "Wall.h"
#include <memory>
#include <vector>
#include <random>

class App
{
public:
	App(class MainWindow& wnd);
	App(const App&) = delete;
	App& operator=(const App&) = delete;
	void Go();
private:
	void UpdateModel();
	void ComposeFrame();
	void UpdateObjects();
	void EraseObjects();
private:
	MainWindow& wnd;
	Graphics gfx;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xRand;
	std::uniform_int_distribution<int> yRand;
	std::uniform_int_distribution<int> dir;
	std::vector<GameObject*> objects;
	std::unique_ptr<Player> player;
	std::vector<Enemy> enemy;
	std::vector<Score> score;
	Wall wall;
	int enemyNum = 30;
	static constexpr int enemySpawnTime = 30;
	int enemySpawnTimeLeft;
	int collision;
	int scoreX = 0;
	int scoreY = 0;
};