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
	Scene()
	{
		obj1 = std::make_unique<TestObject>(Vec3(0.1f,0.1f, 3.2f), TestObject::TYPE::COLORED);
		obj1->SetVelocity(Vec3(0.0f, 0.0f, 0.0f));
		obj2 = std::make_unique<TestObject>(Vec3(0.1f,0.1f, 3.2f), TestObject::TYPE::SKELETON);
		obj2->SetVelocity(Vec3(0.01f, -0.01f, 0.004f));
		obj3 = std::make_unique<TestObject>(Vec3(-0.2f,-0.3f, 3.2f), TestObject::TYPE::FILLED);
		obj3->SetVelocity(Vec3(-0.01f, 0.01f, -0.004f));
		obj4 = std::make_unique<TestObject>(Vec3(-0.1f, 0.2f, 3.2f), TestObject::TYPE::TEXTURED);
		obj4->SetVelocity(Vec3(0.01f, 0.01f, -0.003f));
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
	}
	void Draw(Graphics& gfx) const
	{
		obj1->Draw(gfx);
		obj2->Draw(gfx);
		obj3->Draw(gfx);
		obj4->Draw(gfx);
	}
private:
	std::unique_ptr<TestObject> obj1;
	std::unique_ptr<TestObject> obj2;
	std::unique_ptr<TestObject> obj3;
	std::unique_ptr<TestObject> obj4;
};