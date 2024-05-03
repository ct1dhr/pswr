void cFab()
{
DefaultCPL ={10,2.5,-45,1.0,1};

R.cal_AD[0].db10m= DefaultCPL.highdbm*10;  // highdbm;  voltHdbn; lowdbm; voltLdbm;
R.cal_AD[1].db10m= DefaultCPL.lowdbm*10;
R.cal_AD[0].Fwd= VtomV(DefaultCPL.voltHdbn);
R.cal_AD[1].Fwd = VtomV(DefaultCPL.voltLdbm);
/*
R.cal_AD[0].db10m= att_cal + 100;
R.cal_AD[1].db10m= att_cal+ -450;
R.cal_AD[0].Fwd=  2.53*10000;
R.cal_AD[1].Fwd = 1.0*10000;
*/
}

void coupler_calib(int coupler_cal, int16_t dbmHigh,int16_t dbmLow,double fwd_h, double fwd_l, int att )
{
if ( coupler_cal == 1)
        {
        // First coupler
          att_c1 = att;
          R.cal_AD1[0].db10m =dbmHigh;
          R.cal_AD1[0].Fwd = fwd_h;
          R.cal_AD1[0].Rev = R.cal_AD[0].Fwd;
          // Set second calibration point at 30 dB less
          R.cal_AD1[1].db10m = dbmLow;
          R.cal_AD1[1].Fwd = fwd_l;
          R.cal_AD1[1].Rev = fwd_l;  
        }
        if ( coupler_cal == 2)
        {
        // Second coupler

          att_c2 = att;
          R.cal_AD2[0].db10m =dbmHigh;
          R.cal_AD2[0].Fwd = fwd_h;
          R.cal_AD2[0].Rev = R.cal_AD2[0].Fwd;
          // Set second calibration point at 30 dB less
          R.cal_AD2[1].db10m = dbmLow;
          R.cal_AD2[1].Fwd   = fwd_l;
          R.cal_AD2[1].Rev   = fwd_l; 
        }
        if ( coupler_cal == 3)
        {
        // Third coupler 
         att_c3 = att;
          R.cal_AD3[0].db10m = dbmHigh;
          R.cal_AD3[0].Fwd = fwd_h;
          R.cal_AD3[0].Rev = R.cal_AD3[0].Fwd;
          // Set second calibration point at 30 dB less
          R.cal_AD3[1].db10m = dbmLow;
          R.cal_AD3[1].Fwd   = fwd_l;
          R.cal_AD3[1].Rev   = fwd_l; 
        }
        if ( coupler_cal == 4)
        {
        // Fourth coupler
         att_c4 = att;
        
          R.cal_AD4[0].db10m =dbmHigh;
          R.cal_AD4[0].Fwd = fwd_h;
          R.cal_AD4[0].Rev = R.cal_AD4[0].Fwd;
          // Set second calibration point at 30 dB less
          R.cal_AD4[1].db10m = dbmLow;
          R.cal_AD4[1].Fwd   = fwd_l;
          R.cal_AD4[1].Rev   = fwd_l; 
        }
saveConfig(config_filename);
}

int escala()
{
  int esc=0;
if(fwd_power_mw > 1000000 ){esc=1;} //> 1kw 
if(fwd_power_mw > 500000 and fwd_power_mw <=1000000){esc=2;} //500w  a 1kw
if(fwd_power_mw > 100000 and fwd_power_mw <=500000){esc=3;}// 100w a 500w
if(fwd_power_mw > 50000 and fwd_power_mw <=100000){esc=4;}// 50w a 100w
if(fwd_power_mw > 10000 and fwd_power_mw <=50000){esc=5;}// 10w a 50w
if(fwd_power_mw > 1000 and fwd_power_mw <=10000){esc=6;}// 1w a 10w
if(fwd_power_mw <=1000){esc=7;}// menor do que 1w
return esc;
}// fim escala
void onePointCal(int16_t db, double volts)
{

SecondPointdB=db-300;
SecondPointVolt=volts-LOGAMP1_SLOPE * .001 * 30;
SecondPointdB1=db-300;
SecondPointVolt1=volts-LOGAMP1_SLOPE * .001 * 30;

 
}
int inteiro(double n){return floor(n);}
int frac(double n){


return n-floor(n);

}

double powerRatio(int16_t dB){

return pow(10,(dB/10));
}

bool wifi_connect(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  return true;
 } 

 int readADC_Avg(int FILTER_LEN )
{

  
  int AN_Pot1_Buffer[FILTER_LEN]; 
  Sum=0;
 int j=0;
  
  for(iconut=0; iconut<FILTER_LEN; iconut++)
  {

    float vout = analogReadMilliVolts(analogPin);
    AN_Pot1_Buffer[iconut] = vout;
    
 
  }
for(j=0; j<FILTER_LEN; j++){
Sum = Sum + AN_Pot1_Buffer[j];
}
  return (Sum/FILTER_LEN);
 
}