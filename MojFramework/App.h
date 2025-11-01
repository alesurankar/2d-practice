#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

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
private:
	MainWindow& wnd;
	Graphics gfx;
	int x = 200;
	int y = 200;
	int width = 12;
	int height = 12;
	Color color;
};