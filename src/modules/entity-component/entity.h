#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "subject.h"



namespace ns_armament{ namespace  ns_subject {

class Subject; // Forward declaration

}}

namespace ns_armament { namespace ns_component {
class Component; // Forward declaration
}}
namespace ns_armament { namespace ns_entity {

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



     void AddComponent(ns_subject::Subject & sub , ns_component::Observer & obs);
     void RemoveComponent(ns_subject::Subject & sub , ns_component::Observer & obs);
protected:
private:
    std::vector<ns_subject::Subject *> m_vpSubjectList;

private:
    /** Forward declarations are put here.
     * They should not be inherited as they will pollute the namespace
     */
    ns_subject::Subject * s; // Forward declaration
    ns_component::Observer *o; //Forward declaration


};

 } }
#endif // ENTITY_H
