#include "Dummy.h"
#include "Obsevable.h"
#include "Displacement.h"
#include "Speed.h"
#include "Acceleration.h"
#include "TestIncludes.h"
TEST(Dummy, Integrate_SingleElement)
{
    Dummy dummy{};
    EXPECT_EQ(3, dummy.integrate(3, 3));
}
TEST(Dummy, Integrate_ThreeElements)
{
    Dummy dummy{};
    EXPECT_EQ(12, dummy.integrate(3, 5));
}
TEST(Observers, ObTest)
{
    Displacement d{};
    Acceleration a{};
    Speed s{};
    d.registerObserver(&s);
    d.registerObserver(&a);
    d.set(10);
    d.set(11);
    EXPECT_EQ(1, s.get());
    d.set(13);
    EXPECT_EQ(2, s.get());
    EXPECT_EQ(1,a.get());
}
