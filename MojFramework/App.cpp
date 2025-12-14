#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
    scene = std::make_unique<Scene>();
    //calc = std::make_unique<Calculator>(Vei2{ 100, 20 });
    //calc2 = std::make_unique<Calculator>(Vei2{ 330, 100 });
	//osc = std::make_unique<Oscilloscope>();
    //mcuSim = std::make_unique<MCUSimulator>(Vei2(300,300), 14, "Atmega 168");
    //oldMousePos = wnd.mouse.GetPos();
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
        scene->Update(wnd.kbd, wnd.mouse, dt);
        //calc->Update(wnd.mouse, dt);
        //osc->Update(wnd.mouse, dt);
        //mcuSim->Update(wnd.mouse, dt);
        //if (wnd.mouse.LeftIsPressed() && wnd.kbd.KeyIsPressed(VK_CONTROL)) {
        //    int dx = std::abs(wnd.mouse.GetPosX() - oldMousePos.x);
        //    int dy = std::abs(wnd.mouse.GetPosY() - oldMousePos.y);
        //
        //    pixel.emplace_back(wnd.mouse.GetPos(), Colors::Black);
        //    pixel.emplace_back(Vei2(wnd.mouse.GetPosX() + 1, wnd.mouse.GetPosY()), Colors::Black);
        //    pixel.emplace_back(Vei2(wnd.mouse.GetPosX() - 1, wnd.mouse.GetPosY()), Colors::Black);
        //    pixel.emplace_back(Vei2(wnd.mouse.GetPosX(), wnd.mouse.GetPosY()), Colors::Black);
        //    pixel.emplace_back(Vei2(wnd.mouse.GetPosX(), wnd.mouse.GetPosY() + 1), Colors::Black);
        //    pixel.emplace_back(Vei2(wnd.mouse.GetPosX(), wnd.mouse.GetPosY() - 1), Colors::Black);
        //}
    }

    //////////////////////////////
             time += dt;        //
             if(time >= 0.1f) { //
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
    scene->Draw(gfx);
    //calc->Draw(gfx);
    //calc2->Draw(gfx);
	//osc->Draw(gfx);
    //mcuSim->Draw(gfx); 
    //
    //for (auto& p : pixel) {
    //    p.Draw(gfx);
    //}
    //gfx.DrawLine(Vec2(20.0f, 20.0f), Vec2(100.0f, 100.0f), Colors::Black);
}