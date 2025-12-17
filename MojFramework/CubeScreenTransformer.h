#pragma once
#include "Vec3.h"
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
	template<class Vertex>
	Vertex& Transform(Vertex& v) const
	{
		const float zInv = 1.0f / v.pos.z;
		v *= zInv;
		v.pos.x = (v.pos.x + 1.0f) * xFactor;
		v.pos.y = (-v.pos.y + 1.0f) * yFactor;
		v.pos.z = zInv;
		return v;
	}
private:
	float xFactor;
	float yFactor;
};