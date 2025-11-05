#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "Brick.h"
#include "FrameTimer.h"
#include <memory>
#include <vector>
#include <random>

class App {
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
	FrameTimer ft;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xRand;
	std::uniform_real_distribution<float> yRand;
	std::uniform_real_distribution<float> dir;
	std::vector<GameObject*> objects;
	std::unique_ptr<Player> player;
	std::vector<Enemy> enemy;
	std::vector<Score> score;
	std::vector<Brick> brick;
	int enemyNum = 30;
	static constexpr int enemySpawnTime = 30;
	int enemySpawnTimeLeft;
	int collision;
	float scoreX = 0.0f;
	float scoreY = 0.0f;
};