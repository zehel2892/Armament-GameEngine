#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "canvas.h"
#include "entity.h"
#include "observer.h"

using namespace ns_armament;
using namespace ns_canvas;
using namespace ns_entity;

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

  ns_subject::Subject sub;

  ns_component::Observer obs;

  ns_entity::Entity ent(ns_entity::Entity::en_PROJECT_MANAGER);

  sub.Attach(ent,obs);



  while(display.GetIsCanvasActive()==true)
  {

    display.Update();
  }

  SDL_Quit();


  return 0;

}
