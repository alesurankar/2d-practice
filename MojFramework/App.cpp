#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	osc = std::make_unique<Oscilloscope>();
}

void App::Go()
{
    float dt = ft.Mark();
    if (UpdateModel(dt))
    {
        gfx.BeginFrame(Colors::DarkGray);
        ComposeFrame();
        gfx.EndFrame(1);
    }
    else
    {
        Sleep(1);
    }
}

////////////////////////////////////////////////////////////
bool App::UpdateModel(float dt)
{
    {
        osc->Update(wnd.kbd, wnd.mouse, dt);
    }

    //////////////////////////////
             time += dt;        //
             if(time >= 0.0f) { //
                 time = 0.0f;   //
                 return true;   //
             }                  //
             else {             //
                 return false;  //
             }                  //
    //////////////////////////////
}


/////////////////////////////////////////////////////////
void App::ComposeFrame()
{
	osc->Draw(gfx);
}