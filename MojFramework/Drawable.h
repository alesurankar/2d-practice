#pragma once
#include "Vec2.h"
#include <vector>
#include "IndexedLineList.h"


class Drawable
{
public:
	Drawable(float size)
	{
		const float side = size / 2.0f;
		vert2.emplace_back(-side, -side);
		vert2.emplace_back(side, -side);
		vert2.emplace_back(-side, side);
		vert2.emplace_back(side, side);
	}
	IndexedLineList GetLines() const
	{
		return{
			vert2,{
			0,1,  1,3,
			0,2,  2,3 }
		};
	}
private:
	std::vector<Vec2> vert2;
};

