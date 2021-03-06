
#include "observer.h"
#include "subject.h"
#include "entity.h" // entity.h needs forward declaration

#include <iostream>


using namespace ns_armament::ns_subject;

namespace ns_armament { namespace ns_subject {

Subject::Subject()
{
  //ctor
}

Subject::~Subject()
{
  //dtor
}

Subject::Subject(const Subject& other)
{
  //copy ctor
}

Subject& Subject::operator=(const Subject& rhs)
{
  if (this == &rhs) return *this; // handle self assignment
  //assignment operator
  return *this;
}

////////////////////////////////////////////////////////////////////////////////
//
// __PUBLIC_INTERFACE__
//
// ATTACH AND DETACH OBSERVERS
//
////////////////////////////////////////////////////////////////////////////////

/** Attach Observer to the Subject
 *  \param Reference to an object of class entity
 *  \return call to entity.AddComponent() with Reference to this and Reference to Observer object
 */

void Subject::Attach(ns_entity::Entity & ent  , ns_component::Observer & obs)
{   /** We are converting the reference to a pointer to pass to std::vector
     */
    ns_component::Observer * p = &obs;
    /** First we add the Observer to the ObserverList then we add it as a Component
     *  by sending it to AddComponent function in class Entity
     */
    m_vpObserverList.push_back(p);

    if(m_vpObserverList[m_vpObserverList.size()-1] == p)
    {

      std::cout<<"SUCCESS : Attach Observer Successfull  : nt_ATTACH_OBSERVER_SUCCESS  :"<<std::endl;
       GenNotification(ent,nt_ATTACH_OBSERVER_SUCCESS);
      ent.AddComponent(*this,obs);
    }
    else
        {
            std::cerr<<"WARNING : Attach Observer Unsuccessfull : nt_ATTACH_OBSERVER_FAILURE :"<<std::endl;
            GenNotification(ent,nt_ATTACH_OBSERVER_FAILURE);
        }
}

void Subject::Detach(ns_entity::Entity & ent , ns_component::Observer & obs)
{   /** We are converting the reference to a pointer to pass to std::vector
     */
    ns_component::Observer * p = &obs;

    for(unsigned int i=0;i<m_vpObserverList.size();i++)
    {
        if(m_vpObserverList[i]==p)
        {
        /* This is a round about way of deleting the index
         * since the position can be expressed as
         * 0+i = i;
         */
         m_vpObserverList.erase(m_vpObserverList.begin()+i);
         if(m_vpObserverList[i] != p)
         {
             GenNotification(ent,nt_DETACH_OBSERVER_SUCCESS);
         }
         else
             GenNotification(ent,nt_DETACH_OBSERVER_FAILURE);
        }
    }



}



////////////////////////////////////////////////////////////////////////////////
//
// __HELPER_METHODS__
//
// ATTACH AND DETACH SUBJECT TO AN ENTITY
//
////////////////////////////////////////////////////////////////////////////////



void Subject::AttachTo(ns_entity::Entity & ent)
{
    /** We are converting pointer this to a reference *this
     *  by de-referencing the pointer this
     */
    ent.AddSubject(*this);
}

void Subject::DetachFrom(ns_entity::Entity & ent)
{
    /** We are converting pointer this to a reference *this
     *  by de-referencing the pointer this
     */
    ent.RemoveSubject(*this);
}



////////////////////////////////////////////////////////////////////////////////
// __PUBLIC_INTERFACE__
//
// NOTIFICATION SYSTEM
////////////////////////////////////////////////////////////////////////////////



void Subject::Notify(ns_entity::Entity & ent , ENotification note)
{
for(unsigned int i=0; i<m_vpObserverList.size();i++)
    {
        m_vpObserverList[i]->Update(ent,note);
        std::cout<<note<<std::endl;
    }

}

void Subject::GenNotification(ns_entity::Entity & ent , ENotification note)
{
    this->Notify(ent,note);

}

void Subject::GenNotification(ns_entity::EModule mod , ENotification note)
{
    /// Pending
    /// This is a bad idea.
    /// Create a uniform notification system where we just pass in the Entity & ent and
    /// it will automatically figure out the EModule part
}

////////////////////////////////////////////////////////////////////////////////
// END NAMESPACES
}} // end namespaces
////////////////////////////////////////////////////////////////////////////////
