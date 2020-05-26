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

Vec2& Vec2::operator+=(Vec2 const& v)
{
	x += v.x;
	y += v.y;
	return *this;
}
Vec2& Vec2::operator-=(Vec2 const& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}
Vec2& Vec2::operator*=(float s)
{
	x *= s;
	y *= s;
	return *this;
}
Vec2& Vec2::operator/=(float s)
{
	if (s == 0)
	{
		std::cout << "The devision is not defined\n";
		Vec2  v0{};
		return v0;
	}
	else
	{
		x /= s;
		y /= s;
		return *this;
	}
} 
Vec2 operator+(Vec2 const& u, Vec2 const& v)
{
	return Vec2(u) += v;
}
Vec2 operator-(Vec2 const& u, Vec2 const& v)
{
	return Vec2(u) -= v;
}
Vec2 operator*(Vec2 const& v, float s)
{
	return Vec2(v) *= s;
}
Vec2 operator/(Vec2 const& v, float s)
{
	if (s == 0.0f)
	{
		std::cout << "s == 0 ist nicht definiert" << std::endl;
		Vec2 v0;
		return v0;
	}
	else
		return Vec2(v) /= s;
}

Vec2 operator*(float s, Vec2 const& v)
{
	return  Vec2(v) *= s;
}