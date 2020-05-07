#pragma once

#include "ExpressionBase.h"

template<typename... Operands>
class ExpressionAllOf : public ExpressionBase<Operands...>
{
public:
    ExpressionAllOf() = default;
    virtual ~ExpressionAllOf() = default;
    virtual bool getFormationValue() override
    {
        return true;
    }

protected:
    virtual bool evaluate(bool first, bool second) const override final
    {
        return first && second;
    }
};

template<typename... Operands>
class ExpressionOneOf : public ExpressionBase<Operands...>
{
public:
    ExpressionOneOf() = default;
    virtual ~ExpressionOneOf() = default;
    virtual bool getFormationValue() override
    {
        return false;
    }

protected:
    virtual bool evaluate(bool first, bool second) const override final
    {
        return first || second;
    }
};

template<typename... Operands>
class ExpressionNoneOf : public ExpressionBase<Operands...>
{
public:
    ExpressionNoneOf() = default;
    virtual ~ExpressionNoneOf() = default;
    virtual bool getFormationValue() override
    {
        return true;
    }

protected:
    virtual bool evaluate(bool first, bool second) const override final
    {
        return not first && not second;
    }
};

template<typename... Operands>
using AllOf = ExpressionAllOf<Operands...>;

template<typename... Operands>
using OneOf = ExpressionOneOf<Operands...>;

template<typename... Operands>
using NoneOf = ExpressionNoneOf<Operands...>;
