#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "mat2.hpp"

class Rectangle {
public:
	Rectangle();
	Rectangle(Vec2 const& min, Vec2 const& max);
	Rectangle(Vec2 const& min, Vec2 const& max, Color const& color);
	float Rectangle::laenge() const;
	float Rectangle::breite() const;
	float Rectangle::circumrefrence() const;

	//getter function
	Vec2 min() const;
	Vec2 max() const;


private:
	Vec2 min_;
	Vec2 max_;
	Color color_;


};

#endif