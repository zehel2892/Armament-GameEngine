#include "observer.h"
#include <iostream>

using namespace ns_armament::ns_component;
namespace ns_armament { namespace ns_component  {
Observer::Observer()
{
  //ctor
}

Observer::~Observer()
{
  //dtor
}

void Observer::Update(ns_entity::Entity & ent , ns_subject::Subject::ENotification & note)
{
    std::cout<<"Received Update message from entity : "<<ent.m_em_ModuleType<<std::endl;
    std::cout<<"Received notification is            : "<<note<<std::endl;

}




 } } // end namespaces
