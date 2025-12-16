#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "TestObject.h"
#include "Vec2.h"
#include <memory>

class Scene
{
public:
	Scene(Graphics& gfx)
	{
		obj1 = std::make_unique<TestObject>(gfx, Vec3(0.1f,0.1f, 3.2f), "Images\\stonewall.bmp");
		obj1->SetVelocity(Vec3(0.0f, 0.0f, 0.0f));
		obj2 = std::make_unique<TestObject>(gfx, Vec3(0.1f,0.1f, 3.2f), "Images\\floor.bmp");
		obj2->SetVelocity(Vec3(0.01f, -0.01f, 0.004f));
		obj3 = std::make_unique<TestObject>(gfx, Vec3(-0.2f,-0.3f, 3.2f), "Images\\ceiling.bmp");
		obj3->SetVelocity(Vec3(-0.01f, 0.01f, -0.004f));
		obj4 = std::make_unique<TestObject>(gfx, Vec3(-0.1f, 0.2f, 3.2f), "Images\\wood.bmp");
		obj4->SetVelocity(Vec3(0.01f, 0.01f, -0.003f));
		obj5 = std::make_unique<TestObject>(gfx, Vec3(-0.2f, 0.2f, 3.2f), "Images\\wall.bmp");
		obj5->SetVelocity(Vec3(0.01f, -0.01f, -0.003f));
		obj6 = std::make_unique<TestObject>(gfx, Vec3(-0.1f, 0.2f, 2.2f), "Images\\office_skin.bmp");
		obj6->SetVelocity(Vec3(-0.01f, 0.01f, -0.003f));
		obj7 = std::make_unique<TestObject>(gfx, Vec3(-0.3f, 0.2f, 3.0f), "Images\\office_skin_lores.bmp");
		obj7->SetVelocity(Vec3(0.01f, 0.01f, -0.003f));
	}
	void Update(const Keyboard& kbd, Mouse& mouse, float dt)
	{
		float speed = dt/2;
		if (kbd.KeyIsPressed(VK_SPACE)) {
			speed = dt;
		}
		if (kbd.KeyIsPressed('W')) {
			obj1->Move(0.0f, speed, 0.0f);
		}
		if (kbd.KeyIsPressed('S')) {
			obj1->Move(0.0f, -speed, 0.0f);
		}
		if (kbd.KeyIsPressed('A')) {
			obj1->Move(-speed, 0.0f, 0.0f);
		}
		if (kbd.KeyIsPressed('D')) {
			obj1->Move(speed, 0.0f, 0.0f);
		}
		
		while (!mouse.IsEmpty())
		{
			Mouse::Event e = mouse.Read();
		
			switch (e.GetType())
			{
			case Mouse::Event::Type::WheelUp:
				obj1->Move(0.0f, 0.0f, speed);
				break;
		
			case Mouse::Event::Type::WheelDown:
				obj1->Move(0.0f, 0.0f, -speed);
				break;
			}
		}
		if (kbd.KeyIsPressed('Q')) {
			obj1->Rotate(0.0f, 0.0f, speed);
		}
		if (kbd.KeyIsPressed('E')) {
			obj1->Rotate(0.0f, 0.0f, -speed);
		}
		obj2->Move();
		obj3->Move();
		obj4->Move();
		obj5->Move();
		obj6->Move();
		obj7->Move();
	}
	void Draw() const
	{
		obj1->Draw();
		obj2->Draw();
		obj3->Draw();
		obj4->Draw();
		obj5->Draw();
		obj6->Draw();
		obj7->Draw();
	}
private:
	std::unique_ptr<TestObject> obj1;
	std::unique_ptr<TestObject> obj2;
	std::unique_ptr<TestObject> obj3;
	std::unique_ptr<TestObject> obj4;
	std::unique_ptr<TestObject> obj5;
	std::unique_ptr<TestObject> obj6;
	std::unique_ptr<TestObject> obj7;
};