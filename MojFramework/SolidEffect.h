#pragma once
#include "Pipeline.h"
#include "DefaultVertexShader.h"

// solid color attribute not interpolated
class SolidEffect
{
public:
	// the vertex type that will be input into the pipeline
	class Vertex
	{
	public:
		Vertex() = default;
		Vertex(const Vec3& pos)
			:
			pos(pos)
		{
		}
		Vertex(const Vec3& pos, const Vertex& src)
			:
			color(src.color),
			pos(pos)
		{
		}
		Vertex(const Vec3& pos, const Color& color)
			:
			color(color),
			pos(pos)
		{
		}
		Vertex& operator+=(const Vertex& rhs)
		{
			pos += rhs.pos;
			return *this;
		}
		Vertex operator+(const Vertex& rhs) const
		{
			return Vertex(*this) += rhs;
		}
		Vertex& operator-=(const Vertex& rhs)
		{
			pos -= rhs.pos;
			return *this;
		}
		Vertex operator-(const Vertex& rhs) const
		{
			return Vertex(*this) -= rhs;
		}
		Vertex& operator*=(float rhs)
		{
			pos *= rhs;
			return *this;
		}
		Vertex operator*(float rhs) const
		{
			return Vertex(*this) *= rhs;
		}
		Vertex& operator/=(float rhs)
		{
			pos /= rhs;
			return *this;
		}
		Vertex operator/(float rhs) const
		{
			return Vertex(*this) /= rhs;
		}
	public:
		Vec3 pos;
		Color color;
	};
	// default vs rotates and translates vertices
	// does not touch attributes
	typedef DefaultVertexShader<Vertex> VertexShader;
	// invoked for each pixel of a triangle
	// takes an input of attributes that are the
	// result of interpolating vertex attributes
	// and outputs a color
	class PixelShader
	{
	public:
		template<class I>
		Color operator()(const I& in) const
		{
			return in.color;
		}
		//Color operator()(const I& in) const
		//{
		//	// simple XYZ -> RGB mapping
		//	float r = (in.pos.x + 1.0f) * 0.5f; // map -1..1 to 0..1
		//	float g = (in.pos.y + 1.0f) * 0.5f;
		//	float b = (in.pos.z + 1.0f) * 0.5f;
		//	return Color(r, g, b);
		//}
		/*Color operator()(const I& in) const
		{
			int checkX = int(floor(in.pos.x * 5));
			int checkY = int(floor(in.pos.y * 5));
			if ((checkX + checkY) % 2 == 0)
				return Colors::White;
			else
				return Colors::Black;
		}*/
	};
public:
	VertexShader vs;
	PixelShader ps;
};