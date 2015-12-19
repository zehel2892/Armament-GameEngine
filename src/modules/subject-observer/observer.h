#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H

#include "component.h"

namespace ns_armament { namespace ns_component {

class Observer : public Component
{
  public:
    Observer();
    virtual ~Observer();
    void Update(ns_entity::Entity & ent);
  protected:
  private:
};
 } }
#endif // OBSERVER_H
