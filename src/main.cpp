#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "canvas.h"

int main(int argc, char **argv)
{
  std::cout<<"Hello world"<<std::endl;
  Canvas display;

  std::cout<<display.GetCount()<<std::endl;

  return 0;

}
