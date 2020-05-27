#include "circle.hpp"
#include <cmath>
#include "color.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include "window.hpp"
#define Pi 3.1415926

Circle::Circle() :
	center_{ 0.0,0.0 },
	radius_{ 1.0 },
	color_{ 0,0,0 }
{}
Circle::Circle(Vec2 const& center, float const& radius) :
	center_{ center },
	radius_{ radius }
{}

Circle::Circle(Vec2 const& center, float const& radius, Color const& color) :
	center_{ center },
	radius_{ radius },
	color_{ color }
{}

float Circle::diameter()const
{
	float diameter = (radius_ * 2);
	return diameter;
}
float Circle::circumrefrence() const
{
	return Pi * radius() * 2;
}
Vec2 Circle::center() const       //getter Function
{
	return center_;
}
float Circle::radius() const       //getter Function
{
	return radius_;
}

void Circle::center(Vec2 const& center)   //setter Function
{
	center_ = center;
}

void Circle::radius(float radius)   //setter Function
{
	radius_ = radius;
}

void Circle::drawCircle(Window const& win)
{
	win.draw_point(center_.x, center_.y, 0.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 360; i++) {
		float M_PI = std::acos(-1.0);
		Vec2 start = ((make_rotation_mat2(2 * i * M_PI / 360)) * Vec2(radius_, 0.0f) + center_);
		Vec2 end = ((make_rotation_mat2(2 * M_PI * (i + 1) / 360)) * Vec2(radius_, 0.0f) + center_);
		win.draw_line(start.x, start.y, end.x, end.y, 0.0f, 0.0f, 0.0f);
	}
	return;
}

void Circle::drawCircle(Window const& win, Color const& color) {
	win.draw_point(center_.x, center_.y, color.r, color.g, color.b);
	for (int i = 1; i <= 360; i++) {
		float M_PI = std::acos(-1.0);
		Vec2 start = ((make_rotation_mat2(2 * i * M_PI / 360)) * Vec2(radius_, 0.0f) + center_);
		Vec2 end = ((make_rotation_mat2(2 * M_PI * (i + 1) / 360)) * Vec2(radius_, 0.0f) + center_);
		win.draw_line(start.x, start.y, end.x, end.y, color.r, color.g, color.b);
	}
	return;
}