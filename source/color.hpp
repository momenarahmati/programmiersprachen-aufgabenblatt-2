#ifndef COLOR_HPP
#define COLOR_HPP

struct Color {

	float r;
	float g;
	float b;

	Color() {
		r = 211;
		g = 211;
		b = 211;
	};

	Color(float _r, float _g, float _b)
	{
		r = _r;
		g = _g;
		b = _b;

	};
};

#endif