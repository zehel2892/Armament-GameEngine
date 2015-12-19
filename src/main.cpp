#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "canvas.h"

using namespace ns_armament;
using namespace ns_canvas;

/** Entity Component system
        armament.Attach(ns_entity::Entity & ,ns_subject::Subject & , ns_component::Observer & );
        Then
            |_ inside Attach join Observer to Subject
            |_ call entity.AddComponent
 */

int main(int argc, char **argv)
{
  std::cout<<"Hello world"<<std::endl;
  Canvas display(640,480,"SDL window");

  while(display.GetIsCanvasActive()==true)
  {

    display.Update();
  }

  SDL_Quit();


  return 0;

}
