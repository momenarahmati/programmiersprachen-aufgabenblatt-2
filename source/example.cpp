#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "vec2.hpp"
#include "rectangle.hpp"
#include "circle.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
      if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
          win.close();
      }

      bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

      auto t = win.get_time();

      float x1 = 400.f + 380.f * std::sin(t);
      float y1 = 400.f + 380.f * std::cos(t);

      float x2 = 400.f + 380.f * std::sin(2.0f * t);
      float y2 = 400.f + 380.f * std::cos(2.0f * t);

      float x3 = 400.f + 380.f * std::sin(t - 10.f);
      float y3 = 400.f + 380.f * std::cos(t - 10.f);

      win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
      win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
      win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

      auto mouse_position = win.mouse_position();
      if (left_pressed) {
          win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
              mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
              1.0, 0.0, 0.0, // color with r,g,b in [0.0, 1.0]
              1.0);        // line thickness = 1.0 * default thickness
      }

      win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
      win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

      win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
      win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

      std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";

      int text_offset_x = 10;
      int text_offset_y = 5;
      unsigned int font_size = 35;

      win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

      win.update();
      
      // Draw circle

      Vec2 center1{ 400.0f, 400.0f };
      float radius1 = 200.0f;
      Circle c1(center1, radius1);
      c1.drawCircle(win);

      //draw Circle mit Farbe
      Vec2 center2{ 400.0f, 400.0f };
      float radius2 = 300.0f;
      Circle c2(center2, radius2);
      Color color{ 1.0f, 0.5f, 0.2f };
      c2.drawCircle(win, color);
      /*
      //Rectangle ohne Farbe
      Vec2 max1{ 250.2f, 231.1f };
      Vec2 min1{ 199.2f, 100.0f };
      Rectangle r1(max1, min1);
      r1.drawRect(win);

      //Rectangle mit Frabe
      Vec2 max2{ 450.0f, 450.0f };
      Vec2 min2{ 300.0f, 250.0f };
      Color col{ 0.0f, 0.2f, 0.7f };
      Rectangle r2(max2, min2);
      r2.drawRect(win, col);
    */
  }
  return 0;
}
