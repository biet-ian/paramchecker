#include "paramchecker.h"
#include <gtest/gtest.h>

TEST(VitalsTest, RANGE) { 
    ASSERT_EQ(false, out_of_range( -1,2,0) );
    ASSERT_EQ(true, out_of_range(-1,2,2.001) );
    ASSERT_EQ(true, out_of_range(-1,2,-1.001) );
}

TEST(VitalsTest, BPM) { 
    ASSERT_EQ(true, bpmOk(100));
    ASSERT_EQ(false, bpmOk(69));
    ASSERT_EQ(false, bpmOk(151));
}

TEST(VitalsTest, SPO2) {
    ASSERT_EQ(false, spo2Ok(40));
    ASSERT_EQ(true, spo2Ok(80.0));
}
 
TEST(VitalsTest, RESP_RATE) {
    ASSERT_EQ(true, respRateOk(50));
    ASSERT_EQ(false, respRateOk(29.99));
    ASSERT_EQ(false, respRateOk(60.01));
}

TEST(VitalsTest, VITALS) {
    ASSERT_EQ(true, vitalsAreOk(100,80,50));
    ASSERT_EQ(false, vitalsAreOk(69,80,50));
    ASSERT_EQ(false, vitalsAreOk(0,0,0));
    ASSERT_EQ(false, vitalsAreOk(101,0,61));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
