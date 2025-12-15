#include "TestObject.h"


TestObject::TestObject(const Vec3& pos_in, TYPE type_in, const Vec3 ornt_in)
	:
	pos(pos_in),
	type(type_in),
	ornt(ornt_in)
{
	rct = std::make_unique<Drawable>(0.4f);

	Update();
}

void TestObject::Move(float x, float y, float z)
{
	pos.x += x;
	pos.y += y;
	pos.z += z;
}

void TestObject::Rotate(float x, float y, float z)
{
	ornt.x = wrap_angle(ornt.x + x);
	ornt.y = wrap_angle(ornt.y + y);
	ornt.z = wrap_angle(ornt.z + z);
}

void TestObject::Update()
{
	rot =
		Mat3::RotationX(ornt.x) *
		Mat3::RotationY(ornt.y) *
		Mat3::RotationZ(ornt.z);

	switch (type) {
	case TYPE::SKELETON:
		lines = rct->GetLines();
		TransformVertices(lines.vert, rot);
		break;
	case TYPE::FILLED:
		triangles = rct->GetTriangles();
		TransformVertices(triangles.vert, rot);
		break;
	}
}
void TestObject::TransformVertices(std::vector<Vec3>& verts, const Mat3& rot)
{
	for (auto& v : verts)
	{
		v *= rot;
		v += pos;
		cst.Transform(v);
	}
}

void TestObject::Draw(Graphics& gfx)
{
	switch (type) {
	case TYPE::SKELETON:
		DrawWithLines(gfx);
		break;
	case TYPE::FILLED:
		DrawWithTriangles(gfx);
		break;
	}
}

void TestObject::DrawWithLines(Graphics& gfx)
{
	for (auto i = lines.ind.cbegin(),
		end = lines.ind.cend();
		i != end; std::advance(i, 2))
	{
		gfx.DrawLine(lines.vert[*i], lines.vert[*std::next(i)], Colors::White);
	}
}

void TestObject::DrawWithTriangles(Graphics& gfx)
{
	for (auto i = triangles.ind.cbegin(),
		end = triangles.ind.cend();
		i != end; std::advance(i, 3))
	{
		gfx.DrawTriangle(triangles.vert[*i], triangles.vert[*std::next(i)], triangles.vert[*std::next(i, 2)], Colors::White);
	}
}