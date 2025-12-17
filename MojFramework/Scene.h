#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "TestObject.h"
#include "Vec2.h"
#include "Pipeline.h"
#include <memory>

class Scene
{
public:
	Scene(Graphics& gfx)
		:
		pipeline(gfx)
	{
		obj1 = std::make_unique<TestObject>(gfx, Vec3(0.1f, 0.1f, 3.2f));// , "Images\\stonewall.bmp");
		obj1->Move(0.0f, 0.0f, 0.0f);
		obj1->Rotate(0.0f, 0.0f, 0.0f);
		obj2 = std::make_unique<TestObject>(gfx, Vec3(0.1f,0.1f, 3.2f));//, "Images\\floor.bmp");
		obj2->SetVelocity(0.01f, -0.01f, 0.005f);
		obj2->SetTorque(0.01f, -0.01f, 0.008f);
		obj3 = std::make_unique<TestObject>(gfx, Vec3(-0.2f,-0.3f, 3.2f));//, "Images\\ceiling.bmp");
		obj3->SetVelocity(-0.01f, 0.01f, -0.008f);
		obj3->SetTorque(-0.01f, 0.01f, -0.004f);
		obj4 = std::make_unique<TestObject>(gfx, Vec3(-0.1f, 0.2f, 3.2f));//, "Images\\wood.bmp");
		obj4->SetVelocity(0.001f, 0.02f, -0.007f);
		obj4->SetTorque(0.001f, 0.02f, -0.006f);
		obj5 = std::make_unique<TestObject>(gfx, Vec3(-0.2f, 0.2f, 3.2f));//, "Images\\wall.bmp");
		obj5->SetVelocity(0.02f, -0.001f, -0.006f);
		obj5->SetTorque(0.02f, -0.001f, -0.003f);
		obj6 = std::make_unique<TestObject>(gfx, Vec3(-0.1f, 0.2f, 2.2f));//, "Images\\office_skin.bmp");
		obj6->SetVelocity(-0.05f, 0.015f, -0.002f);
		obj6->SetTorque(-0.015f, 0.05f, -0.004f);
		obj7 = std::make_unique<TestObject>(gfx, Vec3(-0.3f, 0.2f, 3.0f));//, "Images\\office_skin_lores.bmp");
		obj7->SetVelocity(0.01f, 0.007f, -0.01f);
		obj7->SetTorque(0.006f, 0.01f, -0.003f);
	}
	
	void Update(const Keyboard& kbd, Mouse& mouse, float dt)
	{
		float speed = dt/2;
		if (kbd.KeyIsPressed(VK_SHIFT)) {
			speed = 2*dt;
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
		if (kbd.KeyIsPressed(VK_SPACE)) {
			obj1->Move(0.0f, 0.0f, speed);
		}
		if (kbd.KeyIsPressed(VK_CONTROL)) {
			obj1->Move(0.0f, 0.0f, -speed);
		}
		/*while (!mouse.IsEmpty())
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
		}*/
		if (kbd.KeyIsPressed('Q')) {
			obj1->Rotate(0.0f, 0.0f, speed);
		}
		if (kbd.KeyIsPressed('E')) {
			obj1->Rotate(0.0f, 0.0f, -speed);
		}
		obj2->Move();
		obj2->Rotate();
		obj3->Move();
		obj3->Rotate();
		obj4->Move();
		obj4->Rotate();
		obj5->Move();
		obj5->Rotate();
		obj6->Move();
		obj6->Rotate();
		obj7->Move();
		obj7->Rotate();
	}

	void Draw()
	{
		pipeline.BeginFrame();
		BindAndDraw(*obj1);
		BindAndDraw(*obj2);
		BindAndDraw(*obj3);
		BindAndDraw(*obj4);
		BindAndDraw(*obj5);
		BindAndDraw(*obj6);
		BindAndDraw(*obj7);
	}

private:
	void BindAndDraw(const TestObject& obj)
	{
		const Mat3 rot =
			Mat3::RotationX(obj.GetOrnt().x) *
			Mat3::RotationY(obj.GetOrnt().y) *
			Mat3::RotationZ(obj.GetOrnt().z);

		const Vec3 trans = { obj.GetPos().x,obj.GetPos().y,obj.GetPos().z };

		pipeline.BindRotation(rot);
		pipeline.BindTranslation(trans);

		pipeline.Draw(obj.GetTriangle());
	}
private:
	Pipeline<SolidEffect> pipeline;
	std::unique_ptr<TestObject> obj1;
	std::unique_ptr<TestObject> obj2;
	std::unique_ptr<TestObject> obj3;
	std::unique_ptr<TestObject> obj4;
	std::unique_ptr<TestObject> obj5;
	std::unique_ptr<TestObject> obj6;
	std::unique_ptr<TestObject> obj7;
};