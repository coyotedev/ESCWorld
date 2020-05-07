#pragma once

class Entity;

class IExpression
{
public:
    IExpression() = default;
    virtual ~IExpression() = default;

    virtual bool evaluate(Entity&) = 0;
    virtual bool getFormationValue() = 0;
};
