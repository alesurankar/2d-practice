#pragma once
#include <vector>
#include "Vec3.h"


struct IndexedLineList
{
	std::vector<Vec3> vert;
	std::vector<size_t> ind;
};