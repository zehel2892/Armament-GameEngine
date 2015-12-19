#include "entity.h"
#include "component.h"


using namespace ns_armament::ns_entity;

namespace ns_armament { namespace ns_entity {
Entity::Entity()
{
  //ctor
}

Entity::~Entity()
{
  //dtor
}

Entity::Entity(const Entity& other)
{
  //copy ctor
}

Entity& Entity::operator=(const Entity& rhs)
{
  if (this == &rhs) return *this; // handle self assignment
  //assignment operator
  return *this;
}


void Entity::AddComponent(ns_subject::Subject & sub , ns_component::Observer & obs)
{   ns_subject::Subject * p = &sub;
    m_vpSubjectList.push_back(p);

}

void Entity::RemoveComponent(ns_subject::Subject & sub , ns_component::Observer & obs)
{   ns_subject::Subject * p = &sub;
    for (unsigned int i = 0; i < m_vpSubjectList.size(); ++i)
    {
        if(m_vpSubjectList[i]==p)
        {/* This is a round about way of deleting the index
         * since the position can be expressed as
         * 0+i = i;
         */
            m_vpSubjectList.erase(m_vpSubjectList.begin()+i);
        }
    }

}


 } } // end namespaces
