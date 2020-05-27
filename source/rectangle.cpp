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
/*
void Rectangle::drawRect(Window const& win) const {
	win.draw_line(min_.x, min_.y, min_.x, max_.y, 0.0f, 0.0f, 0.0f);
	win.draw_line(min_.x, max_.y, max_.x, max_.y, 0.0f, 0.0f, 0.0f);
	win.draw_line(max_.x, max_.y, max_.x, min_.y, 0.0f, 0.0f, 0.0f);
	win.draw_line(max_.x, min_.y, min_.x, min_.y, 0.0f, 0.0f, 0.0f);
	return;
}

void Rectangle::drawRect(Window const& win, Color const& color) const{
	win.draw_line(min_.x, min_.y, min_.x, max_.y, color.r, color.g, color.b);
	win.draw_line(min_.x, max_.y, max_.x, max_.y, color.r, color.g, color.b);
	win.draw_line(max_.x, max_.y, max_.x, min_.y, color.r, color.g, color.b);
	win.draw_line(max_.x, min_.y, min_.x, min_.y, color.r, color.g, color.b);
	return;
}*/