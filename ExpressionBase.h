#pragma once

#include <type_traits>
#include <tuple>

#include "Interfaces/IExpression.h"
#include "Entity.h"

template<typename... Operands>
class ExpressionBase : public IExpression
{
public:
    ExpressionBase() = default;
    virtual ~ExpressionBase() override = default;

    virtual bool evaluate(Entity& component) const override final
    {
        return tupleTreat<std::tuple_size<std::tuple<Operands...>>::value>(component, getFormationValue());
    }

protected:
    virtual bool evaluate(bool first, bool second) const = 0;

private:

    template<size_t N>
    using TypeBy = typename std::tuple_element<N, std::tuple<Operands...>>::type;

    template<
            size_t N,
            typename std::enable_if<(N > 1)>::type* = nullptr
            >
    bool tupleTreat(Entity& entity, bool prev) const
    {
        return tupleTreat<N - 1>(entity, evaluate(prev, entity.get<TypeBy<N - 1>>() != nullptr));
    }

    template<
            size_t N,
            typename std::enable_if<(N == 1)>::type* = nullptr
            >
    bool tupleTreat(Entity& entity, bool prev) const
    {
        return evaluate(prev, entity.get<TypeBy<N - 1>>() != nullptr);
    }
};
