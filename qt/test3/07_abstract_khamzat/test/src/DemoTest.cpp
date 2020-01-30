//
// Created by student on 25.11.2019.
//
#include "TestIncludes.h"
#include <memory>
class Interface {
public:
    virtual void doSomething() = 0;
};
class Implementation : public Interface {
public:
    void doSomething() override {}
};
TEST(Dummy, Test)
{
    std::shared_ptr<Implementation> implementation = std::make_shared<Implementation>();
    std::shared_ptr<Interface> interface = std::make_shared<Implementation>();
    {
        auto copy = interface;
        { auto otherCopy = interface; }
        std::unique_ptr<Interface> unique = std::make_unique<Implementation>();
    }
}
