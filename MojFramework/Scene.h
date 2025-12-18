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
		objects.emplace_back(std::make_unique<TestObject>(gfx, Vec3(0.1f, 0.1f, 3.2f), "Images\\stonewall.bmp"));
		objects[0]->Move(0.0f, 0.0f, 0.0f);
		objects[0]->Rotate(0.0f, 0.0f, 0.0f);
		player = objects.back().get();
		objects.emplace_back(std::make_unique<TestObject>(gfx, Vec3(0.1f,0.1f, 5.0f), "Images\\floor.bmp"));
		objects[1]->SetVelocity(0.01f, -0.01f, 0.005f); 
		objects[1]->SetTorque(0.01f, -0.01f, 0.008f);
		objects.emplace_back(std::make_unique<TestObject>(gfx, Vec3(-0.2f,-0.3f, 7.0f), "Images\\ceiling.bmp"));
		objects[2]->SetVelocity(-0.01f, 0.01f, -0.008f);
		objects[2]->SetTorque(-0.01f, 0.01f, -0.004f);
		objects.emplace_back(std::make_unique<TestObject>(gfx, Vec3(-0.1f, 0.2f, 9.0f), "Images\\wood.bmp"));
		objects[3]->SetVelocity(0.001f, 0.02f, -0.007f);
		objects[3]->SetTorque(0.001f, 0.02f, -0.006f);
		objects.emplace_back(std::make_unique<TestObject>(gfx, Vec3(-0.2f, 0.2f, 11.0f), "Images\\wall.bmp"));
		objects[4]->SetVelocity(0.02f, -0.001f, -0.006f);
		objects[4]->SetTorque(0.02f, -0.001f, -0.003f);
		objects.emplace_back(std::make_unique<TestObject>(gfx, Vec3(-0.1f, 0.2f, 13.0f), "Images\\office_skin.bmp"));
		objects[5]->SetVelocity(-0.05f, 0.015f, -0.002f);
		objects[5]->SetTorque(-0.015f, 0.05f, -0.004f);
		objects.emplace_back(std::make_unique<TestObject>(gfx, Vec3(-0.3f, 0.2f, 15.0f), "Images\\office_skin_lores.bmp"));
		objects[6]->SetVelocity(0.01f, 0.007f, -0.01f);
		objects[6]->SetTorque(0.006f, 0.01f, -0.003f);
	}
	
	void Update(const Keyboard& kbd, Mouse& mouse, float dt)
	{
		float speed = dt/2;
		if (kbd.KeyIsPressed(VK_SPACE)) {
			speed = 2*dt;
		}
		if (kbd.KeyIsPressed('W')) {
			player->Move(0.0f, speed, 0.0f);
		}
		if (kbd.KeyIsPressed('S')) {
			player->Move(0.0f, -speed, 0.0f);
		}
		if (kbd.KeyIsPressed('A')) {
			player->Move(-speed, 0.0f, 0.0f);
		}
		if (kbd.KeyIsPressed('D')) {
			player->Move(speed, 0.0f, 0.0f);
		}
		if (kbd.KeyIsPressed(VK_SHIFT)) {
			player->Move(0.0f, 0.0f, speed);
		}
		if (kbd.KeyIsPressed(VK_CONTROL)) {
			player->Move(0.0f, 0.0f, -speed);
		}
		/*while (!mouse.IsEmpty())
		{
			Mouse::Event e = mouse.Read();
		
			switch (e.GetType())
			{
			case Mouse::Event::Type::WheelUp:
				player->Move(0.0f, 0.0f, speed);
				break;
		
			case Mouse::Event::Type::WheelDown:
				player->Move(0.0f, 0.0f, -speed);
				break;
			}
		}*/
		if (kbd.KeyIsPressed('Q')) {
			player->Rotate(0.0f, 0.0f, speed);
		}
		if (kbd.KeyIsPressed('E')) {
			player->Rotate(0.0f, 0.0f, -speed);
		}
		for (auto& obj : objects) {
			if (obj.get() != player) {
				obj->Move();
				obj->Rotate();
			}
		}
		CheckCollisions();
	}

	void Draw()
	{
		pipeline.BeginFrame();
		for (auto& obj : objects) {
			BindAndDraw(*obj);
		}
	}

private:
	void CheckCollisions()
	{
		for (size_t i = 0; i < objects.size(); i++)
		{
			for (size_t j = i + 1; j < objects.size(); j++)
			{
				if (objects[i]->GetWorldBoundingBox()
					.IsOverlappingWith(objects[j]->GetWorldBoundingBox()))
				{
					objects[i]->ChangeVelocity();
					objects[i]->ChangeTorque();
					objects[j]->ChangeVelocity();
					objects[j]->ChangeTorque();
				}
			}
		}
	}
	void BindAndDraw(const TestObject& obj)
	{
		pipeline.effect.ps.BindTexture(obj.GetTexture());
		const Mat3 rot =
			Mat3::RotationX(obj.GetOrnt().x) *
			Mat3::RotationY(obj.GetOrnt().y) *
			Mat3::RotationZ(obj.GetOrnt().z);

		const Vec3 trans = { obj.GetPos().x,obj.GetPos().y,obj.GetPos().z };

		pipeline.effect.vs.BindRotation(rot);
		pipeline.effect.vs.BindTranslation(trans);

		pipeline.Draw(obj.GetTriangle());
	}
private:
	Pipeline<TextureEffect> pipeline;
	std::vector<std::unique_ptr<TestObject>> objects;
	TestObject* player = nullptr;
};