#include "GameObject.h"
#include <utility>

GameObject::GameObject(RectI rect_in, Color color_in)
	:
	rect(std::move(rect_in)),
	color(std::move(color_in))
{}

void GameObject::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, color);
}

bool GameObject::CheckCollision(const GameObject& other) const
{
	return rect.IsOverlappingWith(other.rect);
}


void GameObject::ChangeColor(Color color_in)
{
	color = color_in;
}