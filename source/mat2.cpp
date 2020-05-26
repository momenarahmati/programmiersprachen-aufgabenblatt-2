#include"mat2.hpp"
#include<iostream>

Mat2::Mat2() :
	e_00{ 1.0f },
	e_01{ 0.0f },
	e_10{ 0.0f },
	e_11{ 1.0f }
{}

Mat2::Mat2(float x_00, float x_01, float x_10, float x_11) :
	e_00{ x_00 },
	e_01{ x_01 },
	e_10{ x_10 },
	e_11{ x_11 }
{}


Mat2& Mat2::operator*=(Mat2 const& m)
{
	e_00 = e_00 * m.e_00 + e_01 * m.e_10;
	e_01 = e_00 * m.e_01 + e_01 * m.e_11;
	e_10 = e_10 * m.e_00 + e_11 * m.e_10;
	e_11 = e_10 * m.e_01 + e_11 * m.e_11;
	return *this;
}