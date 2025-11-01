#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Player.h"
#include "Enemy.h"
#include <memory>
#include <vector>

class App
{
public:
	App(class MainWindow& wnd);
	App(const App&) = delete;
	App& operator=(const App&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void UpdatePlayer();
	void UpdateEnemy();
private:
	MainWindow& wnd;
	Graphics gfx;
	std::vector<GameObject*> objects;
	std::unique_ptr<Player> player;
	std::vector<Enemy> enemy;
};