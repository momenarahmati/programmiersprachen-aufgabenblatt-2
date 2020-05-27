#include "rectangle.hpp"
#include <cmath>
#include "color.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include "window.hpp"


Rectangle::Rectangle() :
	min_{ 0.0,0.0 },
	max_{ 1.0,1.0 },
	color_{ 0,0,0 }
{}
Rectangle::Rectangle(Vec2 const& min, Vec2 const& max) :
	min_{ min },
	max_{ max }
{}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color) :
	min_{ min },
	max_{ max },
	color_{ color }
{}

float Rectangle::laenge() const
{
	return max_.y - min_.y;
}

float Rectangle::breite() const
{
	return max_.x - min_.x;
}

float Rectangle::circumrefrence() const
{
	return (2 * (laenge() + breite()));
}

Vec2 Rectangle::min() const
{
	return min_;
}

Vec2 Rectangle::max() const
{
	return max_;
}
