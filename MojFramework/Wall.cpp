#include "Wall.h"

Wall::Wall(Graphics& gfx)
	:
	gfx(gfx)
{}

void Wall::DrawBrick(Location & loc, Color c)
{
	for (int i = (loc.x * dimension); i < (loc.x * dimension) + dimension; i++)
	{
		for (int j = (loc.y * dimension); j < (loc.y * dimension) + dimension; j++)
		{
			gfx.PutPixel(i, j, c);
		}
	}
}

int Wall::GetGridWidth() const
{
	return width;
}

int Wall::GetGridHeight() const
{
	return height;
}
