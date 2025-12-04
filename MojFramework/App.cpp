#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	//osc = std::make_unique<Oscilloscope>();
    mcuSim = std::make_unique<MCUSimulator>(Vei2(300,300), 14, "Atmega 168");
}

void App::Go()
{
    float dt = ft.Mark();
    if (UpdateModel(dt))
    {
        gfx.BeginFrame(Colors::MakeRGB(90, 90, 90));
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
        //osc->Update(wnd.mouse, dt);
        mcuSim->Update(wnd.mouse, dt);

        if (wnd.mouse.LeftIsPressed() && wnd.kbd.KeyIsPressed(VK_CONTROL)) {
            pixel.emplace_back(wnd.mouse.GetPos(), Colors::Black);
            pixel.emplace_back(Vei2(wnd.mouse.GetPosX() + 1, wnd.mouse.GetPosY()), Colors::Black);
            pixel.emplace_back(Vei2(wnd.mouse.GetPosX(), wnd.mouse.GetPosY() + 1), Colors::Black);
            pixel.emplace_back(Vei2(wnd.mouse.GetPosX() + 1, wnd.mouse.GetPosY() + 1), Colors::Black);
        }
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
	//osc->Draw(gfx);
    mcuSim->Draw(gfx); 
    
    for (auto& p : pixel) {
        p.Draw(gfx);
    }
}