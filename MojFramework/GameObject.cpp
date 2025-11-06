#include "GameObject.h"
#include <utility>

GameObject::GameObject(RectI rect_in, Color color_in)
	:
	rect(std::move(rect_in)),
	color(std::move(color_in)),
	destroyed(false)
{}

void GameObject::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, color);
}

//bool GameObject::CheckCollision(const GameObject& other) const
//{
//	// TO DO
//}

const RectI& GameObject::GetRect() const
{
	return rect;
}

bool GameObject::DestroyedCheck()
{
	return destroyed;
}

void GameObject::Destroy()
{
	destroyed = true;
}

//void GameObject::ChangeColor(Color color_in)
//{
//	color = color_in;
//}
//