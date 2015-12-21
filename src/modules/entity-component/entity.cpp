#include "entity.h"
#include "component.h"
#include <iostream>


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

Entity::Entity(EModule modType):m_em_ModuleType(modType)
{
    std::cout<<"Entity constructed with EModule : "<<m_em_ModuleType<<std::endl;
}


void Entity::AddComponent(ns_subject::Subject & sub , ns_component::Observer & obs)
{  /* ERROR : We are storing a pointer to class Subject
    *         What we should be storing is a compoent i.e an Observer
    */
    ns_component::Observer * p = &obs;
    m_vpGlobalObserverList.push_back(p);
    if(m_vpGlobalObserverList[m_vpGlobalObserverList.size()-1] == p)
    {
        std::cout<<"Successfully added component : nt_ADD_COMPONENT_SUCCESS "<<std::endl;
        sub.GenNotification(*this,sub.nt_ADD_COMPONENT_SUCCESS);
        AddSubject(sub);
    }


}

void Entity::RemoveComponent(ns_subject::Subject & sub , ns_component::Observer & obs)
{   ns_component::Observer * p = &obs;
    for (unsigned int i = 0; i < m_vpGlobalObserverList.size(); i++)
    {
        if(m_vpGlobalObserverList[i]==p)
        {/* This is a round about way of deleting the index
         * since the position can be expressed as
         * 0+i = i;
         */
            m_vpGlobalObserverList.erase(m_vpGlobalObserverList.begin()+i);
            /// We need to send a reference
            sub.GenNotification(*this, sub.nt_REMOVE_COMPONENT_SUCCESS);
            RemoveSubject(sub);
        }
    } // end for loop

}

void Entity::AddSubject(ns_subject::Subject& sub)
{
    ns_subject::Subject *p =&sub;
    m_vpSubjectList.push_back(p);

} // end AddSubject()

void Entity::RemoveSubject(ns_subject::Subject& sub)
{
    ns_subject::Subject * p = &sub;
    for(unsigned int i=0 ; i<m_vpSubjectList.size();i++)
    {
        if (m_vpSubjectList[i]==p)
        {
            m_vpSubjectList.erase(m_vpSubjectList.begin()+i);
        }
    } // end for loop
}


 } } // end namespaces
