#pragma once

#include <vector>
#include <memory>

class Entity;
class IEvent;
class World;

class ISystem
{
public:
    ISystem() = default;
    virtual ~ISystem() = default;

    virtual std::vector<std::shared_ptr<Entity>> getEntities() = 0;
    virtual void handleEvent(std::shared_ptr<IEvent>) = 0;
    virtual void update() = 0;
    virtual void setActive(bool) = 0;
    virtual bool isActive() = 0;
	virtual World* getWorld() = 0;
};
