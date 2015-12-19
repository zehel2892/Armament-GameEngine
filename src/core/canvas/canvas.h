#ifndef CANVAS_H
#define CANVAS_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// NAMESPACE STARTS //
namespace ns_armament { namespace ns_canvas {
////////////////////////////////////////////////////////////////////////////////
class Canvas
{
public:

typedef unsigned int td_uint;

  /** Default constructor */
  Canvas();
   /** Default destructor */
  virtual ~Canvas();
  /** Copy constructor
    *  \param other Object to copy from
    */
  Canvas(const Canvas& other);
    /** Assignment operator
     *  \param other Object to assign from
     *  \return A reference to this
     */
  Canvas& operator=(const Canvas& other);




  Canvas(td_uint WIDTH , td_uint HEIGHT, std::string title);
     /** Access utility functions here
      */
public:
        /** Runtime methods defined here
         */
       void  Update();

public:
    /** Access activation status of the canvas
     *  \return m_bIsCanvasActive
     *  \brief Shows whether the canvas is active or not
     */


  bool GetIsCanvasActive() { return m_bIsCanvasActive; }

protected:


  bool m_bIsCanvasActive; //!< Member variable "m_bCanvasActive"

  void InputManager();
  void Clear();

private:

  SDL_Window  * m_pWindow;
  SDL_GLContext m_GLContext;





};

////////////////////////////////////////////////////////////////////////////////
// NAMESPACE ENDS //
 } } // _namespace ends here
////////////////////////////////////////////////////////////////////////////////

#endif // CANVAS_H
