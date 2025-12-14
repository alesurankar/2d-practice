#pragma once
#include "Drawable.h"
#include "CubeScreenTransformer.h"
#include "Graphics.h"
#include "Vec2.h"
#include "Mat.h"
#include <memory>

class TestObject
{
public:
	TestObject(const Vec3& pos_in)
		:
		pos(pos_in)
	{
		rct = std::make_unique<Drawable>(0.4f); 

		Update();
	}
	void Move(float x, float y, float z)
	{
		pos.x += x;
		pos.y += y;
		pos.z += z;
	}
	void Rotate(float x, float y, float z)
	{
		ornt.x = wrap_angle(ornt.x + x);
		ornt.y = wrap_angle(ornt.y + y);
		ornt.z = wrap_angle(ornt.z + z);
	}
	void Update()
	{
		rot =
			Mat3::RotationX(ornt.x) *
			Mat3::RotationY(ornt.y) *
			Mat3::RotationZ(ornt.z);

		lines = rct->GetLines();
		for (auto& v : lines.vert)
		{
			v *= rot;
			v.x += pos.x;
			v.y += pos.y;
			v.z += pos.z;
			cst.Transform(v);
		}
	}
	void Draw(Graphics& gfx)
	{
		for (auto i = lines.ind.cbegin(),
			end = lines.ind.cend();
			i != end; std::advance(i, 2))
		{
			gfx.DrawLine(lines.vert[*i], lines.vert[*std::next(i)], Colors::White);
		}
	}
private:
	Vec3 pos;
	CubeScreenTransformer cst;
	IndexedLineList lines; 
	Mat3 rot;
	std::unique_ptr<Drawable> rct;
	static constexpr float dTheta = PI;
	Vec3 ornt;
};