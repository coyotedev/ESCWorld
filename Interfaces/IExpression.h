#pragma once

class Entity;

class IExpression
{
public:
    IExpression() = default;
    virtual ~IExpression() = default;

    virtual bool evaluate(Entity&) const = 0;
    virtual bool getFormationValue() const = 0;
};
