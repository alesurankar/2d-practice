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
	TestObject(const Vec3& pos_in, TYPE type_in, const Vec3& ornt_in = { 0.0f,0.0f,0.0f });
	void Move(float x, float y, float z);
	void Move();
	void Rotate(float x, float y, float z);
	void Draw(Graphics& gfx);
	Vec3 GetPos() const;
	void SetVelocity(const Vec3& vel);
private:
	void Update();
	void CheckBorder();
	void TransformToWorldSpace(std::vector<Vec3>& verts, const Mat3& rot);
	void TransformToScreenSpace(std::vector<Vec3>& verts);
	void BackfaceCulling();
	void DrawLines(Graphics& gfx);
	void DrawTriangles(Graphics& gfx);
	void DrawColoredTriangles(Graphics& gfx);
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
	Vec3 vel;
	std::unique_ptr<Drawable> rct;
	IndexedLineList modelLines;
	IndexedLineList lines;
	IndexedTriangleList modelTriangles;
	IndexedTriangleList triangles;
	CubeScreenTransformer cst;
	Mat3 rot;
};