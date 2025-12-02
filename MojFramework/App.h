#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Fonts.h"
#include "Vec2.h"
#include "Menu.h"
#include "Signal.h"
#include <memory>

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
	std::unique_ptr<Menu> menu;
	std::unique_ptr<Signal> signal;
};