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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
