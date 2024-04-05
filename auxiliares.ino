void cFab()
{
DefaultSens ={10,2.5,-45,1.0};

R.cal_AD[0].db10m= DefaultSens.highdbm*10;  // highdbm;  voltHdbn; lowdbm; voltLdbm;
R.cal_AD[1].db10m= DefaultSens.lowdbm*10;
R.cal_AD[0].Fwd= VtomV(DefaultSens.voltHdbn);
R.cal_AD[1].Fwd = VtomV(DefaultSens.voltLdbm);
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
          R.cal_AD1[0].db10m =dbmHigh*10;
          R.cal_AD1[0].Fwd = VtomV(fwd_h);
          R.cal_AD1[0].Rev = R.cal_AD[0].Fwd;
          // Set second calibration point at 30 dB less
          R.cal_AD1[1].db10m = dbmLow*10;
          R.cal_AD1[1].Fwd = VtomV(fwd_l);
          R.cal_AD1[1].Rev = VtomV(fwd_l);  
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
          R.cal_AD2[1].Rev   = VtomV(fwd_l); 
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
          R.cal_AD3[1].Rev   = VtomV(fwd_l); 
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
          R.cal_AD4[1].Rev   = VtomV(fwd_l); 
        }
saveConfig(config_filename);
}