#include "paramchecker.h"
#include <gtest/gtest.h>
 
TEST(VitalsTest, BPM) { 
    ASSERT_EQ(true, bpmOk(100));
}
 
TEST(VitalsTest, SPO2) {
    ASSERT_EQ(false, spo2Ok(40));
}
 
TEST(VitalsTest, RESP_RATE) {
    ASSERT_EQ(true, respRateOk(50));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
