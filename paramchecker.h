
enum vital_param{
  bpm,
  spo2,
  respRate,
};

struct vital{
    vital_param param;
    float val;
};

bool out_of_range(float min, float max, float val);

bool bpmOk( float bpm );

bool spo2Ok(float spo2);

bool respRateOk(float respRate);

bool vitalsAreOk(vital arr[], unsigned size ) ;

