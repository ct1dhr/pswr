//--------------------------------------------------------------------
// Multipurpose Pushbutton 
//
// Returns 0 for no push, 1 for short push and 2 for long push
// (routine should be called once every 1 ms)
//--------------------------------------------------------------------
//
// Flags for Calibrate Submenu functions
#define CAL_SET0_MENU          61  // Single level calibration
#define CAL_SET1_MENU          62  // 1st level
#define CAL_SET2_MENU          63  // 2nd level
#if PUSHBUTTON_ENABLED
uint8_t multipurpose_pushbutton(void)
{
  static uint16_t pushcount;       // Measure push button time (max 65s)
  uint8_t         state;           // 1 for push or 0 for no-push
  static uint8_t  prevstate;       // Used for clumsy debounce
  uint8_t         retstate = 0;    // 1 for short push, 2 for long push

  if (digitalRead(EnactSW) == LOW) {state = 1; }    // Pin low = pushed
  else {state = 0;}

  //-------------------------------------------------------------------    
  // Is this the end of a successful push?
  // Was state stable for a minimum number of consecutive readings?
  if ((state != prevstate) && (pushcount >= ENACT_MIN))
  {
    if (prevstate == 1)                          // Menu/Enact switch
    { 
      if (pushcount >= ENACT_MAX)                // "Long Push"
      {
        retstate = 2;                            // Indicate long push
      }
      else retstate = 1;
      
    }
    pushcount = 0;                               // set counter to zero
    prevstate = 0;
  }
    
  //-------------------------------------------------------------------    
  // Debounce and measure time of push
  // If state is not stable, then reset to no-push
  else if (state != prevstate)                   // Change of state, seed prevstate and reset counter
  {
    pushcount = 0;
    prevstate = state;
  }
  else if (state == 0)                           // Push too short, reset everything
  {
    pushcount = 0;
    prevstate = 0;
  }
  else if ((state > 0) && (state == prevstate)) pushcount++; // Count upwards if state is stable

  //-------------------------------------------------------------------    
  // Kludge, enter Config mode immediately when long push condition is satisfied
  if ((state == 1) && (pushcount >= ENACT_MAX))
  {
    retstate = 2;   
  }
  
  return retstate;
  
}
#endif