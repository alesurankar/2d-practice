#include "TestObject.h"
#include "App.h"


TestObject::TestObject(Graphics& gfx, const Vec3& pos_in, const std::string& filename, const Vec3& ornt_in)
	:
	pos(pos_in),
	ornt(ornt_in),
	rct(std::make_unique<Drawable>(0.4f)),
	modelTriangles(rct->GetTrianglesTex()),
	triangles(modelTriangles),
	pipeline(gfx)
{
	pipeline.BindTexture(filename);
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
	pipeline.rotation =
		Mat3::RotationX(ornt.x) *
		Mat3::RotationY(ornt.y) *
		Mat3::RotationZ(ornt.z);

		//pipeline.BindRotation(rot);
		//pipeline.BindTranslation(trans);
	triangles = modelTriangles;
	TransformToWorldSpace(triangles.vert, pipeline.rotation);
	BackfaceCulling();
	TransformToScreenSpace(triangles.vert);

	CheckBorder();
}

void TestObject::TransformToWorldSpace(std::vector<TexVertex>& verts, const Mat3& rot)
{
	for (auto& v : verts)
	{
		v.pos *= rot;   // rotate position
		v.pos += pos;   // translate position
	}
}

void TestObject::BackfaceCulling()
{
	for (size_t i = 0,
		end = triangles.ind.size() / 3;
		i < end; i++)
	{
		const Vec3& v0 = triangles.vert[triangles.ind[i * 3]].pos;
		const Vec3& v1 = triangles.vert[triangles.ind[i * 3 + 1]].pos;
		const Vec3& v2 = triangles.vert[triangles.ind[i * 3 + 2]].pos;
		Vec3 normal = (v1 - v0) % (v2 - v0);
		Vec3 camera_pos = { 0.0f, 0.0f, 0.0f };
		Vec3 view = camera_pos -v0; // direction from v0 to camera
		triangles.cullFlags[i] = normal * view <= 0; // facing camera
	}
}

void TestObject::TransformToScreenSpace(std::vector<TexVertex>& verts)
{
	for (auto& v : verts)
	{
		pipeline.cst.Transform(v.pos);
	}
}

void TestObject::Draw()
{
	for (size_t i = 0, end = triangles.ind.size() / 3; i < end; i++)
	{
		if (!triangles.cullFlags[i])
		{
			pipeline.gfx.DrawTriangleTex(
				triangles.vert[triangles.ind[i * 3]],
				triangles.vert[triangles.ind[i * 3 + 1]],
				triangles.vert[triangles.ind[i * 3 + 2]],
				pipeline.tex);
		}
	}
}

Vec3 TestObject::GetPos() const
{
	return pos;
}