//
// Created by Christian nahuel Rivera on 30/8/19.
//

#include <gtest/gtest.h>
#include "../../src/1-programacion_dinamica/FibonnachiTopDown.h"

struct FibonnachiTopDownTest : testing::Test{
    FibonnachiTopDown *fibonnachiTopDown;

    FibonnachiTopDownTest(){
        fibonnachiTopDown = new FibonnachiTopDown();
    }

    ~FibonnachiTopDownTest(){
        delete fibonnachiTopDown;
    }
};

TEST_F(FibonnachiTopDownTest, test1){
    int number = 0;

    long actualBenefit = fibonnachiTopDown->execute(number);

    ASSERT_EQ(1, actualBenefit);
}

TEST_F(FibonnachiTopDownTest, test2){
    int number = 2;

    long actualBenefit = fibonnachiTopDown->execute(number);

    ASSERT_EQ(2, actualBenefit);
}

TEST_F(FibonnachiTopDownTest, test3){
    int number = 7;

    long actualBenefit = fibonnachiTopDown->execute(number);

    ASSERT_EQ(21, actualBenefit);
}

TEST_F(FibonnachiTopDownTest, test4){
    int number = 16;

    long actualBenefit = fibonnachiTopDown->execute(number);

    ASSERT_EQ(1597, actualBenefit);
}