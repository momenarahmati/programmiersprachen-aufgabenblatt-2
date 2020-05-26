#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "vec2.hpp"

TEST_CASE("StandardCons","[Vec2]") 
{
    Vec2 a;
    Vec2 b{5.1f,-9.3f};
    REQUIRE(a.x == Approx(0.0f).epsilon(0.01f));
    REQUIRE(a.y == Approx(0.0f).epsilon(0.01f));
    REQUIRE(b.x == Approx(5.1f).epsilon(0.01f));
    REQUIRE(b.y == Approx(-9.3f).epsilon(0.01f));
}
TEST_CASE("testOperator+", "[poertor+]")
{
    Vec2 a{ 2.0f,2.0f };
    Vec2 b{ 2.0f,-2.0f };
    a += b;
    REQUIRE(a.x == Approx(4.0f));
    REQUIRE(a.y == Approx(0.0f));
}
TEST_CASE("testOperator-=", "[operator-=]")
{
    Vec2 a{ -1,0 };
    Vec2 b{ 10,20 };
    a -= b;
    REQUIRE(a.x == Approx(-11.0f));
    REQUIRE(a.y == Approx(-20.0f));
}
TEST_CASE("testOperator*=", "[operator*=]")
{
    Vec2 a{ -1,0 };
    float s = 5;
    a *= s;
    REQUIRE(a.x == Approx(-5.0f));
    REQUIRE(a.y == Approx(0.0f));
}
TEST_CASE("testOperator/=", "[operator/=]")
{
    Vec2 a{ 3,-2 };
    float s = 10;
    a /= s;
    REQUIRE(a.x == Approx(0.3f));
    REQUIRE(a.y == Approx(-0.2f));
}
TEST_CASE("testFreieFuncOperator+", "[operator+]")
{
    Vec2 a{ 1,4 };
    Vec2 b{ 0,3 };
    a += b;
    REQUIRE(a.x == Approx(1.0f));
    REQUIRE(a.y == Approx(7.0f));
}
TEST_CASE("test2FreieFuncOperator+", "[operator+]")
{
    Vec2 a{ -1,-4 };
    Vec2 b{ 10,-3 };
    a += b;
    REQUIRE(a.x == Approx(9.0f));
    REQUIRE(a.y == Approx(-7.0f));
}
TEST_CASE("testFreieFuncOperator-", "[operator-]")
{
    Vec2 a{ -1,-4 };
    Vec2 b{ 10,-3 };
    a -= b;
    REQUIRE(a.x == Approx(-11.0f));
    REQUIRE(a.y == Approx(-1.0f));
}
TEST_CASE("2testFreieFuncOperator-", "[operator*]")
{
    Vec2 a{ -1,-4 };
    float s = 100;
    a *= s;
    REQUIRE(a.x == Approx(-100.0f));
    REQUIRE(a.y == Approx(-400.0f));
}
TEST_CASE("testFreieFuncOperator/", "[operator/]")
{
    Vec2 a{ -100,-400 };
    float s = 10;
    a /= s;
    REQUIRE(a.x == Approx(-10.0f));
    REQUIRE(a.y == Approx(-40.0f));
}
TEST_CASE("2testFreieFuncOperator/", "[operator/]")
{
    Vec2 a{ -100,-400 };
    float s = 0.0f;
    a /= s;
    REQUIRE(a.x == Approx(-100.0f));
    REQUIRE(a.y == Approx(-400.0f));
}
TEST_CASE("testFreieFuncOperator*", "[operator*]")
{
    float s = 11;
    Vec2 v{ -1,5 };
    v = s * v;
    REQUIRE(v.x == Approx(-11.0f));
    REQUIRE(v.y == Approx(55.0f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
