[![Total alerts](https://img.shields.io/lgtm/alerts/g/coyotedev/ESCWorld.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/coyotedev/ESCWorld/alerts/)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/a0700324e7024fbe979a0a8bf34d28ef)](https://www.codacy.com/manual/coyotedev/ESCWorld?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=coyotedev/ESCWorld&amp;utm_campaign=Badge_Grade)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/coyotedev/ESCWorld.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/coyotedev/ESCWorld/context:cpp)

What's this?
=====
It's my simple implementation of Entity-Component-System pattern.

How to use?
=====
Define your own components derived from ```ComponentBase```:
```
class TestComponent1 : public ComponentBase
{
public:
    TestComponent1(std::string id)
        : ComponentBase(id)
    {
    }
};

...

class TestComponent4 : public ComponentBase
{
public:
    TestComponent1(std::string id)
        : ComponentBase(id)
    {
    }
};
```

Define your own systems derived from ```System``` with some component filters, such as ```AllOf```, ```OneOf``` or ```NoneOf``` from [`Expressions.h`](https://github.com/coyotedev/ESCWorld/blob/master/Expressions.h):
```
class TestSystem : public System<AllOf<TestComponent1, TestComponent2>, OneOf<TestComponent3, TestComponent4>>
{
public:
    TestSystem(World* p_World)
        : System(p_World)
    {
    }

    virtual void handleEvent(std::shared_ptr<IEvent>)
    {
    	//Here you go with some code of your system's reaction upon events, comes from another systems
    }
    virtual void update()
    {
    	//Here you go with some code of your system's treating entities
    }
};
```

And then you do something like this:
```
std::shared_ptr<Entity> test = std::make_shared<Entity>();
test->add<TestComponent1>("nullptr1");
test->add<TestComponent2>("nullptr2");
test->add<TestComponent3>("nullptr3");

std::shared_ptr<Entity> test1 = std::make_shared<Entity>();
test1->add<TestComponent1>("1nullptr1");
test1->add<TestComponent2>("1nullptr2");
test1->add<TestComponent3>("1nullptr3");

World w;
w.addEntity(test);
w.addEntity(test1);
w.addSystem<TestSystem>();
```

Don't forget to use [`World::update()`](https://github.com/coyotedev/ESCWorld/blob/b533b8d0a37f178a76aa7eb2e613799ce1214538/World.h#L31) in your gameloop tick handler.
