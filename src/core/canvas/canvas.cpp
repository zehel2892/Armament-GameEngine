#include "canvas.h"
////////////////////////////////////////////////////////////////////////////////
// NAMESPACE STARTS //
namespace ns_armament { namespace ns_canvas {

////////////////////////////////////////////////////////////////////////////////
Canvas::Canvas()
{
  //ctor
   std::cout<<"Hit Canvas default constructor"<<std::endl;


}



Canvas::Canvas(const Canvas& other)
{
  //copy ctor
  std::cout<<"Hit Canvas copy constructor"<<std::endl;
}

Canvas& Canvas::operator=(const Canvas& rhs)
{
  if (this == &rhs) return *this; // handle self assignment
  //assignment operator
  return *this;
}

Canvas::Canvas(td_uint WIDTH , td_uint HEIGHT, std::string title)
{


  std::cout<<"Hit Canvas overridden constructor"<<std::endl;

    // Set minimum space required for the bits to be drawn
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    glEnable(GL_DEPTH_TEST);



  /** Initialising SDL2 */
  SDL_SetMainReady();
  SDL_Init(SDL_INIT_VIDEO);

  m_pWindow = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_OPENGL);


  /** Create the OpenGL context
   *  WARNING : Create the OpenGL context before calling glewInit()
   *            Otherwise we will get Missing GL version error
   */
  m_GLContext = SDL_GL_CreateContext(m_pWindow);

   /** NOTE: \param glewExperimental
    *  SYNOPSIS: We are telling that we are using new OpenGL attributes
    *  WARNING : Create the OpenGL context before calling glewInit()
    *            Otherwise we will get Missing GL version error
    */

    glewExperimental = GL_TRUE;

    GLenum status = glewInit();
     if(status != GLEW_OK)
    { std::cerr<<"ERROR : Glew failed to initialise : "
               <<glewGetErrorString(status)<<std::endl;}

   m_bIsCanvasActive =true;

}

Canvas::~Canvas()
{

  std::cout<<"Hit destructor"<<std::endl;
  SDL_GL_DeleteContext(m_GLContext);
  SDL_DestroyWindow(m_pWindow);
}

void Canvas::Update()

{

  Clear();

  InputManager();

}

void Canvas::Clear()
{

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f,0.3f,0.5f,1.0f);
  SDL_GL_SwapWindow(m_pWindow);

}

void Canvas::InputManager()
{


  SDL_Event e;

  while(SDL_PollEvent(&e))
    {

       ///CASE : if Escape key is pressed down
      if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
        {
          m_bIsCanvasActive = false;

        }

    }


}

////////////////////////////////////////////////////////////////////////////////
// NAMESPACE ENDS //
  }    // end ns_canvas
}     // end ns_armament
////////////////////////////////////////////////////////////////////////////////
