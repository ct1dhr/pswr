/*__________________________________________________________________
                   TRIGGER  1
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
// trigger dado pelos botões
void trigger1() // actualizar coupler 1

{



   String s1_value="i";
// no botão event printh 23 02 54 xx     xx = ao numero do trigger
         dbm1_s1 = nex.readNumber("x3.val");  // valor mais alto em dbm 
         dbm1_s1 = nex.readNumber("x3.val");
         dbm1_s1=dBmC(dbm1_s1/Fnex);
         
         dbm2_s1 =nex.readNumber("x7.val");  // valor mais baixo em dbm 
         dbm2_s1 = nex.readNumber("x7.val");
         dbm2_s1=dBmC(dbm2_s1/Fnex);

         volt1_s1= nex.readNumber("x5.val");  //tensão para o valor dBm mais alto
         volt1_s1= nex.readNumber("x5.val"); 
          volt1_s1=VtomV(volt1_s1/Fnex);
      
         volt2_s1= nex.readNumber("x9.val");  //tensão para o valor dBm mais baixo
         volt2_s1= nex.readNumber("x9.val");
         volt2_s1=VtomV(volt2_s1/Fnex);
       
         att_s1= nex.readNumber("x0.val");
         att_s1= nex.readNumber("x0.val");
         att_c1=att_s1/Fnex;

        s1_value=nex.readStr("send_value.txt");
        s1_value=nex.readStr("send_value.txt");

        vtest=nex.readNumber("xt.val");
        vtest=nex.readNumber("xt.val");
       Serial.print("trigger1  ");Serial.print(dbm1_s1);
         vtest=vtest/Fnex;


  /*
        R.cal_AD[0].Fwd = adc_ref * volts0;
       R.cal_AD[0].Fwd =volt1_s1*1000;
        R.cal_AD[0].Rev = R.cal_AD[0].Fwd;
        // Defina o segundo ponto de calibração em 30 dB menos
        R.cal_AD[1].db10m = R.cal_AD[0].db10m - 300;
        R.cal_AD[1].Fwd = R.cal_AD[0].Fwd - LOGAMP1_SLOPE * .001 * 30;
        R.cal_AD[1].Rev = R.cal_AD[0].Fwd - LOGAMP2_SLOPE * .001 * 30;


        */

 //_______________________________________________________________________________
 // coupler_calib(int coupler_cal, int16_t dbmHigh,int16_t dbmLow,double fwd_h, double fwd_l )

coupler_calib(1, dbm1_s1,dbm2_s1,volt1_s1, volt2_s1,att_c1);

 //______________________________________________________________________________

  
   refreshPage2();


}
/*__________________________________________________________________
                   TRIGGER  2
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger2()  // actualizar coupler 2
{
//ATT_x02 dBm_h_x32 volt_hx52 dBd_H_x72 Volt_L_x92
   
  String s1_value="i";
// no botão event printh 23 02 54 xx     xx = ao numero do trigger
         dbm1_s2 = nex.readNumber("x32.val");  // valor mais alto em dbm 
         dbm1_s2 = nex.readNumber("x32.val");
         dbm1_s2=dBmC(dbm1_s2/Fnex);
         
         dbm2_s2 =nex.readNumber("x72.val");  // valor mais baixo em dbm 
         dbm2_s2 = nex.readNumber("x72.val");
         dbm2_s2=dBmC(dbm2_s2/Fnex);

          volt1_s2= nex.readNumber("x52.val");  //tensão para o valor dBm mais alto
         volt1_s2= nex.readNumber("x52.val"); 
          volt1_s2= VtomV(volt1_s2/Fnex);
      
         volt2_s2= nex.readNumber("x92.val");  //tensão para o valor dBm mais baixo
         volt2_s2= nex.readNumber("x92.val");
         volt2_s2=VtomV(volt2_s2/Fnex);
       
         att_s2= nex.readNumber("x0.val");
         att_s2= nex.readNumber("x0.val");
         att_c2=att_s2/Fnex;

        s1_value=nex.readStr("send_value.txt");
        s1_value=nex.readStr("send_value.txt");

        vtest=nex.readNumber("xt.val");
        vtest=nex.readNumber("xt.val");
       
         vtest=vtest/Fnex;

  
  
// coupler_calib(int coupler_cal, int16_t dbmHigh,int16_t dbmLow,double fwd_h, double fwd_l )

coupler_calib(2, dbm1_s2,dbm2_s2,volt1_s2, volt2_s2, att_c2);

//______________________________________________________________________________
   
  
   refreshPage3();




 }  // fim trigger 2
/*__________________________________________________________________
                   TRIGGER  3
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger3() //  // actualizar coupler 3
{
//ATT_x02 dBm_h_x32 volt_hx52 dBd_H_x72 Volt_L_x92
   
  String s1_value="i";
// no botão event printh 23 02 54 xx     xx = ao numero do trigger
         dbm1_s3 = nex.readNumber("x33.val");  // valor mais alto em dbm 
         dbm1_s3 = nex.readNumber("x33.val");
         dbm1_s3=  dBmC(dbm1_s3/Fnex);
         
         dbm2_s3 =nex.readNumber("x73.val");  // valor mais baixo em dbm 
         dbm2_s3 = nex.readNumber("x73.val");
        
         dbm2_s3= dBmC(dbm2_s3/Fnex);

         volt1_s3= nex.readNumber("x53.val");  //tensão para o valor dBm mais alto
         volt1_s3= nex.readNumber("x53.val"); 
          volt1_s3= VtomV(volt1_s3/Fnex);
      
          volt2_s3= nex.readNumber("x93.val");  //tensão para o valor dBm mais baixo
         volt2_s3= nex.readNumber("x93.val");
         volt2_s3= VtomV(volt2_s3/Fnex);
       
         att_s3= nex.readNumber("x0.val");
         att_s3= nex.readNumber("x0.val");
         att_c3=att_s3/Fnex;

        s1_value=nex.readStr("send_value.txt");
        s1_value=nex.readStr("send_value.txt");

        vtest=nex.readNumber("xt.val");
        vtest=nex.readNumber("xt.val");
       
         vtest=vtest/Fnex;
Serial.print("trigger1  ");Serial.print(dbm1_s1);

  
// coupler_calib(int coupler_cal, int16_t dbmHigh,int16_t dbmLow,double fwd_h, double fwd_l )

coupler_calib(3, dbm1_s3,dbm2_s3,volt1_s3, volt2_s3,att_c3);

//______________________________________________________________________________
 
  
   refreshPage4();





}// fim do trigger 3
/*__________________________________________________________________
                   TRIGGER  4
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger4()  /// actualizar coupler 4
{

//ATT_x02 dBm_h_x32 volt_hx52 dBd_H_x72 Volt_L_x92
   
  String s1_value="i";
// no botão event printh 23 02 54 xx     xx = ao numero do trigger
        dbm1_s4 = nex.readNumber("x34.val");  // valor mais alto em dbm 
         dbm1_s4 = nex.readNumber("x34.val");
         dbm1_s4= dBmC(dbm1_s4/Fnex);
         
         dbm2_s4 =nex.readNumber("x74.val");  // valor mais baixo em dbm 
         dbm2_s4 = nex.readNumber("x74.val");
         dbm2_s4= dBmC(dbm2_s4/Fnex);

        volt1_s4= nex.readNumber("x54.val");  //tensão para o valor dBm mais alto
         volt1_s4= nex.readNumber("x54.val"); 
          volt1_s4= VtomV(volt1_s4/Fnex);
      
         volt2_s4= nex.readNumber("x94.val");  //tensão para o valor dBm mais baixo
         volt2_s4= nex.readNumber("x94.val");
         volt2_s4= VtomV(volt2_s4/Fnex);
       
         att_s4= nex.readNumber("x0.val");
         att_s4= nex.readNumber("x0.val");
         att_c4=att_s4/Fnex;

        s1_value=nex.readStr("send_value.txt");
        s1_value=nex.readStr("send_value.txt");

        vtest=nex.readNumber("xt.val");
        vtest=nex.readNumber("xt.val");
       
         vtest=vtest/Fnex;

  
// coupler_calib(int coupler_cal, int16_t dbmHigh,int16_t dbmLow,double fwd_h, double fwd_l )

coupler_calib(4, dbm1_s4,dbm2_s4,volt1_s4, volt2_s4,att_c4);

//______________________________________________________________________________
 
  
   refreshPage5();




}// fim do trigger 4
/*__________________________________________________________________
                   TRIGGER  5
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger5()
{

cFab();


         att_s1= nex.readNumber("x0.val")/100;
         att_s1= nex.readNumber("x0.val")/100;    
          vtest=nex.readNumber("xt.val");
        vtest=nex.readNumber("xt.val");
       
         vtest=vtest/100;


att_cal=att_s1;


         nex.writeNum("x2.val",(R.cal_AD[0].db10m*100)/10);
         nex.writeNum("x2.val",(R.cal_AD[0].db10m*100)/10);

         nex.writeNum("x6.val",(R.cal_AD[1].db10m*100)/10);
         nex.writeNum("x6.val",(R.cal_AD[1].db10m*100)/10);

         nex.writeNum("x4.val",(mVtoV(R.cal_AD[0].Fwd)*100));
         nex.writeNum("x4.val",(mVtoV(R.cal_AD[0].Fwd)*100));

         nex.writeNum("x4.val",(mVtoV(R.cal_AD[1].Fwd)*100));
         nex.writeNum("x4.val",(mVtoV(R.cal_AD[1].Fwd)*100));


        



refreshPage2();



}// fim do trigger 5
/*__________________________________________________________________
                   TRIGGER  6
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger6()
{

     current_coupler= 1;
/*
          R.cal_AD[0].db10m =R.cal_AD1[0].db10m;
          R.cal_AD[0].Fwd = R.cal_AD1[0].Fwd;
          R.cal_AD[0].Rev = R.cal_AD1[0].Rev;
          // Set second calibration point at 30 dB less
          R.cal_AD[1].db10m = R.cal_AD1[1].db10m;
          R.cal_AD[1].Fwd = R.cal_AD1[1].Fwd;
          R.cal_AD[1].Rev = R.cal_AD1[1].Rev;  
*/
}// fim do trigger 6
/*__________________________________________________________________
                   TRIGGER  7
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger7()
{



}// fim do trigger 7
/*__________________________________________________________________
                   TRIGGER  8
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger8()
{

  current_coupler= 2;
/*
          R.cal_AD[0].db10m =R.cal_AD2[0].db10m;
          R.cal_AD[0].Fwd = R.cal_AD2[0].Fwd;
          R.cal_AD[0].Rev = R.cal_AD2[0].Rev;
          // Set second calibration point at 30 dB less
          R.cal_AD[1].db10m = R.cal_AD2[1].db10m;
          R.cal_AD[1].Fwd = R.cal_AD2[1].Fwd;
          R.cal_AD[1].Rev = R.cal_AD2[1].Rev;  
          */
}// fim do trigger 8
/*__________________________________________________________________
                   TRIGGER  9
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger9()
{



}// fim do trigger 9
/*__________________________________________________________________
                   TRIGGER  10
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger10()
{

current_coupler= 3;

/*
          R.cal_AD[0].db10m =R.cal_AD3[0].db10m;
          R.cal_AD[0].Fwd = R.cal_AD3[0].Fwd;
          R.cal_AD[0].Rev = R.cal_AD3[0].Rev;
          // Set second calibration point at 30 dB less
          R.cal_AD[1].db10m = R.cal_AD3[1].db10m;
          R.cal_AD[1].Fwd = R.cal_AD3[1].Fwd;
          R.cal_AD[1].Rev = R.cal_AD3[1].Rev;  
*/
}// fim do trigger 10
/*__________________________________________________________________
                   TRIGGER  11
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger11()
{



}// fim do trigger 11
/*__________________________________________________________________
                   TRIGGER  12
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger12()
{

current_coupler= 4;

/*
          R.cal_AD[0].db10m =R.cal_AD4[0].db10m;
          R.cal_AD[0].Fwd = R.cal_AD4[0].Fwd;
          R.cal_AD[0].Rev = R.cal_AD4[0].Rev;
          // Set second calibration point at 30 dB less
          R.cal_AD[1].db10m = R.cal_AD4[1].db10m;
          R.cal_AD[1].Fwd = R.cal_AD4[1].Fwd;
          R.cal_AD[1].Rev = R.cal_AD4[1].Rev;  
*/
}// fim do trigger 12
/*__________________________________________________________________
                   TRIGGER  13
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger13(){
current_coupler =1;
coupler_name[0]= nex.readStr("t1.txt");
saveConfig(config_filename);
}

/*__________________________________________________________________
                   TRIGGER  14
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger14(){
 current_coupler= 2;
coupler_name[1]= nex.readStr("t2.txt");
saveConfig(config_filename);
}

/*__________________________________________________________________
                   TRIGGER  15
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger15(){
  current_coupler= 3;
coupler_name[2]= nex.readStr("t3.txt");
saveConfig(config_filename);
}

/*__________________________________________________________________
                   TRIGGER  16
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger16(){
 current_coupler= 4; 
coupler_name[3]= nex.readStr("t4.txt");
saveConfig(config_filename);

}

/*__________________________________________________________________
                   TRIGGER  17
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger17(){
nex.writeStr("tlk.txt",String(linkOTA));
saveConfig(config_filename);
}

/*__________________________________________________________________
                   TRIGGER  18
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger18(){


}

/*__________________________________________________________________
                   TRIGGER  19  (hex 13)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void trigger19(){
 current_coupler= 5; 
coupler_name[4]= nex.readStr("t9.txt");

 vtest=nex.readNumber("xt.val");
        vtest=nex.readNumber("xt.val");
       
         vtest=vtest/100;
saveConfig(config_filename);
}
