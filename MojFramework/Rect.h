#pragma once
#include "Vec2.h"
#include <algorithm>
#include "Surface.h"

template<typename T>
class Rect_
{
public:
	Rect_() = default;
	Rect_(T left_in, T top_in, T right_in, T bottom_in)
		:
		left(left_in), 
		top(top_in), 
		right(right_in), 
		bottom(bottom_in) 
	{}
	Rect_(const _Vec2<T>& topLeft, const _Vec2<T>& bottomRight)
		: 
		Rect_(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y) 
	{}
	Rect_(const _Vec2<T>& topLeft, T width, T height)
		: 
		Rect_(topLeft, topLeft + _Vec2<T>(width, height))
	{}
	template<typename T2>
	operator Rect_<T2>() const
	{
		return { (T2)left, (T2)top, (T2)right, (T2)bottom };
	}
	bool IsOverlappingWith(const Rect_& other) const
	{
		return right > other.left && left < other.right
			&& bottom > other.top && top < other.bottom;
	}
	Rect_<T> GetShrinkedBy(T value)
	{
		return Rect_<T>(left + (T)value, top + (T)value, right - (T)value, bottom - (T)value);
	}
	_Vec2<T> GetCenter() const
	{
		return _Vec2<T>((left + right) / (T)2, (top + bottom) / (T)2);
	}
	_Vec2<T> GetLeftTop() const
	{
		return _Vec2<T>(left, top);
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