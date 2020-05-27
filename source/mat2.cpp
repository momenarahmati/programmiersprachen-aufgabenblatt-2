#include"mat2.hpp"
#include<iostream>
#include<cmath>

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
	return *this;  // Referenziert auf das ursprüngliche Objekt, welches zurückgegeben werden soll
}
float Mat2::det() const  //Methode, um Determinante zu berechnen 
{
	float det = (e_00 * e_11) - (e_01 * e_10);
	return det;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2)
{
	Mat2 mResult;
	mResult.e_00 = m1.e_00 * m2.e_00 + m1.e_01 * m2.e_10;
	mResult.e_01 = m1.e_00 * m2.e_01 + m1.e_01 * m2.e_11;
	mResult.e_10 = m1.e_10 * m2.e_00 + m1.e_11 * m2.e_10;
	mResult.e_11 = m1.e_10 * m2.e_01 + m1.e_11 * m2.e_11;
	return mResult;
}
Vec2 operator*(Mat2 const& m, Vec2 const& v)
{
	Vec2 vector;
	vector.x = v.x * m.e_00 + v.y * m.e_01;
	vector.y = v.x * m.e_10 + v.y * m.e_11;
	return vector;
}
Vec2 operator*(Vec2 const& v, Mat2 const& m)
{
	Vec2 vector;
	vector.x = v.x * m.e_00 + v.y * m.e_01;
	vector.y = v.x * m.e_10 + v.y * m.e_11;
	return vector;
}
Mat2 inverse(Mat2 const& m)
{
	Mat2 invM;
	float det = m.e_00 * m.e_11 - (m.e_01 * m.e_10);
	if (det == 0)
	{
		std::cout << "wenn Determinant einer Matriz 0 ist,gibt es keine inverse Matriz" << std::endl;
		return m;
	}
	else
	{
		invM.e_00 = (1 / det) * m.e_11;
		invM.e_01 = -(1 / det) * m.e_01;
		invM.e_10 = -(1 / det) * m.e_10;
		invM.e_11 = (1 / det) * m.e_00;
		return invM;
	}
}

Mat2 transpose(Mat2 const& m)
{
	Mat2 transM;
	transM.e_00 = m.e_00;
	transM.e_01 = m.e_10;
	transM.e_10 = m.e_01;
	transM.e_11 = m.e_11;
	return transM;
}
Mat2 make_rotation_mat2(float phi)
{
	return Mat2(std::cos(phi), -std::sin(phi), std::sin(phi), std::cos(phi));
}