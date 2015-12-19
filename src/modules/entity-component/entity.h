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
        *  the Entity types possible and supported
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
      Entity(EModule modType);



public:



     void AddComponent(ns_subject::Subject & sub    , ns_component::Observer & obs);
     void RemoveComponent(ns_subject::Subject & sub , ns_component::Observer & obs);
protected:
private:
    std::vector<ns_subject::Subject *> m_vpSubjectList;
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
