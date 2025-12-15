#pragma once
#include "Drawable.h"
#include "CubeScreenTransformer.h"
#include "Graphics.h"
#include "Vec2.h"
#include "Mat.h"
#include <memory>

class TestObject
{
public:
	enum class TYPE {
		SKELETON,
		FILLED,
		COLORED
	};
	TestObject(const Vec3& pos_in, TYPE type_in, const Vec3 ornt_in = { 0.0f,0.0f,0.0f });
	void Move(float x, float y, float z);
	void Rotate(float x, float y, float z);
	void Update();
	void Draw(Graphics& gfx);
private:
	void TransformVertices(std::vector<Vec3>& verts, const Mat3& rot);
	void DrawWithLines(Graphics& gfx);
	void DrawWithTriangles(Graphics& gfx);
	void DrawWithColoredTriangles(Graphics& gfx);
private:
	Color colors[12] = {
		Colors::White,
		Colors::Blue,
		Colors::Cyan,
		Colors::Gray,
		Colors::Green,
		Colors::Magenta,
		Colors::LightGray,
		Colors::Red,
		Colors::Yellow,
		Colors::White,
		Colors::Blue,
		Colors::Cyan
	};
	Vec3 pos;
	TYPE type;
	Vec3 ornt;
	CubeScreenTransformer cst;
	IndexedLineList lines; 
	IndexedTriangleList triangles;
	Mat3 rot;
	std::unique_ptr<Drawable> rct;
};