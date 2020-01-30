#include "Dummy.h"
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
