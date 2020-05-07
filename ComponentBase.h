#pragma once

#include <string>

class ComponentBase
{
public:
    std::string getId();

protected:
    ComponentBase(std::string id);

private:
    std::string m_id;
};
