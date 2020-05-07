#include "Entity.h"


Entity::Entity()
    : m_isActive(false)
{

}

bool Entity::isActive()
{
    return m_isActive;
}

void Entity::setActive(bool isActive)
{
    m_isActive = isActive;
}

