cmake_minimum_required(VERSION 3.6)

project(ecsworld VERSION 0.0.1 DESCRIPTION "ECS-model for games")

set(SOURCE_FILES)
set(HEADER_FILES)

set(INTERFACES
    Interfaces/IComponent.h
    Interfaces/ISystem.h
    Interfaces/IExpression.h
    Interfaces/IEvent.h
    )

list(APPEND SOURCE_FILES
    World.cpp
    ComponentBase.cpp
    Entity.cpp
    )

list(APPEND HEADER_FILES
    ${INTERFACES}
    World.h
    ComponentBase.h
    Entity.h
    ExpressionBase.h
    Expressions.h
    System.h
    )

set(all_sources
    ${SOURCE_FILES}
    ${HEADER_FILES}
    )

add_library(ecsworld STATIC ${all_sources})
