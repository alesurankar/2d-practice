#pragma once
#include "Vec3.h"
#include <vector>
#include "IndexedList.h"
#include "TexVertex.h"


class Drawable
{
public:
	Drawable(float size)
	{
		const float side = size / 2.0f;
		vert.emplace_back(-side, -side, -side); // 0
		tc.emplace_back(0.0f, 1.0f);
		vert.emplace_back(side, -side, -side); // 1
		tc.emplace_back(1.0f, 1.0f);
		vert.emplace_back(-side, side, -side); // 2
		tc.emplace_back(0.0f, 0.0f);
		vert.emplace_back(side, side, -side); // 3
		tc.emplace_back(1.0f, 0.0f);
		vert.emplace_back(-side, -side, side); // 4
		tc.emplace_back(1.0f, 1.0f);
		vert.emplace_back(side, -side, side); // 5
		tc.emplace_back(0.0f, 1.0f);
		vert.emplace_back(-side, side, side); // 6
		tc.emplace_back(1.0f, 0.0f);
		vert.emplace_back(side, side, side); // 7
		tc.emplace_back(0.0f, 0.0f);
	}
	IndexedTriangleList<TexVertex> GetTrianglesTex() const
	{
		std::vector<TexVertex> tverts;
		tverts.reserve(vert.size());
		for (size_t i = 0; i < vert.size(); i++)
		{
			tverts.emplace_back(vert[i], tc[i]);
		}
		return {
			std::move(tverts),{
			0,2,1, 2,3,1,
			1,3,5, 3,7,5,
			2,6,3, 3,6,7,
			4,5,7, 4,7,6,
			0,4,2, 2,4,6,
			0,1,4, 1,5,4 }
		};
	}
private:
	std::vector<Vec3> vert;
	std::vector<Vec2> tc;
};

