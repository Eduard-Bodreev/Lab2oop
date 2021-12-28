#include "../tesrc/pascal.hpp"
#include <gtest/gtest.h>
#include <cassert>


TEST(curve, setget){
    double a = 0.5, l = 1.7;
    Limacon li(a, l), ra;
    
    EXPECT_DOUBLE_EQ(0.0, ra.getA());
    EXPECT_DOUBLE_EQ(0.0, ra.getL());
    EXPECT_DOUBLE_EQ(0.5, li.getA());
    EXPECT_DOUBLE_EQ(1.7, li.getL());

    EXPECT_ANY_THROW(Limacon(-1.0, 1));
    EXPECT_ANY_THROW(Limacon(1.0, -1));

    li.setA(12);
    EXPECT_DOUBLE_EQ(12.0, li.getA());
    EXPECT_ANY_THROW(li.setA(-2));
    EXPECT_ANY_THROW(li.setL(-1));
}

TEST(curve, dist){
    Limacon li(0,0);
    EXPECT_DOUBLE_EQ(0, li.getCentDist(3.234));
}

TEST(curve, type){
    ASSERT_TRUE(Types::point == Limacon(0,0).getType());
    ASSERT_TRUE(Types::looped == Limacon(2,1).getType());
    ASSERT_TRUE(Types::cardioid == Limacon(1.7,1.7).getType());
    ASSERT_TRUE(Types::circle == Limacon(0,0.1).getType());
    ASSERT_TRUE(Types::circle == Limacon(0.1,0).getType());
    ASSERT_TRUE(Types::kinked == Limacon(2,3).getType());
    ASSERT_TRUE(Types::oval == Limacon(2.1,5.8).getType());   
}

TEST(curve, radius){
    Limacon li(2,  1);
    ASSERT_TRUE(li.getCurvativeRadius().size() == 3);
    ASSERT_TRUE(Limacon(1.2, 2.3).getCurvativeRadius().size() == 2);
    EXPECT_DOUBLE_EQ(Limacon(0, 1.22343).getCurvativeRadius()[0], 1.22343);
}

TEST(curve, text){
    Limacon li(1.2, 2.3);
    char* x = li.getText();
    ASSERT_TRUE(std::string(x) == std::string("(x^2 + y^2 - 1.200000 * x)^2 = 5.290000*(x^2 + y^2)"));
delete[] x;
}

TEST(curve, area){
    Limacon li(5.7, 5.7);
    EXPECT_DOUBLE_EQ(li.getArea(), pi*1.5*5.7*5.7);
    EXPECT_DOUBLE_EQ(0.0, Limacon(0,0).getArea());
    EXPECT_DOUBLE_EQ(pi, Limacon(0, 1).getArea());
}


int main(){
    srand(time(0));
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
