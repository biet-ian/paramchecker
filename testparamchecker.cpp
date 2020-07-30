#include "paramchecker.h"
#include <gtest/gtest.h>
 
TEST(VitalsTest, when_a_vital_is_in_range_vital_range_check_is_ok) {
    VitalRangeCheck vitalChecker(60, 100);
    ASSERT_EQ(vitalChecker.measurementIsOk(70), true);
}

TEST(VitalsTest, when_a_vital_is_off_limit_it_is_reported_with_vital_id) { 
    std::vector<Measurement> measurements = {
        {bpm, 100},
        {spo2, 50},
        {respRate, 50},
    };
    auto results = vitalsAreOk(measurements);
    ASSERT_EQ(results.size(), sizeof(measurements)/sizeof(measurements[0]));
    ASSERT_EQ(results[spo2], false);
    ASSERT_EQ(results[bpm], true);
    ASSERT_EQ(results[respRate], true);
}

TEST(VitalsTest, alert_spo2_low_resprate_high ) { 
    std::vector<Measurement> measurements = {
        {bpm, 100},
        {spo2, 50},
        {respRate, 70},
    };
    auto result = vitalAlert(measurements);
    ASSERT_EQ(result, VITAL_ALERT::lung_compromised );

    std::vector<Measurement> measurements = {
        {bpm, 100},
        {spo2, 50},
        {respRate, 50},
    };
    auto result = vitalAlert(measurements);
    ASSERT_EQ(result, VITAL_ALERT::no_special_alert );
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
