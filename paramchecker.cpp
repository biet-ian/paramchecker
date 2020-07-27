
bool bpmOk( float bpm ) {
  
  if(bpm < 70 || bpm > 150) {
    return false;
  } 

  return true;
}

bool spo2Ok(float spo2) {

  if(spo2 < 80) {
    return false;
  } 
  
  return true;
}

bool respRateOk(float respRate) {
  
  if(respRate < 30 || respRate > 60) {
    return false;
  }

  return true;
}

