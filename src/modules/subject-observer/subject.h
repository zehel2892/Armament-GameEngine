#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>


/// Subject Class is the base class for all other game objects


/** we use namespace ns_armament::ns_component::ns_observer so that we can
 *  access Observer class
 */
// using namespace ns_armament::ns_component::ns_observer;
namespace ns_armament { namespace ns_entity {
  class Entity; // Forward declaration
  enum EModule{}; // Forward declaration
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
    /** Enumerations which provide easy representation of notifications
     *  NOTE : Declare the enums before any functions which want to use them
     */
     enum ENotification{

         nt_ATTACH_OBSERVER_SUCCESS,
         nt_ATTACH_OBSERVER_FAILURE,

         nt_DETACH_OBSERVER_SUCCESS,
         nt_DETACH_OBSERVER_FAILURE,

         nt_ADD_COMPONENT_SUCCESS,
         nt_ADD_COMPONENT_FAILURE,

         nt_REMOVE_COMPONENT_SUCCESS,
         nt_REMOVE_COMPONENT_FAILURE


     };

public:
  /** Public interfaces available to the class */
  /// The caller of the Attach function will be of class subject
  void Attach(ns_entity::Entity & ent ,  ns_component::Observer & obs);
  void Detach(ns_entity::Entity & ent ,  ns_component::Observer & obs);

  /** Attach Subject and its children to the given entity(whhich is like a king)
   *    \param  The (king) Entity object to whhich we want to attach the caller
   *            Subject(lords) and its Observers(citizens)
   *
   */
  void AttachTo(ns_entity::Entity & ent);
  /** Detach Subject and its children from the given entity(whhich is like a king)
   *    \param  The (king) Entity object to whhich we want to detach the caller
   *            Subject(lords) and its Observers(citizens)
   *
   */
  void DetachFrom(ns_entity::Entity & ent);


  /// Send notifications
  void Notify(ns_entity::Entity & ent , ENotification note);

  /// Generate notifications
  void GenNotification(ns_entity::Entity & ent , ENotification note);
  void GenNotification(ns_entity::EModule mod , ENotification note);


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
