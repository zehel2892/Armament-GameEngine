#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>





/** we use namespace ns_armament::ns_component::ns_observer so that we can
 *  access Observer class
 */
// using namespace ns_armament::ns_component::ns_observer;
namespace ns_armament { namespace ns_entity {
  class Entity; // Forward declaration
   }}

namespace ns_armament { namespace ns_component {
  class Observer; // Forward declaration
 }}
namespace ns_armament { namespace ns_subject {
class Subject
{
public:


    Subject();
    virtual ~Subject();
    /** Copy constructor
     *  \param other Object to copy from
     */
    Subject(const Subject& other);
    /** Assignment operator
     *  \param other Object to assign from
     *  \return A reference to this
     */
    Subject& operator=(const Subject& other);

public:
  /** Public interfaces available to the class */
  /// The caller of the Attach function will be of class subject
  void Attach(ns_entity::Entity & ent ,  ns_component::Observer & obs);
  void Detach(ns_entity::Entity & ent ,  ns_component::Observer & obs);
  /// Send notifications
  void Notify(ns_entity::Entity & ent);

  /// Generate notifications
  void GenNotification(ns_entity::Entity & ent );


protected:
private:
    /** Private members available to the class */
    /** Observer list
     *  \param Observer * : pointer to Observer class Object
     *  \return none
     *  \save Observer list
     */
    std::vector<ns_component::Observer *> m_vpObserverList;

private:
    /** Forward declarations are put here.
     * They should not be inherited as they will pollute the namespace
     */
      ns_entity::Entity * e;




};

}}

#endif // SUBJECT_H
