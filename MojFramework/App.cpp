#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	menu = std::make_unique<Menu>(Menu::MenuType::IN_APP);
}

void App::Go()
{
	gfx.BeginFrame(Colors::DarkGray);
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame(1);
}

////////////////////////////////////////////////////////////
void App::UpdateModel()
{
//	dots.emplace_back(headX, y);
//
//	//pos = dots.front();
//	x++;
//	if (rising && !falling) {
//		y--;
//	}
//	if (!rising && falling) {
//		y++;
//	}
//	if ((y > (Graphics::ScreenHeight / 2) + 20)) {
//		rising = true;
//		falling = false;
//	}
//	else if (y < (Graphics::ScreenHeight / 2) - 20) {
//		rising = false;
//		falling = true;
//	}
//	// remove off-screen dots
//	if (!dots.empty() && dots.front().x < 0) {
//		dots.erase(dots.begin());
//	}
//	for (auto& dot : dots)
//	{
//		dot.x--;
//	}
//	//dots.pop();

	const int headX = Graphics::ScreenWidth - 1;    // newest dot is always on right
	dots.emplace_back(headX, y);
	
	// vertical square wave
	if (rising && !falling) {
	    y--;
	}
	if (!rising && falling) {
	    y++;
	}
	
	const int mid = Graphics::ScreenHeight / 2;
	if (y > mid + 20) {
	    rising = true;
	    falling = false;
	}
	else if (y < mid - 20) {
	    rising = false;
	    falling = true;
	}
	
	// scroll left
	for (auto& dot : dots) {
	    dot.x -= 2;     // scroll speed
	}
	
	// remove off-screen dots
	if (!dots.empty() && dots.front().x < 0) {
	    dots.erase(dots.begin());
	}
	menu->Update(wnd.mouse);
}


/////////////////////////////////////////////////////////
void App::ComposeFrame()
{
	for (auto& dot : dots)
	{
		gfx.PutPixel(dot, Colors::White);
	}
	menu->Draw(gfx);
}