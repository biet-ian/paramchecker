#include "paramchecker.h"
bool out_of_range(float min, float max, float val)
{
  return val < min || val > max ;
}

bool bpmOk( float bpm ) 
{
  return !out_of_range( 70, 150, bpm );
}

bool spo2Ok(float spo2) 
{
  return !out_of_range( 80, 100, spo2 );
}

bool respRateOk(float respRate) 
{
  return !out_of_range( 30, 60, respRate );
}

typedef bool (*fp)(float);
struct vital_check{
  vital_param param;
  float min;
  float max;
  fp ok;
};

const vital_check vitals[]={
  {vital_param::bpm, 70,150, bpmOk},
  {vital_param::spo2, 80,100, spo2Ok},
  {vital_param::respRate, 30,60, respRateOk},
};

bool vitalsAreOk(vital arr[], unsigned size ) 
{
  for( unsigned v=0; v < size; v++ )
  {
      if( !vitals[arr[v].param].ok(arr[v].val) )
      { 
        return false;
      }
  }
  return true;
}
