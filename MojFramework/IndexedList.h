#pragma once
#include <vector>
#include "Vec3.h"
#include <cassert>
#include <utility>


struct IndexedLineList
{
	std::vector<Vec3> vert;
	std::vector<size_t> ind;
};

struct IndexedTriangleList
{
	IndexedTriangleList(std::vector<Vec3> verts_in, std::vector<size_t> indices_in)
		:
		vert(std::move(verts_in)),
		ind(std::move(indices_in))
	{
		assert(vert.size() > 2);
		assert(ind.size() % 3 == 0);
		cullFlags.resize(ind.size() / 3, false);
	}
	std::vector<Vec3> vert;
	std::vector<size_t> ind;
	std::vector<bool> cullFlags;
};