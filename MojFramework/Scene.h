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
		obj1 = std::make_unique<TestObject>(Vec2(0.1f,0.1f));
		obj2 = std::make_unique<TestObject>(Vec2(0.1f,0.1f));
	}
	void Update(const Keyboard& kbd, const Mouse& mouse, float dt)
	{
		float speed = dt/2;
		if (kbd.KeyIsPressed(VK_SPACE)) {
			speed = dt;
		}
		if (kbd.KeyIsPressed('W')) {
			obj1->Move(0.0f, speed);
		}
		if (kbd.KeyIsPressed('S')) {
			obj1->Move(0.0f, -speed);
		}
		if (kbd.KeyIsPressed('A')) {
			obj1->Move(-speed, 0.0f);
		}
		if (kbd.KeyIsPressed('D')) {
			obj1->Move(speed, 0.0f);
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