#pragma once
#include <vector>
#include "Vec2.h"


struct IndexedLineList
{
	std::vector<Vec2> vert;
	std::vector<size_t> ind;
};