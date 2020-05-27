#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"

TEST_CASE("StandardCons1","[Vec2]") 
{
    Vec2 a;
    Vec2 b{5.1f,-9.3f};
    REQUIRE(a.x == Approx(0.0f).epsilon(0.01f));
    REQUIRE(a.y == Approx(0.0f).epsilon(0.01f));
    REQUIRE(b.x == Approx(5.1f).epsilon(0.01f));
    REQUIRE(b.y == Approx(-9.3f).epsilon(0.01f));
}
TEST_CASE("testOperator+2", "[poertor+]")
{
    Vec2 a{ 2.0f,2.0f };
    Vec2 b{ 2.0f,-2.0f };
    a += b;
    REQUIRE(a.x == Approx(4.0f));
    REQUIRE(a.y == Approx(0.0f));
}
TEST_CASE("testOperator-=3", "[operator-=]")
{
    Vec2 a{ -1,0 };
    Vec2 b{ 10,20 };
    a -= b;
    REQUIRE(a.x == Approx(-11.0f));
    REQUIRE(a.y == Approx(-20.0f));
}
TEST_CASE("testOperator*=4", "[operator*=]")
{
    Vec2 a{ -1,0 };
    float s = 5;
    a *= s;
    REQUIRE(a.x == Approx(-5.0f));
    REQUIRE(a.y == Approx(0.0f));
}
TEST_CASE("testOperator/=5", "[operator/=]")
{
    Vec2 a{ 3,-2 };
    float s = 10;
    a /= s;
    REQUIRE(a.x == Approx(0.3f));
    REQUIRE(a.y == Approx(-0.2f));
}
TEST_CASE("testFreieFuncOperator+6", "[operator+]")
{
    Vec2 a{ 1,4 };
    Vec2 b{ 0,3 };
    a += b;
    REQUIRE(a.x == Approx(1.0f));
    REQUIRE(a.y == Approx(7.0f));
}
TEST_CASE("test2FreieFuncOperator+7", "[operator+]")
{
    Vec2 a{ -1,-4 };
    Vec2 b{ 10,-3 };
    a += b;
    REQUIRE(a.x == Approx(9.0f));
    REQUIRE(a.y == Approx(-7.0f));
}
TEST_CASE("testFreieFuncOperator-8", "[operator-]")
{
    Vec2 a{ -1,-4 };
    Vec2 b{ 10,-3 };
    a -= b;
    REQUIRE(a.x == Approx(-11.0f));
    REQUIRE(a.y == Approx(-1.0f));
}
TEST_CASE("2testFreieFuncOperator-9", "[operator*]")
{
    Vec2 a{ -1,-4 };
    float s = 100;
    a *= s;
    REQUIRE(a.x == Approx(-100.0f));
    REQUIRE(a.y == Approx(-400.0f));
}
TEST_CASE("testFreieFuncOperator/10", "[operator/]")
{
    Vec2 a{ -100,-400 };
    float s = 10;
    a /= s;
    REQUIRE(a.x == Approx(-10.0f));
    REQUIRE(a.y == Approx(-40.0f));
}
TEST_CASE("2testFreieFuncOperator/11", "[operator/]")
{
    Vec2 a{ -100,-400 };
    float s = 0.0f;
    a /= s;
    REQUIRE(a.x == Approx(-100.0f));
    REQUIRE(a.y == Approx(-400.0f));
}
TEST_CASE("testFreieFuncOperator*12", "[operator*]")
{
    float s = 11;
    Vec2 v{ -1,5 };
    v = s * v;
    REQUIRE(v.x == Approx(-11.0f));
    REQUIRE(v.y == Approx(55.0f));
}

TEST_CASE("13:testOperator*Mat2", "[operator*=]")
{
    Mat2 a{ 0,2,-3,4 };
    Mat2 b{ 1,2,3,4 };
    a *= b;
    REQUIRE(a.e_00 == Approx(6.0f));
    REQUIRE(a.e_01 == Approx(20.0f));
    REQUIRE(a.e_10 == Approx(9.0f));
    REQUIRE(a.e_11 == Approx(34.0f));
}

TEST_CASE("14standardKonstructur_Mat")
{
    Mat2 a; 
    REQUIRE(a.e_00 == Approx(1.0f));
    REQUIRE(a.e_01 == Approx(0.0f));
    REQUIRE(a.e_10 == Approx(0.0f));
    REQUIRE(a.e_11 == Approx(1.0f));
} 
TEST_CASE("15:testMatrixOperatoren", "[operatorMat*]")
{
    Mat2 a{ -1.0f,2.0f,-3.0f,4.0f };
    REQUIRE(a.e_00 == Approx(-1.0f));
    REQUIRE(a.e_01 == Approx(2.0f));
    REQUIRE(a.e_10 == Approx(-3.0f));
    REQUIRE(a.e_11 == Approx(4.0f));
} 
TEST_CASE("16:test_Multiplikation_Matriz_Vektor")
{
    Mat2 a{ -5,0,7,1 };
    Vec2 b{ 2,3 };
    b = a * b;
    REQUIRE(b.x == Approx(-10.0f));
    REQUIRE(b.y == Approx(17.0f));
}
TEST_CASE("17:test_Multiplikation_Matriz_Vektor")
{
    Mat2 a{ -5,0,7,1 };
    Vec2 b{ 0,0 };
    b = a * b;
    REQUIRE(b.x == Approx(0.0f));
    REQUIRE(b.y == Approx(0.0f));
}
TEST_CASE("18:testInversMatriz", "[inverse]")
{
    Mat2 a{ 10,10,10,10 };
    a = inverse(a);
    REQUIRE(a.e_00 == Approx(10.0f));
    REQUIRE(a.e_01 == Approx(10.0f));
    REQUIRE(a.e_10 == Approx(10.0f));
    REQUIRE(a.e_11 == Approx(10.0f));
}
TEST_CASE("19:testInversMatriz", "[inverse]")
{
    Mat2 a{ 11,14,15,-16 };
    a = inverse(a);
    REQUIRE(a.e_00 == Approx(0.04145f));
    REQUIRE(a.e_01 == Approx(0.03627f));
    REQUIRE(a.e_10 == Approx(0.03886f));
    REQUIRE(a.e_11 == Approx(-0.0285f));
}
TEST_CASE("20:testTransposeMatriz", "[transpose]")
{
    Mat2 a{ 1,2,3,4 };
    a = transpose(a);
    REQUIRE(a.e_00 == Approx(1.0f));
    REQUIRE(a.e_01 == Approx(3.0f));
    REQUIRE(a.e_10 == Approx(2.0f));
    REQUIRE(a.e_11 == Approx(4.0f));
}
TEST_CASE("21:testMake_rotation", "[make_rotation_mat2]")
{
    float phi = 60;
    Mat2 m = make_rotation_mat2(phi);
    REQUIRE(m.e_00 == Approx(-0.95f).epsilon(0.01));
    REQUIRE(m.e_01 == Approx(0.30f).epsilon(0.01));
    REQUIRE(m.e_10 == Approx(-0.30f).epsilon(0.01));
    REQUIRE(m.e_11 == Approx(-0.95f).epsilon(0.01));
}
TEST_CASE("22:testMake_rotation", "[make_rotation_mat2]")
{
    float phi = -60;
    Mat2 m = make_rotation_mat2(phi);
    REQUIRE(m.e_00 == Approx(-0.95f).epsilon(0.01));
    REQUIRE(m.e_01 == Approx(-0.30f).epsilon(0.01));
    REQUIRE(m.e_10 == Approx(0.30f).epsilon(0.01));
    REQUIRE(m.e_11 == Approx(-0.95f).epsilon(0.01));
}

TEST_CASE("23:testDeterminantMatriz")
{
    Mat2 a{ 1,2,3,4 };
    REQUIRE(a.det() == Approx(-2.0f));
}
TEST_CASE("24:testDeterminantMatriz")
{
    Mat2 a{ 0,0,0,0 };
    REQUIRE(a.det() == Approx(0.0f));
}
TEST_CASE("25FarbeTest", "[color]")
{
    Color red{ 0.8f,0.0f,1.3f };
    REQUIRE(red.r == 0.8f);
    REQUIRE(red.g == 0.0f);
    REQUIRE(red.b == 1.3f);
}
TEST_CASE("26FarbeGrauDefaultTest", "[color]")
{
    Color grau{ };
    REQUIRE(grau.r == 211);
    REQUIRE(grau.g == 211);
    REQUIRE(grau.b == 211);
}
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
