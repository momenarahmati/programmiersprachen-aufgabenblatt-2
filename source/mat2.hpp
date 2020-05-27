#ifndef MAT2_HPP
#define MAT2_HPP
#include<math.h>

#include"vec2.hpp"
#include<array>


struct Mat2
{
	//Membervariablen
	float e_00;  // top left
	float e_01;  // top right
	float e_10;  // Down left
	float e_11;  // Down right

	Mat2(); //Standard Constructor erzugt Einheitsmatriz
	Mat2(float x_00, float x_01, float x_10, float x_11); // user konstruktur

	Mat2& operator*=(Mat2 const& m);
};
Mat2 operator*(Mat2 const& m1, Mat2 const& m2);

#endif