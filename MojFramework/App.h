#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Fonts.h"
#include <vector>

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
	Fonts smallFont = Fonts("Images\\Fonts8x14.bmp");
};