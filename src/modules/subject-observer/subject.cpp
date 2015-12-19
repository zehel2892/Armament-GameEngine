
#include "observer.h"
#include "subject.h"
#include "entity.h" // entity.h needs forward declaration



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

void Subject::Attach(ns_entity::Entity & ent  , ns_component::Observer & obs)
{   /** We are converting the reference to a pointer to pass to std::vector
     */
    ns_component::Observer * p = &obs;
    /** First we add the Observer to the ObserverList then we add it as a Component
     *  by sending it to AddComponent function in class Entity
     */
    m_vpObserverList.push_back(p);

    ent.AddComponent(*this,obs);



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
        }
    }



}

void Subject::Notify(ns_entity::Entity & ent)
{
for(unsigned int i=0; i<m_vpObserverList.size();i++)
    {
        m_vpObserverList[i]->Update(ent);
    }

}

void Subject::GenNotification(ns_entity::Entity & ent)
{
    this->Notify(ent);

}


}} // end namespaces
