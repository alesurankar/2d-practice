#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Pad.h"
#include "Ball.h"
#include "Brick.h"
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
private:
	MainWindow& wnd;
	Graphics gfx;
	FrameTimer ft;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xRand;
	std::uniform_int_distribution<int> yRand;
	std::uniform_real_distribution<float> dir;
	std::unique_ptr<Pad> pad;
	std::unique_ptr<Ball> ball;
	std::vector<Brick> brick;
};