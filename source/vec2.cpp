#include "vec2.hpp"
#include <iostream>

Vec2::Vec2():
	x{0.0f},
	y{0.0f}
{}

Vec2::Vec2(float new_x, float new_y) :
	x{new_x},
	y{new_y}
	{}
/*
Vec2& operator+=(Vec2 const& v)
{

}
Vec2& operator-=(Vec2 const& v)
{

}
Vec2& operator*=(float s)
{

}
Vec2& operator/=(float s)
{

} */