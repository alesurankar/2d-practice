#pragma once
#include "Drawable.h"
#include "CubeScreenTransformer.h"
#include "Graphics.h"
#include "Vec2.h"
#include "Mat.h"
#include "Pipeline.h"
#include <memory>

class TestObject
{
public:
	typedef Pipeline::Vertex Vertex;
	TestObject(Graphics& gfx, const Vec3& pos_in, const std::string& filename ,const Vec3& ornt_in = { 0.0f,0.0f,0.0f });
	void Move(float x, float y, float z);
	void Move();
	void Rotate(float x, float y, float z);
	void Draw();
	Vec3 GetPos() const;
	void SetVelocity(const Vec3& vel);
private:
	void Update();
	void CheckBorder();
private:
	Vec3 pos;
	Vec3 ornt;
	Vec3 vel;
	IndexedTriangleList<Vertex> itlist;
	IndexedTriangleList<Vertex> triangles;
	Pipeline pipeline;
};