#pragma once
#include "Drawable.h"
#include "CubeScreenTransformer.h"
#include "Graphics.h"
#include "Vec2.h"
#include <memory>

class TestObject
{
public:
	TestObject(const Vec2& pos_in)
		:
		pos(pos_in)
	{
		rct = std::make_unique<Drawable>(0.4f);
	}
	void Move(float x, float y)
	{
		pos.x += x;
		pos.y += y;
	}
	void Update()
	{
		lines = rct->GetLines();
		for (auto& v : lines.vert)
		{
			v += {pos.x, pos.y};
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
	Vec2 pos;
	CubeScreenTransformer cst;
	IndexedLineList lines;
	std::unique_ptr<Drawable> rct;
};