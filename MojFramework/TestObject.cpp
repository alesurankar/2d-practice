#include "TestObject.h"
#include "App.h"


TestObject::TestObject(Graphics& gfx, const Vec3& pos_in, const std::string& filename, const Vec3& ornt_in)
	:
	pos(pos_in),
	ornt(ornt_in),
	itlist(Drawable::GetSkinned<Vertex>()),
	triangles(itlist),
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
	if (pos.x < -2.1f) {
		pos.x = -2.1f;
		vel.x = -vel.x;
	}
	if (pos.y < -2.1f) {
		pos.y = -2.1f;
		vel.y = -vel.y;
	}
	if (pos.z < 3.2f) {
		pos.z = 3.2f;
		vel.z = -vel.z;
	}
	if (pos.x > 2.1f) {
		pos.x = 2.1f;
		vel.x = -vel.x;
	}
	if (pos.y > 2.1f) {
		pos.y = 2.1f;
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
	CheckBorder();

	const Mat3 rot =
		Mat3::RotationX(ornt.x) *
		Mat3::RotationY(ornt.y) *
		Mat3::RotationZ(ornt.z);

	const Vec3 trans = { pos.x,pos.y,pos.z };

	pipeline.BindRotation(rot);
	pipeline.BindTranslation(trans);

	triangles = itlist;
}

void TestObject::Draw()
{
	pipeline.Draw(triangles);
}

Vec3 TestObject::GetPos() const
{
	return pos;
}