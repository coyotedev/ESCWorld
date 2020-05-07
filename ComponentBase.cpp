#include "ComponentBase.h"

std::string ComponentBase::getId()
{
    return m_id;
}

ComponentBase::ComponentBase(std::string id)
    : m_id(id)
{
}
