#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "mat2.hpp"

class Circle {
public:
	Circle();
	Circle(Vec2 const& center, float const& radius);
	Circle(Vec2 const& center, float const& radius, Color const& color);
	float diameter()const;          //Memberfunktion kann nicht keine nicht statischen Datenmember ändern, kann nicht const
	float circumrefrence() const;

	//getter function
	Vec2 center() const;
	float radius()const;

	//setter function
	void center(Vec2 const& center);
	void radius(float radius);

	void drawCircle(Window const& win);
	void drawCircle(Window const& win, Color const& color);

private:
	Vec2 center_;
	float radius_;
	Color color_;


};

#endif
