#pragma once

#include <vector>
#include <memory>
#include <type_traits>

class Entity;
class ISystem;
class IEvent;

class World
{
public:
    World() = default;

    std::vector<std::shared_ptr<Entity>> getAllEntities();
    std::vector<std::shared_ptr<Entity>> getActiveEntities();

    void addEntity(std::shared_ptr<Entity> entity);

    template<
            typename System,
            typename std::enable_if<std::is_base_of<ISystem, System>::value>::type* = nullptr
            >
    void addSystem()
    {
        m_systems.push_back(std::make_shared<System>(this));
    }

    void pushEvent(std::shared_ptr<IEvent> event);
    void update();

private:
    std::vector<std::shared_ptr<Entity>> m_entities;
    std::vector<std::shared_ptr<ISystem>> m_systems;
};
