#include "canvas.h"

Canvas::Canvas():m_uiCount(0)
{
  //ctor
}

Canvas::~Canvas()
{
  //dtor
}

Canvas::Canvas(const Canvas& other)
{
  //copy ctor
}

Canvas& Canvas::operator=(const Canvas& rhs)
{
  if (this == &rhs) return *this; // handle self assignment
  //assignment operator
  return *this;
}
