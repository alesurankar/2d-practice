#pragma once
#include "Vec2.h"
#include <algorithm>

template<typename T>
class Rect_
{
public:
	Rect_() = default;
	Rect_(T left, T top, T right, T bottom)
		: left(left), top(top), right(right), bottom(bottom) 
	{}
	Rect_(const Vec2_<T>& topLeft, const Vec2_<T>& bottomRight)
		: Rect_(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y) 
	{}
	Rect_(const Vec2_<T>& topLeft, T width, T height)
		: Rect_(topLeft.x, topLeft.y, topLeft.x + width, topLeft.y + height) 
	{}
	template<typename T2>
	operator Rect_<T2>() const
	{
		return { (T2)left, (T2)top, (T2)right, (T2)bottom };
	}
	void ClipTo(const Rect_& rect)
	{
		left = std::max(left, rect.left);
		top = std::max(top, rect.top);
		right = std::min(right, rect.right);
		bottom = std::min(bottom, rect.bottom);
	}
	bool IsOverlappingWith(const Rect_& other) const
	{
		return right > other.left && left < other.right
			&& bottom > other.top && top < other.bottom;
	}
	bool Contains(const Vec2_<T>& p) const
	{
		return p.x >= left && p.x <= right && p.y >= top && p.y <= bottom;
	}
	void Translate(const Vec2_<T>& d)
	{
		left += d.x; 
		top += d.y; 
		right += d.x; 
		bottom += d.y;
	}
	Vec2_<T> GetPos() const
	{
		return Vec2_<T>(left, top);
	}
	Vec2_<T> GetCenter() const
	{
		return Vec2_<T>((left + right) / (T)2, (top + bottom) / (T)2);
	}
	T GetWidth() const
	{
		return right - left;
	}
	T GetHeight() const
	{
		return bottom - top;
	}
public:
	T left;
	T top;
	T right;
	T bottom;
};

using RectI = Rect_<int>;
using RectF = Rect_<float>;