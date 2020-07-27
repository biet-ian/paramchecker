#include "paramchecker.h"
#include <gtest/gtest.h>
 
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

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
