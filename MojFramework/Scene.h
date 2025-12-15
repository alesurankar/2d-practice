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
		obj1 = std::make_unique<TestObject>(Vec3(0.1f,0.1f, 1.0f), TestObject::TYPE::FILLED);
		obj2 = std::make_unique<TestObject>(Vec3(0.1f,0.1f, 1.0f), TestObject::TYPE::SKELETON);
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
		obj1->Update();
		obj2->Update();
	}
	void Draw(Graphics& gfx) const
	{
		obj1->Draw(gfx);
		obj2->Draw(gfx);
	}
private:
	std::unique_ptr<TestObject> obj1;
	std::unique_ptr<TestObject> obj2;
};