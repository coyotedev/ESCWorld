#include "Entity.h"


Entity::Entity()
    : m_isActive(false)
	, m_markedToDestroy(false)
{

}

bool Entity::isActive() const
{
    return m_isActive;
}

void Entity::setActive(bool isActive)
{
    m_isActive = isActive;
}

bool Entity::isMarkedToDestroy() const
{
	return m_markedToDestroy;
}

void Entity::destroy()
{
	m_isActive = false;
	m_markedToDestroy = true;
}
