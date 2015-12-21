#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity.h"
namespace ns_armament { namespace ns_entity {
  class Entity; // Forward declaration
  }}
  namespace ns_armament { namespace ns_subject {
  class Subject; // Forward declaration
  }}
namespace ns_armament { namespace ns_component {
class Component
{
  public:


    virtual void Update(ns_entity::Entity & ent,ns_subject::Subject::ENotification & note)=0;

  protected:
  private:
      ns_entity::Entity * e;
      ns_subject::Subject * s;
};
 } }
#endif // COMPONENT_H
