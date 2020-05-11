#pragma once

#include <type_traits>
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "Interfaces/IComponent.h"

class Entity
{
public:
    Entity();
    virtual ~Entity() = default;

    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;

    template<
            typename Component,
            typename std::enable_if<std::is_base_of<IComponent, Component>::value>::type* = nullptr
            >
    const std::shared_ptr<IComponent> get()
    {
        return m_components[std::type_index(typeid(Component))];
    }

    template<
            typename Component,
            typename... ComponentArgs,
            typename std::enable_if<std::is_base_of<IComponent, Component>::value>::type* = nullptr
            >
    void add(ComponentArgs&&... args)
    {
        m_components.emplace(std::type_index(typeid(Component)), std::make_shared<Component>(std::forward<ComponentArgs...>(args...)));
    }

    bool isActive();
    void setActive(bool isActive);

private:
    std::unordered_map<std::type_index, const std::shared_ptr<IComponent>> m_components;
    bool m_isActive;
};
