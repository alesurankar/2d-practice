#include "TestObject.h"
#include "App.h"


//TestObject::TestObject(Graphics& gfx, const Vec3& pos_in, const std::string& filename, const Vec3& ornt_in)
TestObject::TestObject(Graphics& gfx, const Vec3& pos_in, const Vec3& ornt_in)
	:
	pos(pos_in),
	ornt(ornt_in),
	itlist(Drawable::GetPlainIndependentFaces<Vertex>()),
	//itlist(Drawable::GetPlain<Vertex>()),
	//itlist(Drawable::GetSkinned<Vertex>()),
	triangles(itlist)
{
	const Color colors[] = {
			Colors::Red,Colors::Green,Colors::Blue,Colors::Magenta,Colors::Yellow,Colors::Cyan
	};
	
	for (int i = 0; i < itlist.vert.size(); i++)
	{
		itlist.vert[i].color = colors[i / 4];
	}
	//itlist.vert[0].color = Vec3(Colors::Red);
	//itlist.vert[1].color = Vec3(Colors::Green);
	//itlist.vert[2].color = Vec3(Colors::Blue);
	//itlist.vert[3].color = Vec3(Colors::Yellow);
	//itlist.vert[4].color = Vec3(Colors::Cyan);
	//itlist.vert[5].color = Vec3(Colors::Magenta);
	//itlist.vert[6].color = Vec3(Colors::White);
	//itlist.vert[7].color = Vec3(Colors::Black);
	//pipeline.effect.ps.BindTexture(filename);
}

void TestObject::Move(float x, float y, float z)
{
	pos.x += x;
	pos.y += y;
	pos.z += z;

	CheckBorder();
}

void TestObject::Move()
{
	pos.x += vel.x;
	pos.y += vel.y;
	pos.z += vel.z;

	CheckBorder();
}

void TestObject::Rotate(float x, float y, float z)
{
	ornt.x = wrap_angle(ornt.x + x);
	ornt.y = wrap_angle(ornt.y + y);
	ornt.z = wrap_angle(ornt.z + z);

	CheckBorder();
}

void TestObject::CheckBorder()
{
	if (pos.x < -2.0f) {
		pos.x = -2.0f;
		vel.x = -vel.x;
	}
	if (pos.y < -2.0f) {
		pos.y = -2.0f;
		vel.y = -vel.y;
	}
	if (pos.z < 3.4f) {
		pos.z = 3.4f;
		vel.z = -vel.z;
	}
	if (pos.x > 2.0f) {
		pos.x = 2.0f;
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
	triangles = itlist;
}

void TestObject::SetVelocity(const Vec3& vel_in)
{
	vel = vel_in;
}

Vec3 TestObject::GetPos() const
{
	return pos;
}

Vec3 TestObject::GetOrnt() const
{
	return ornt;
}

const IndexedTriangleList <SolidEffect::Vertex > & TestObject::GetTriangle() const
{
	return triangles;
}
