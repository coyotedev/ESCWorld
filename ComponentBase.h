#pragma once

#include <string>

#include "Interfaces/IComponent.h"

class ComponentBase : public IComponent
{
public:
    std::string getId();

protected:
    ComponentBase(std::string id);

private:
    std::string m_id;
};
