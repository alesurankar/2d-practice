#include "TestObject.h"


TestObject::TestObject(const Vec3& pos_in, TYPE type_in, const Vec3& ornt_in)
	:
	pos(pos_in),
	type(type_in),
	ornt(ornt_in),
	rct(std::make_unique<Drawable>(0.4f)),
	modelLines(rct->GetLines()),
	lines(modelLines),
	modelTriangles(rct->GetTriangles()),
	triangles(modelTriangles)
{
	Update();
}

void TestObject::Move(float x, float y, float z)
{
	pos.x += x;
	pos.y += y;
	pos.z += z;

	Update();
}

void TestObject::Move()
{
	pos.x += vel.x;
	pos.y += vel.y;
	pos.z += vel.z;

	Update();
}

void TestObject::Rotate(float x, float y, float z)
{
	ornt.x = wrap_angle(ornt.x + x);
	ornt.y = wrap_angle(ornt.y + y);
	ornt.z = wrap_angle(ornt.z + z);

	Update();
}

void TestObject::CheckBorder()
{
	if (pos.x < -2.2f) {
		pos.x = -2.2f;
		vel.x = -vel.x;
	}
	if (pos.y < -2.0f) {
		pos.y = -2.0f;
		vel.y = -vel.y;
	}
	if (pos.z < 2.8f) {
		pos.z = 2.8f;
		vel.z = -vel.z;
	}
	if (pos.x > 2.2f) {
		pos.x = 2.2f;
		vel.x = -vel.x;
	}
	if (pos.y > 2.0f) {
		pos.y = 2.0f;
		vel.y = -vel.y;
	}
	if (pos.z > 7.8f) {
		pos.z = 7.8f;
		vel.z = -vel.z;
	}	
}

void TestObject::SetVelocity(const Vec3& vel_in)
{
	vel = vel_in;
}

void TestObject::Update()
{
	rot =
		Mat3::RotationX(ornt.x) *
		Mat3::RotationY(ornt.y) *
		Mat3::RotationZ(ornt.z);

	switch (type) {
	case TYPE::SKELETON:
		lines = modelLines;
		TransformToWorldSpace(lines.vert, rot);
		TransformToScreenSpace(lines.vert);
		break;
	case TYPE::FILLED:
		triangles = modelTriangles;
		TransformToWorldSpace(triangles.vert, rot);
		TransformToScreenSpace(triangles.vert);
		break;
	case TYPE::COLORED:
		triangles = modelTriangles;
		TransformToWorldSpace(triangles.vert, rot);
		BackfaceCulling();
		TransformToScreenSpace(triangles.vert);
		break;
	}

	CheckBorder();
}
void TestObject::TransformToWorldSpace(std::vector<Vec3>& verts, const Mat3& rot)
{
	for (auto& v : verts)
	{
		v *= rot;
		v += pos;
	}
}

void TestObject::BackfaceCulling()
{
	for (size_t i = 0,
		end = triangles.ind.size() / 3;
		i < end; i++)
	{
		const Vec3& v0 = triangles.vert[triangles.ind[i * 3]];
		const Vec3& v1 = triangles.vert[triangles.ind[i * 3 + 1]];
		const Vec3& v2 = triangles.vert[triangles.ind[i * 3 + 2]];
		Vec3 normal = (v1 - v0) % (v2 - v0);
		Vec3 camera_pos = { 0.0f, 0.0f, 0.0f };
		Vec3 view = camera_pos -v0; // direction from v0 to camera
		triangles.cullFlags[i] = normal * view <= 0; // facing camera
	}
}

void TestObject::TransformToScreenSpace(std::vector<Vec3>& verts)
{
	for (auto& v : verts)
	{
		cst.Transform(v);
	}
}

void TestObject::Draw(Graphics& gfx)
{
	switch (type) {
	case TYPE::SKELETON:
		DrawLines(gfx);
		break;
	case TYPE::FILLED:
		DrawTriangles(gfx);
		break;
	case TYPE::COLORED:
		DrawColoredTriangles(gfx);
		break;
	}
}

void TestObject::DrawLines(Graphics& gfx)
{
	for (auto i = lines.ind.cbegin(),
		end = lines.ind.cend();
		i != end; std::advance(i, 2))
	{
		gfx.DrawLine(lines.vert[*i], lines.vert[*std::next(i)], Colors::White);
	}
}

void TestObject::DrawTriangles(Graphics& gfx)
{
	for (auto i = triangles.ind.cbegin(),
		end = triangles.ind.cend();
		i != end; std::advance(i, 3))
	{
		gfx.DrawTriangle(triangles.vert[*i], triangles.vert[*std::next(i)], triangles.vert[*std::next(i, 2)], Colors::White);
	}
}

void TestObject::DrawColoredTriangles(Graphics& gfx)
{
	for (size_t i = 0,end = triangles.ind.size() / 3;i < end; i++)
	{
		if (!triangles.cullFlags[i])
		{
			gfx.DrawTriangle(
				triangles.vert[triangles.ind[i * 3]],
				triangles.vert[triangles.ind[i * 3 + 1]],
				triangles.vert[triangles.ind[i * 3 + 2]],
				colors[i]);
		}
	}
}


Vec3 TestObject::GetPos() const
{
	return pos;
}