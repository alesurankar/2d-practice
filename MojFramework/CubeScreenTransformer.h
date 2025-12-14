#pragma once
#include "Vec2.h"
#include "Graphics.h"

class CubeScreenTransformer
{
public:
	CubeScreenTransformer()
		:
		xFactor(float(Graphics::ScreenWidth) / 2.0f),
		yFactor(float(Graphics::ScreenHeight) / 2.0f)
	{
	}

	Vec2& Transform(Vec2& v) const
	{
		v.x = (v.x + 1.0f) * xFactor;
		v.y = (-v.y + 1.0f) * yFactor;
		return v;
	}
private:
	float xFactor;
	float yFactor;
};