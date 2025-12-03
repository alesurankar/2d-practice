#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Fonts.h"
#include "Vec2.h"
#include "Oscilloscope.h"
#include "FrameTimer.h"
#include <memory>

class App {
public:
	App(class MainWindow& wnd);
	App(const App&) = delete;
	App& operator=(const App&) = delete;
	void Go();
private:
	bool UpdateModel(float dt);
	void ComposeFrame();
private:
	MainWindow& wnd;
	Graphics gfx;
	FrameTimer ft; 
	float time = 0.0f;
	std::unique_ptr<Oscilloscope> osc;
};