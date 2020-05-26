#ifndef MAT2_HPP
#define MAT2_HPP
#include"vec2.hpp"
#include <array>

struct Mat2 {

	Mat2(); //Standard Constructor erzugt Einheitsmatriz
	Mat2(float x_00, float x_01, float x_10, float x_11);

	//Membervariablen
	float e_00;
	float e_01;
	float e_10;
	float e_11;

	Mat2& operator*=(Mat2 const& m);
	float det() const;
};

#endif