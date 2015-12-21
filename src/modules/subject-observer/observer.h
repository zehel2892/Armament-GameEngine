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
    void Update(ns_entity::Entity & ent , ns_subject::Subject::ENotification & note);

  protected:
      // The Subject which is a parent to this Observer
      ns_subject::Subject * m_Sub;
  private:
};
 } }
#endif // OBSERVER_H
