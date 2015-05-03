#include <fensterchen.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
  bool insideRad1 = false;
  Window win(glm::ivec2(800,800));

  while (!win.shouldClose()) {
    if (win.isKeyPressed(GLFW_KEY_ESCAPE)) {
      win.stop();
    }

      auto t = win.getTime();
      auto m = win.mousePosition();

      Rectangle rect{};
      
      Circle rad1 {{fmod(t/23,1.0),0.2,{0.9}},sqrt(pow(rect.height(), 2)+pow(rect.width(), 2))/2};
          
      rect.center({fmod(t/23,1.0),0.2});
      rad1.draw_full(win);
      
      Circle c{{0.5,0.5,{0.2}},0.1};
      
      if (rect.is_inside({m.x,m.y}) | insideRad1 )
      {
          if (rad1.is_inside({m.x,m.y}))
          {
              rect.color({0.0,0.0,1.0});
              rect.center({m.x,m.y});
              insideRad1 = true;
          } else {
              insideRad1 = false;
          }
      } else {
          rect.color({fmod(t,1.0),fmod(t/30,1.0),fmod(t/90,1.0)});
      }
      
      if(c.is_inside({m.x,m.y}))
      {
          c.draw(win,Color {0,0,1});
      } else {
          c.draw(win,fmod(t,40)*sin(t));
      }
      
      c.color({0.7,0.6,0});
      c.radius(c.radius()-0.009);
      c.draw(win);
      
      rect.draw(win);

    win.update();
  }

  return 0;
}
