#pragma once

#include <string>

class IComponent
{
public:
    IComponent() = default;
    virtual ~IComponent() = default;

    virtual std::string getId() = 0;
};
