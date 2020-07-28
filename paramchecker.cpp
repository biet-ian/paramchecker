
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

bool vitalsAreOk(float bpm, float spo2, float respRate) 
{
  return bpmOk(bpm) && spo2Ok(spo2) && respRateOk(respRate);
}
