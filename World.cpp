#include "World.h"

#include <algorithm>

#include "Entity.h"
#include "Interfaces/ISystem.h"
#include "Interfaces/IEvent.h"

std::vector<std::shared_ptr<Entity>> World::getAllEntities()
{
    return m_entities;
}

std::vector<std::shared_ptr<Entity>> World::getActiveEntities()
{
    std::vector<std::shared_ptr<Entity>> ret;
    for (const auto& it : m_entities)
    {
        if (it->isActive())
        {
            ret.push_back(it);
        }
    }
    return ret;
}

void World::addEntity(std::shared_ptr<Entity> entity)
{
    m_entities.push_back(entity);
}

void World::pushEvent(std::shared_ptr<IEvent> event)
{
    for (const auto& it : m_systems)
    {
        if (it->isActive())
        {
            it->handleEvent(event);
        }
    }
}

void World::update()
{
    for (const auto& it : m_systems)
    {
        if (it->isActive())
        {
            it->update();
        }
    }

	m_entities.erase
			(
				std::remove_if(m_entities.begin(), m_entities.end(), [](const std::shared_ptr<Entity>& entity){
					return entity->isMarkedToDestroy();
				})
				, m_entities.end()
			);
}
