#pragma once

#include "../Entity.h"

class IEvent
{
protected:
	IEvent() = default;
public:
	virtual ~IEvent() = default;
	virtual Entity* getEntity() = 0;
};
