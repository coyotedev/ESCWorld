#pragma once

#include <vector>
#include <memory>

#include "Interfaces/ISystem.h"
#include "Interfaces/IExpression.h"
#include "Interfaces/IEvent.h"
#include "World.h"

template<typename... Expressions>
class System : public ISystem
{
public:
    virtual std::vector<std::shared_ptr<Entity>> getEntities() override final
    {
        std::vector<std::shared_ptr<Entity>> ret;
        const auto activeEntities = mp_world->getActiveEntities();

        for (auto it : activeEntities)
        {
            const auto passed = [this, it]()
            {
                for (const auto& itFilter : m_filters)
                {
                    if (not itFilter->evaluate(*it.get()))
                    {
                        return false;
                    }
                }
                return true;
            }();

            if (passed)
            {
                ret.push_back(it);
            }
        }

        return ret;
    }

    virtual void setActive(bool isActive) override
    {
        m_isActive = isActive;
    }

    virtual bool isActive() override
    {
        return m_isActive;
    }

	virtual void handleEvent(std::shared_ptr<IEvent> e) override final
	{
		for (const auto& it : m_filters)
		{
			if (!it->evaluate(*e->getEntity()))
			{
				return;
			}
		}
		handleEventImpl(e);
	}

protected:
    System(World* p_World)
        : mp_world(p_World)
        , m_isActive(true)
    {
        CollectFilters<std::tuple_size<std::tuple<Expressions...>>::value>();
    }

    virtual World* getWorld() override final
    {
	return mp_world;
    }

	virtual void handleEventImpl(std::shared_ptr<IEvent>) = 0;

private:
    template<size_t N>
    using TypeBy = typename std::tuple_element<N, std::tuple<Expressions...>>::type;

    template<
            size_t N,
            typename std::enable_if<(N > 1)>::type* = nullptr
            >
    void CollectFilters()
    {
        ConstructFilter<N - 1>();
        return CollectFilters<N - 1>();
    }

    template<
            size_t N,
            typename std::enable_if<(N == 1)>::type* = nullptr
            >
    void CollectFilters()
    {
        ConstructFilter<N - 1>();
    }

    template<size_t N>
    void ConstructFilter()
    {
        m_filters.push_back(std::unique_ptr<TypeBy<N>>(new TypeBy<N>));
    }

    World* mp_world;
    std::vector<std::unique_ptr<IExpression>> m_filters;
    bool m_isActive;
};
