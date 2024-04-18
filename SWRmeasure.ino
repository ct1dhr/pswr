
void adc_poll_and_feed_circular(void)
{
#if ADS1115
    
// ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

     
  #if ADS2 

    ads0.setVoltageRange_mV(ADS1115_RANGE_6144);
    ads0.setMeasureMode(ADS1115_CONTINUOUS); 
    ads0.setCompareChannels(ADS1115_COMP_0_GND);
    volts0 = ads0.getResult_V();   // canal 0
    ads0.setCompareChannels(ADS1115_COMP_1_GND);
    volts1 = ads0.getResult_V();   // canal 1
     ads0.setCompareChannels(ADS1115_COMP_2_GND);
    volts2 = ads0.getResult_V();   // canal 2
      ads0.setCompareChannels(ADS1115_COMP_3_GND);
    volts3 = ads0.getResult_V();   // canal 3

    ads1.setVoltageRange_mV(ADS1115_RANGE_6144);
    ads1.setMeasureMode(ADS1115_CONTINUOUS); 
    ads1.setCompareChannels(ADS1115_COMP_0_GND);
    volts4 = ads1.getResult_V();   // canal 0
    ads1.setCompareChannels(ADS1115_COMP_1_GND);
    volts5 = ads1.getResult_V();   // canal 1
     ads1.setCompareChannels(ADS1115_COMP_2_GND);
    volts6 = ads1.getResult_V();   // canal 2
      ads1.setCompareChannels(ADS1115_COMP_3_GND);
    volts7 = ads1.getResult_V();   // canal 3



  #else
     adc0 = ads0.readADC_SingleEnded(0);
     adc1 = ads0.readADC_SingleEnded(1);
     adc2 = ads0.readADC_SingleEnded(2);
     adc3 = ads0.readADC_SingleEnded(3);

     volts0 = ads0.computeVolts(adc0);
     volts1 = ads0.computeVolts(adc1);
     volts2 = ads0.computeVolts(adc2);
     volts3 = ads0.computeVolts(adc3);
if(volts0 < 0.25){volts0 =0.25; }
if(volts1 < 0.24){volts1 =0.24; }
if(volts2 < 0.25){volts2 =0.25; }
if(volts3 < 0.24){volts3 =0.24; }

  #endif   
/*
 VOUT = VY log (VIN /VX) (1)
where:
 VOUT é a tensão de saída,
 VY é chamada de tensão de slope; o logaritmo geralmente é obtido
 para a base dez (nesse caso, VY também é volts por década),
 VIN é a tensão de entrada,
 and
 VX é a tensão de intercept
A adaptação front-end mostrada na Figura 39 fornece a medição da potência que está sendo entregue 
de um amplificador final do transmissor para uma antena. A gama foi definida para cobrir a potência
intervalo –30 dBm (7,07 mV rms, ou 1 μW) a +60 dBm (223 V rms,
ou 1 kW). Uma razão de atenuação de tensão nominal de 158:1 (44 dB) é
usados; assim, o intercept é movido de –84 dBm para –40 dBm e
o AD8307, dimensionado em 0,25 V/década de potência, passará a ler 1,5 V
para um nível de potência de 100 mW, 2,0 V a 10 W e 2,5 V a 1 kW.
A expressão geral é:
P (dBm) = 40 (VOUT – 1)
A atenuação necessária poderia ser implementada usando um divisor capacitivo, fornecendo uma capacitância de entrada muito baixa, mas é
difícil de garantir valores precisos de capacitores pequenos. Um melhor
é usar um divisor resistivo, tomando as precauções necessárias para minimizar o acoplamento espúrio no AD8307, colocando
numa caixa blindada, com a resistência de entrada a passar por uma
furo nesta caixa, como indicado na figura. A capacidade de acoplamento
 º---^^^^---º---||---º8  r 100k 1/2w e 51pF ligados ao pino 8
 Vr1 de  2k em serie com 604ohms ligados entre o pino 8 e o 1
 51pF do pino 1 à massa
*/
   #if TESTE_IN
      
      Serial.print(" Real Volts_fwd: ");
      Serial.print(volts0);
      Serial.print("    Teste Volts_fwd: ");
      Serial.println(vtest);
     volts0=vtest;
     volts1=0.2;
    #endif

     switch (current_coupler) {
  case 1:
      measure.fwd[measure.incount] =VtomV(volts0); // Input from AD7991 is 12 bit resolution
      measure.rev[measure.incount] = VtomV(volts1); // contained in bit positions 0 to 11.
      measure.incount++; 
    break;
  case 2:
      measure.fwd[measure.incount] =VtomV(volts2); // Input from AD7991 is 12 bit resolution
      measure.rev[measure.incount] = VtomV(volts3); // contained in bit positions 0 to 11.
      measure.incount++; 
    break;
    case 3:
      measure.fwd[measure.incount] =VtomV(volts4); // Input from AD7991 is 12 bit resolution
      measure.rev[measure.incount] = VtomV(volts5); // contained in bit positions 0 to 11.
      measure.incount++; 
    break;
    case 4:
      measure.fwd[measure.incount] =VtomV(volts6); // Input from AD7991 is 12 bit resolution
      measure.rev[measure.incount] = VtomV(volts7); // contained in bit positions 0 to 11.
      measure.incount++; 
    break;
    case 5:
      measure.fwd[measure.incount] =VtomV(vtest); // Input from AD7991 is 12 bit resolution
      measure.rev[measure.incount] = VtomV(0.2); // contained in bit positions 0 to 11.
      measure.incount++; 
    break;

  default:
    // if nothing else matches, do the default
    // default is optional
    break;

}



 #endif  // de ads1115
  
 
} //FIM adc_poll_and_feed_circular
//-----------------------------------------------------------------------------------------
//                Convert Voltage Reading into Power when using AD8307
//-----------------------------------------------------------------------------------------
//
void pswr_determine_dBm(void)
{
  double  delta_db;
  double  delta_F, delta_R;
  double  delta_Fdb, delta_Rdb;
  double  temp;

  // Calculate the slope gradient between the two calibration points:
  //
  // (dB_Cal1 - dB_Cal2)/(V_Cal1 - V_Cal2) = slope_gradient
  //
 
if(current_coupler==1)
{
  delta_db = (double)((R.cal_AD1[1].db10m - R.cal_AD1[0].db10m)/10.0);
  delta_F = R.cal_AD1[1].Fwd - R.cal_AD1[0].Fwd;
  delta_Fdb = delta_db/delta_F;
  delta_R = R.cal_AD1[1].Rev - R.cal_AD1[0].Rev;
  delta_Rdb = delta_db/delta_R;
  //
  PdBm =att_c1*(volts0 -1.0);
  PdBmRev=att_c1*(volts1-1.0); // Outra forma de calculo baseado na atenuacão e slope e intercept do datasheet
  // measured dB values are: (V - V_Cal1) * slope_gradient + dB_Cal1
      // ad8307_FdBm = (adc_ref * (fwd/4096.0) - R.cal_AD[0].Fwd) * delta_Fdb + R.cal_AD[0].db10m/10.0;
      //  ad8307_RdBm = (adc_ref * (rev/4096.0) - R.cal_AD[0].Rev) * delta_Rdb + R.cal_AD[0].db10m/10.0;
      ad8307_FdBm = (fwd - R.cal_AD1[0].Fwd) * delta_Fdb + R.cal_AD1[0].db10m/10.0;
       ad8307_RdBm =  (rev - R.cal_AD1[0].Rev) * delta_Rdb + R.cal_AD1[0].db10m/10.0;
}
if(current_coupler==2)
{
  delta_db = (double)((R.cal_AD2[1].db10m - R.cal_AD2[0].db10m)/10.0);
  delta_F = R.cal_AD2[1].Fwd - R.cal_AD2[0].Fwd;
  delta_Fdb = delta_db/delta_F;
  delta_R = R.cal_AD2[1].Rev - R.cal_AD2[0].Rev;
  delta_Rdb = delta_db/delta_R;
  //
  PdBm =att_c2*(volts2 - 1);
  PdBmRev=att_c2*(volts3 -1); // Outra forma de calculo baseado na atenuacão e slope e intercept do datasheet
  // measured dB values are: (V - V_Cal1) * slope_gradient + dB_Cal1
      // ad8307_FdBm = (adc_ref * (fwd/4096.0) - R.cal_AD[0].Fwd) * delta_Fdb + R.cal_AD[0].db10m/10.0;
      //  ad8307_RdBm = (adc_ref * (rev/4096.0) - R.cal_AD[0].Rev) * delta_Rdb + R.cal_AD[0].db10m/10.0;
      ad8307_FdBm = (fwd - R.cal_AD2[0].Fwd) * delta_Fdb + R.cal_AD2[0].db10m/10.0;
       ad8307_RdBm =  (rev - R.cal_AD2[0].Rev) * delta_Rdb + R.cal_AD2[0].db10m/10.0;
}

if(current_coupler==3)
{
  delta_db = (double)((R.cal_AD3[1].db10m - R.cal_AD3[0].db10m)/10.0);
  delta_F = R.cal_AD3[1].Fwd - R.cal_AD3[0].Fwd;
  delta_Fdb = delta_db/delta_F;
  delta_R = R.cal_AD3[1].Rev - R.cal_AD3[0].Rev;
  delta_Rdb = delta_db/delta_R;
  //
  PdBm =att_c3*(volts4 - 1);
  PdBmRev=att_c3*(volts5 - 1); // Outra forma de calculo baseado na atenuacão e slope e intercept do datasheet
  // measured dB values are: (V - V_Cal1) * slope_gradient + dB_Cal1
      // ad8307_FdBm = (adc_ref * (fwd/4096.0) - R.cal_AD[0].Fwd) * delta_Fdb + R.cal_AD[0].db10m/10.0;
      //  ad8307_RdBm = (adc_ref * (rev/4096.0) - R.cal_AD[0].Rev) * delta_Rdb + R.cal_AD[0].db10m/10.0;
      ad8307_FdBm = (fwd - R.cal_AD3[0].Fwd) * delta_Fdb + R.cal_AD3[0].db10m/10.0;
       ad8307_RdBm =  (rev - R.cal_AD3[0].Rev) * delta_Rdb + R.cal_AD3[0].db10m/10.0;
}

if(current_coupler==4)
{
  delta_db = (double)((R.cal_AD4[1].db10m - R.cal_AD4[0].db10m)/10.0);
  delta_F = R.cal_AD4[1].Fwd - R.cal_AD4[0].Fwd;
  delta_Fdb = delta_db/delta_F;
  delta_R = R.cal_AD4[1].Rev - R.cal_AD4[0].Rev;
  delta_Rdb = delta_db/delta_R;
  //
  PdBm =att_c4*(volts6 - 1); 
  PdBmRev=att_c4*(volts7 - 1); // Outra forma de calculo baseado na atenuacão e slope e intercept do datasheet
  // measured dB values are: (V - V_Cal1) * slope_gradient + dB_Cal1
      // ad8307_FdBm = (adc_ref * (fwd/4096.0) - R.cal_AD[0].Fwd) * delta_Fdb + R.cal_AD[0].db10m/10.0;
      //  ad8307_RdBm = (adc_ref * (rev/4096.0) - R.cal_AD[0].Rev) * delta_Rdb + R.cal_AD[0].db10m/10.0;
      ad8307_FdBm = (fwd - R.cal_AD4[0].Fwd) * delta_Fdb + R.cal_AD4[0].db10m/10.0;
       ad8307_RdBm =  (rev - R.cal_AD4[0].Rev) * delta_Rdb + R.cal_AD4[0].db10m/10.0;
}
if(current_coupler==5)
{
  delta_db = (double)((R.cal_AD[1].db10m - R.cal_AD[0].db10m)/10.0);
  delta_F = R.cal_AD[1].Fwd - R.cal_AD[0].Fwd;
  delta_Fdb = delta_db/delta_F;
  delta_R = R.cal_AD[1].Rev - R.cal_AD[0].Rev;
  delta_Rdb = delta_db/delta_R;
  //
  
  // measured dB values are: (V - V_Cal1) * slope_gradient + dB_Cal1
      // ad8307_FdBm = (adc_ref * (fwd/4096.0) - R.cal_AD[0].Fwd) * delta_Fdb + R.cal_AD[0].db10m/10.0;
      //  ad8307_RdBm = (adc_ref * (rev/4096.0) - R.cal_AD[0].Rev) * delta_Rdb + R.cal_AD[0].db10m/10.0;
      ad8307_FdBm = (fwd - R.cal_AD[0].Fwd) * delta_Fdb + R.cal_AD[0].db10m/10.0;
       ad8307_RdBm =  (rev - R.cal_AD[0].Rev) * delta_Rdb + R.cal_AD[0].db10m/10.0;
}

Serial.print("PdBm = ");Serial.println(PdBm);
Serial.print("PdBmREV = ");Serial.println(PdBmRev);
// Y=mx+n
  // ad8307_FdBm =0.025*volts0+MovIntercept;
  //  ad8307_RdBm =MovIntercept*(volts1-1);

  #if TESTE_IN 
   Serial.print("PdBm = ");Serial.println(PdBm);
   Serial.print("PdBmREV = ");Serial.println(PdBmRev);
    Serial.print("  measur_incom= ");
    Serial.print(measure.fwd[measure.incount]);
    
   Serial.print("  fwd= ");
    Serial.print(fwd);

    Serial.print("  dBm= ");
    Serial.print(ad8307_FdBm);
   

    Serial.print("  RdBm= ");
    Serial.print(ad8307_RdBm);

    Serial.print("  mW= ");
    Serial.print(power_mw);
    
    Serial.print("   RCalAD_fwd ");
    Serial.print(R.cal_AD[0].Fwd);
    Serial.print("   RCalAD1_fwd ");
    Serial.print(R.cal_AD[1].Fwd);
  
    Serial.print("   deltaFdb ");
    Serial.print(delta_Fdb);
    Serial.print("   RCalAD_10dbm(0) ");
    Serial.print(R.cal_AD[0].db10m);
    Serial.print("   RCalAD_AD10dbm(1) ");
    Serial.print(R.cal_AD[1].db10m);
    Serial.print("   delta_db ");
    Serial.println(delta_db);

   #endif
  // Test for direction of power - Always designate the higher power as "forward"
  // while setting the "Reverse" flag on reverse condition.

  if (ad8307_FdBm > ad8307_RdBm)        // Forward direction
  {
    Reverse = false;
  }
  else                                  // Reverse direction
  {
    temp = ad8307_RdBm;
    ad8307_RdBm = ad8307_FdBm;
    ad8307_FdBm = temp;
    Reverse = true;
  }
}


//-----------------------------------------------------------------------------------------
//                Prepare various types of power and calculate SWR
//                (these are things that can be run outside of the
//                 interrupt function, to optimize time management)
//-----------------------------------------------------------------------------------------
//
void calc_SWR_and_power(void)
{
  static double  swr_avg_buf[AVG_BUFSWR];        // a buffer of instantaneous swr measurements, for swr smoothing
  static double  swr_plus;                       // averaging: all swr measurements within a short window added together
  static uint16_t a;                             // swr avg: short ring buffer counter
  
  power_mw_pk   = pow(10,power_db_pk/10.0);
  power_mw_pep  = pow(10,power_db_pep/10.0);   
  power_mw_long = pow(10,power_db_long/10.0);   
  
  // Only calculate SWR if meaningful power

  if ((power_mw > MIN_PWR_FOR_SWR_CALC) || (power_mw < -MIN_PWR_FOR_SWR_CALC))
  {
    // Calculate SWR
    swr = (1+(r_inst/f_inst))/(1-(r_inst/f_inst));

    // Check for high SWR and set alarm flag if trigger value is exceeded
    // If trigger is 40 (4:1), then Alarm function is Off
    if ((R.SWR_alarm_trig != 40) && ((swr*10) >= R.SWR_alarm_trig) && (power_mw > R.SWR_alarm_pwr_thresh))
    {
      if (flag.swr_alarm)                        // This is the second time in a row, raise the SWR ALARM
      {
        digitalWrite(R_Led,flag.swr_alarm);      // Turn on the Alarm LED
      }
      flag.swr_alarm = true;                     // Set SWR flag - may be a one shot fluke
    }
    //else if (flag.swr_alarm)                   // Clear SWR Flag if High SWR condition does not exist
    //{
    //  flag.swr_alarm = false;                  // Alarm is cleared with a Touch Screen Push Action
    //}
  }
  
  // If some power present, but not enough for an accurate SWR reading, then use
  // recent measured value
  else if ((power_mw > MIN_PWR_FOR_SWR_SHOW) || (power_mw < -MIN_PWR_FOR_SWR_SHOW))
  {
    // Do nothing, in other words, swr remains the same
  }
  else
  {
    // No power present, set SWR to 1.0
    // swr = 1.0;
  }

  //------------------------------------------
  // Average swr reading over short period (100 ms)
  swr_avg_buf[a++] = swr;                       // Add the newest value onto ring buffer
  swr_plus = swr_plus + swr;                    // Add latest value to the total sum of all measurements in [100ms]
  if (a == AVG_BUFSWR) a = 0;                   // wrap around
  swr_plus = swr_plus - swr_avg_buf[a];         // and subtract the oldest value in the ring buffer from the total sum
  swr_avg = swr_plus / (AVG_BUFSWR-1);          // And finally, find the average
}// end func



//

//
//-----------------------------------------------------------------------------------------
//                Determine Forward and Reflected power
//                from 2x AD8307 or from Diode Detectors.
//                Also determine PEP, 100ms peak and Average, 100ms and 1s.
//-----------------------------------------------------------------------------------------
//
void pswr_sync_from_interrupt(void)
{
  uint8_t in;

//  noInterrupts();
  in = measure.incount;
//  interrupts();

  while (measure.outcount != in)              // Read from circular buffer, while new input available
  {
//    noInterrupts();



    fwd = measure.fwd[measure.outcount];      // Transfer data from circular buffers
    rev = measure.rev[measure.outcount];
//    interrupts();
    measure.outcount++;                       // 8 bit value, rolls over at 256
   
    determine_power_pep_pk();                 // Determine Instantaneous power, pep, pk and avg

  

//    noInterrupts();                           // Perhaps a bit redundant - squeeze every last drop while we're at it
    in = measure.incount;
//    interrupts();
  }
}// fim pswr_sync_from_interrupt



void determine_power_pep_pk(void)
{
  // For measurement of peak and average power
  static int32_t  buff_short[BUF_SHORT];        // voltage db information in a 100 ms window
  static int32_t  pepbuff[PEP_BUFFER];          // voltage db information in a 1, 2.5 or 5 second window
  static int32_t  longbuff[LONG_BUFFER];        // voltage db information in a 30 second window
  int32_t pk;                                   // Keep track of Max (1s) and Peak (100ms) dB voltage
  static double   p_avg_buf[AVG_BUFSHORT];      // a short buffer of all instantaneous power measurements, for short average
  static double   p_avg_buf1s[AVG_BUF1S];       // a one second buffer of instantanous power measurements, for 1s average
  static double   p_1splus;                     // averaging: all power measurements within a 1s window added together
  static double   p_plus;                       // averaging: all power measurements within a shorter window added together
  static uint16_t a;                            // Pk:  100ms ring buffer counter
  static uint16_t b;                            // PEP: ring buffer counter
  static uint16_t c;                            // Long: ring buffer counter
  static uint16_t d;                            // avg: short ring buffer counter
  static uint16_t e;                            // avg: 1s ring buffer counter

  #if AD8307_INSTALLED     
  //---------------------------------------------------------------------------------
  // Process Forward and Reflected power measurements from 2x AD8307
  //---------------------------------------------------------------------------------

  pswr_determine_dBm();                         // Determine dBm from AD8307 voltages
  
  // Instantaneous forward voltage and power, milliwatts and dBm
  f_inst = pow(10,ad8307_FdBm/20.0);		        // (We use voltage later on, for SWR calc)

  fwd_power_mw = SQR(f_inst);		// P_mw = (V*V) (current and resistance have already been factored in)
     
  
                

  // Instantaneous reverse voltage and power
  r_inst = pow(10,(ad8307_RdBm)/20.0);
  ref_power_mw = SQR(r_inst);

  


  // We need some sane boundaries (4kW) to determine reasonable variable defs for further calculations
  if (fwd_power_mw > 4000000) fwd_power_mw = 4000000;
  if (ref_power_mw > 4000000) ref_power_mw = 4000000;
  if( fwd_power_mw < MIN_PWR_FOR_SWR_CALC){fwd_power_mw=0;}
  if( ref_power_mw < MIN_PWR_FOR_SWR_CALC){ref_power_mw=0;}
  // Instantaneous Real Power Output

  fwd_power_w=fwd_power_mw/1000;
  ref_power_w=ref_power_mw/1000;
  
  power_mw = fwd_power_mw - ref_power_mw;
  power_db = 10 * log10(power_mw);  

 
 
  #else
  //---------------------------------------------------------------------------------
  // Measure Forward and Reflected power from Diode Detecotrs
  //---------------------------------------------------------------------------------
  // Test for direction of power - Always designate the higher power as "forward"
  // while setting the "Reverse" flag on reverse condition.
  if (fwd > rev)                                // Forward direction
  {
    Reverse = false;
  }
  else                                          // Reverse direction
  {
    uint16_t temp = rev;
    rev = fwd;
    fwd = temp;
    Reverse = true;
  }

  // Instantaneous forward voltage and power, milliwatts
  //
  // Establish actual measured voltage at diode
  f_inst = (double) fwd * adc_ref/4096.0;
  // Convert to VRMS in Bridge
  if (f_inst >= D_VDROP) f_inst = 1/1.4142135 * (f_inst - D_VDROP) + D_VDROP;
  // Take Bridge Coupling into account
  f_inst = f_inst * BRIDGE_COUPLING * R.meter_cal/100.0;
  // Convert into milliwatts
  fwd_power_mw = 1000 * SQR(f_inst)/50.0;
    
  // Instantaneous reflected voltage and power
  //
  // Establish actual measured voltage at diode
  r_inst = (double) rev * adc_ref/4096.0;
  // Convert to VRMS in Bridge
  if (r_inst >= D_VDROP) r_inst = 1/1.4142135 * (r_inst - D_VDROP) + D_VDROP;
  // Take Bridge Coupling into account
  r_inst = r_inst * BRIDGE_COUPLING * R.meter_cal/100.0;
  // Convert into milliwatts
  ref_power_mw = 1000 * SQR(r_inst)/50.0;
  
  // Instantaneous Real Power Output
  power_mw = fwd_power_mw - ref_power_mw;
  if (power_mw <  0) power_mw = power_mw * -1;
  power_db = 10 * log10(power_mw);

  #endif
   
  //------------------------------------------
  // Find peaks and averages

  // Multiply by 100 to make suitable for integer value
  // Store dB value in a ring buffer
  buff_short[a++] = 100 * power_db;             // Get precision of two subdecimals
  if (a == BUF_SHORT)    a = 0;

  //------------------------------------------
  // Find Peak value within a 100ms sliding window
  pk =-0x7fffffff;
  for (uint8_t x = 0; x < BUF_SHORT; x++)
  {
    if (pk < buff_short[x]) pk = buff_short[x];
  }
  power_db_pk = pk / 100.0;

  //------------------------------------------
  // Feed and Retrieve Max Value within a 1 to 5 second sliding window, 
  // while using a resolution granularity of BUF_SHORT (100ms)
  if (a == 0)                                   // Once every BUF_SHORT*SAMPLE_TIMER time
  {
    pepbuff[b++] = 100 * power_db_pk;           // Feed the PEP buffer with Pk values, precision of two subdecimals
    if (b >= R.PEP_period) b = 0;
   
    pk =-0x7fffffff;
    for (uint16_t x = 0; x < R.PEP_period; x++) // Retrieve a new PEP value
    {
      if (pk < pepbuff[x]) pk = pepbuff[x];
    }
    power_db_pep = pk / 100.0;
  }
  if (power_db_pep < power_db_pk)               // Correct for slow reaction of the above
    power_db_pep = power_db_pk;
  
  //------------------------------------------
  // Feed and Retrieve Max Value within a 30 second (or longer) sliding window
  if (b == 0)                                   // Once every PEP (1s, 2.5s or 5s) time
  {
    longbuff[c++] = 100 *power_db_pep;          // Feed the long buffer with PEP values, precision of two subdecimals
    if (c >= (LONG_BUFFER/(R.PEP_period/10))) c = 0;

    pk =-0x7fffffff;
    for (uint16_t x = 0; x < (LONG_BUFFER/(R.PEP_period/10)); x++)  // Retrieve a new LONG value
    {
      if (pk < longbuff[x]) pk = longbuff[x];
    }
    power_db_long = pk / 100.0;
  }
  if (power_db_long < power_db_pep)             // Correct for slow reaction of the above
    power_db_long = power_db_pep;
  
  //------------------------------------------
  // Determine averages, using a FIFO + add and subtract buffer methology

  //------------------------------------------
  // Average power buffers, short period (100 ms)
  p_avg_buf[d++] = power_mw;                    // Add the newest value onto ring buffer
  p_plus = p_plus + power_mw;                   // Add latest value to the total sum of all measurements in [100ms]
  if (d == AVG_BUFSHORT) d = 0;                 // wrap around
  p_plus = p_plus - p_avg_buf[d];               // and subtract the oldest value in the ring buffer from the total sum
  power_mw_avg = p_plus / (AVG_BUFSHORT-1);     // And finally, find the short period average

  //------------------------------------------
  // Average power buffers, 1 second
  p_avg_buf1s[e++] = power_mw;                  // Add the newest value onto ring buffer
  p_1splus = p_1splus + power_mw;               // Add latest value to the total sum of all measurements in 1s
  if (e == AVG_BUF1S) e = 0;                    // wrap around
  p_1splus = p_1splus - p_avg_buf1s[e];         // and subtract the oldest value in the ring buffer from the total sum
  power_mw_1savg = p_1splus / (AVG_BUF1S-1);    // And finally, find the one second period average


}