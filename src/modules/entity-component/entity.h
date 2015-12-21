#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "subject.h"



namespace ns_armament{ namespace  ns_subject {

class Subject; // Forward declaration
enum ENotification{}; // Forward declaration

}}

namespace ns_armament { namespace ns_component {
class Component; // Forward declaration
}}
namespace ns_armament { namespace ns_entity {
/// class Entity is an abstract concept and AddComponent() will be called by Subject.Attach() function
class Entity
{
public:


    /** Default constructor */
    Entity();
    /** Default destructor */
    virtual ~Entity();
    /** Copy constructor
     *  \param other Object to copy from
     */
    Entity(const Entity& other);
    /** Assignment operator
     *  \param other Object to assign from
     *  \return A reference to this
     */
    Entity& operator=(const Entity& other);


public:/** Enumerations which provide easy representation of notifications for
        *  the Entity types possible and supported.
        * WARNING : Make sure that the enums are public and defined before the
        *           functions which want to use them.
        *
        */

    enum EModule{
        en_GAME_ENGINE,
        en_PROJECT_MANAGER,
        en_PHYSICS,
        en_GRAPHICS,
        en_INPUT,
        en_ANIMATION,
        en_SCRIPT

    } ;

public:
      /** Overloaded constructors
       */
      /* Overloaded constructor for class Entity
       * \param EModule modType : which means that it will need a predefined
       *                          enum object type from the enum EModule
       * \save  Initialize the private member m_em_ModuleType with modType
       *
       * WARNING : Make sure to declare it below the enum EModule
       */
      Entity(EModule modType);

public:/** The methods which will be used to add and remove new compoents from
        *   an entity are defined here
        *
        *   NOTE: The methods AddComponent() and RemoveComponent() will be called
        *         from the Subject class method Attach(Entity &, Observer &)
        *         The user has to just call sub.Attach(ent,obs);
        *         where sub is an object of class Subject
        *               ent is an object of class Entity passed as reference
        *               obs is an object of class Observer passed as reference
        */

        /** Adds a particular Observer compoent to the given entity
         *  \param  ns_subject::Subject & sub , which is the reference of an
         *          object of class Subject defined in namespace ns_subject
         *  \param  ns_component::Observer & obs , which is the reference of an
         *          object of class Observer defined in namespace ns_component
         */
     void AddComponent(ns_subject::Subject & sub    , ns_component::Observer & obs);

        /** Adds a particular Observer compoent to the given entity
         *  \param  ns_subject::Subject & sub , which is the reference of an
         *          object of class Subject defined in namespace ns_subject
         *  \param  ns_component::Observer & obs , which is the reference of an
         *          object of class Observer defined in namespace ns_component
         */
     void RemoveComponent(ns_subject::Subject & sub , ns_component::Observer & obs);

     void AddSubject(ns_subject::Subject & sub);
     void RemoveSubject(ns_subject::Subject & sub);

protected:
private:
    std::vector<ns_subject::Subject *>m_vpSubjectList;
    std::vector<ns_component::Observer *>m_vpGlobalObserverList;
    /** The module type of the entity to be initialized by the overloaded constructor
     *  \param m_em_ModuleType means (member(m) which is an enum(em) and name is m_em_ModuleType
     *  \saves an EModule enum object
     */
    EModule m_em_ModuleType ;

private:
    /** Forward declarations are put here.
     * They should not be inherited as they will pollute the namespace
     */
    ns_subject::Subject * s; // Forward declaration
    ns_component::Observer *o; //Forward declaration


};

 } }
#endif // ENTITY_H
