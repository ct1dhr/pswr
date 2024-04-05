
 void firstRefresh() {
  

        
          if(nex.currentPageId != nex.lastCurrentPageId){ 
            
            newPageLoaded = true;               
            switch(nex.currentPageId){
              case 0:
                refreshPage0();
                break;
              
              case 1:
                refreshPage1();
                break;
                
              case 2:
                refreshPage2();
                break;
        
              case 3:
                refreshPage3();
                break;
              case 4:
                refreshPage4();
                break;
                
           
            }
            
            newPageLoaded = false; 
            
            nex.lastCurrentPageId = nex.currentPageId;
          }
    }

    void refereshCurrentPage() {
     
        if ((millis() - pageRefreshTimer) > DATA_REFRESH_RATE) {
         
              
                switch(nex.currentPageId){
                  case 0:
                    refreshPage0();
                    break;
                  
                  case 1:
                    refreshPage1();
                    break;
                    
                  case 2:
                    refreshPage2();
                    break;
            
                  case 3:
                    refreshPage3();
                    break;
                    
                  case 4:
                    refreshPage4();
                    break;
                    
                 
                 
                }
                pageRefreshTimer = millis();
        } else {
            
        }
    }

    void refreshPage0() {
        /*
        text1 = nex.readStr("t1.txt") ;
        text1 = nex.readStr("t1.txt") ;
                
        text2 = nex.readStr("t2.txt") ;
        text2 = nex.readStr("t2.txt") ;
            
         
        nex.writeStr("t3.txt","mecha") ;
        nex.writeStr("t3.txt","mecha") ;
                
        nex.writeStr("t4.txt","Eng") ;
        nex.writeStr("t4.txt","Eng") ;
      
        Serial.println("") ;

        Serial.print("text 1 is "   ) ;
        Serial.println(text1) ;
        Serial.print("text 2 is "   ) ;
        Serial.println(text2) ;
        Serial.println("page 0") ;
        */
    }

    void refreshPage1() {
     
    }

    void refreshPage2() // CPL 1
    {
 
      static int16_t  current_selection;   
      uint8_t cal_set; // Determine whether CAL_SET0, CAL_SET1 or CAL_SET2

  
        //   current_selection = R.cal_AD[cal_set].db10m;
     //digitalWrite(coupler_sw, HIGH); // coupler 1 active
   
      if(!leitura_c1){
      readConfig(config_filename);
      }
      leitura_c1=true;

        int att1 = att_cal;
       int16_t dbm10a=R.cal_AD1[0].db10m;
       int16_t dbm10b=R.cal_AD1[1].db10m;
       double fwdx1=mVtoV(R.cal_AD1[0].Fwd);
       double fwdx2=mVtoV(R.cal_AD1[1].Fwd);
       int16_t db10m1;
       int16_t db10m2;
       float fwdxa;
       float fwdxb;

       db10m1 = (dbm10a/10);
       db10m2 = (dbm10b/10);
       fwdxa= (fwdx1)*Fnex;
       fwdxb= (fwdx2)*Fnex;
 
        nex.writeNum("x2.val",db10m1*Fnex);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x2.val",db10m1*Fnex);

         nex.writeNum("x6.val",db10m2*Fnex);
         nex.writeNum("x6.val",db10m2*Fnex);

         nex.writeNum("x4.val",fwdxa);
         nex.writeNum("x4.val",fwdxa); 

         nex.writeNum("x8.val",fwdxb);
         nex.writeNum("x8.val",fwdxb);
          

          
        

        nex.writeNum("x10.val",volts0*Fnex);
       // nex.writeNum("x1.val0",volts0*100);

         nex.writeNum("x1.val",att_cal*Fnex);
         nex.writeNum("x1.val",att_cal*Fnex);



    }//refresh page2



    void refreshPage3() //  CPL 2
    {
      //ATT_x02 dBm_h_x32 volt_hx52 dBd_H_x72 Volt_L_x92
      // x10 x1 x2 x4 x6 x8

     if(!leitura_c2){
      readConfig(config_filename);
      }
      leitura_c2=true; 

       double dbm10a=R.cal_AD2[0].db10m;
       double dbm10b=R.cal_AD2[1].db10m;
       double fwdx1=mVtoV(R.cal_AD2[0].Fwd);
       double fwdx2=mVtoV(R.cal_AD2[1].Fwd);
       float db10m1;
       float db10m2;
       float fwdxa;
       float fwdxb;

       db10m1 = (dbm10a/10);
       db10m2 = (dbm10b/10);
       fwdxa= (fwdx1)*Fnex;
       fwdxb= (fwdx2)*Fnex;
 
        nex.writeNum("x2.val",db10m1*Fnex);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x2.val",db10m1*Fnex);

         nex.writeNum("x6.val",db10m2*Fnex);
         nex.writeNum("x6.val",db10m2*Fnex);

         nex.writeNum("x4.val",fwdxa);
         nex.writeNum("x4.val",fwdxa); 

         nex.writeNum("x8.val",fwdxb);
         nex.writeNum("x8.val",fwdxb);
          

          
        

        nex.writeNum("x10.val",volts0*Fnex);
       // nex.writeNum("x1.val0",volts0*100);

//___________________________
    }// fim refreshPage3

    void refreshPage4() // CPL 3
    {

if(!leitura_c3){
      readConfig(config_filename);
      }
      leitura_c3=true;

       double dbm10a=R.cal_AD3[0].db10m;
       double dbm10b=R.cal_AD3[1].db10m;
       double fwdx1=mVtoV(R.cal_AD3[0].Fwd);
       double fwdx2=mVtoV(R.cal_AD3[1].Fwd);
       float db10m1;
       float db10m2;
       float fwdxa;
       float fwdxb;

       db10m1 = (dbm10a/10);
       db10m2 = (dbm10b/10);
       fwdxa= (fwdx1)*Fnex;
       fwdxb= (fwdx2)*Fnex;
 
        nex.writeNum("x2.val",db10m1*Fnex);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x2.val",db10m1*Fnex);

         nex.writeNum("x6.val",db10m2*Fnex);
         nex.writeNum("x6.val",db10m2*Fnex);

         nex.writeNum("x4.val",fwdxa);
         nex.writeNum("x4.val",fwdxa); 

         nex.writeNum("x8.val",fwdxb);
         nex.writeNum("x8.val",fwdxb);
          

          
        

        nex.writeNum("x10.val",volts0*Fnex);
       // nex.writeNum("x1.val0",volts0*100);

         nex.writeNum("x1.val",att_cal*Fnex);
         nex.writeNum("x1.val",att_cal*Fnex);






    }// fim refreshPage4

    void refreshPage5() // CPL 4
    {
     
if(!leitura_c4){
      readConfig(config_filename);
      }
      leitura_c4=true;

      double dbm10a=R.cal_AD4[0].db10m;
       double dbm10b=R.cal_AD4[1].db10m;
       double fwdx1=mVtoV(R.cal_AD4[0].Fwd);
       double fwdx2=mVtoV(R.cal_AD4[1].Fwd);
       float db10m1;
       float db10m2;
       float fwdxa;
       float fwdxb;

       db10m1 = (dbm10a/10);
       db10m2 = (dbm10b/10);
       fwdxa= (fwdx1)*Fnex;
       fwdxb= (fwdx2)*Fnex;
 
        nex.writeNum("x2.val",db10m1*Fnex);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x2.val",db10m1*Fnex);

         nex.writeNum("x6.val",db10m2*Fnex);
         nex.writeNum("x6.val",db10m2*Fnex);

         nex.writeNum("x4.val",fwdxa);
         nex.writeNum("x4.val",fwdxa); 

         nex.writeNum("x8.val",fwdxb);
         nex.writeNum("x8.val",fwdxb);
          

          
        

        nex.writeNum("x10.val",volts0*Fnex);
       // nex.writeNum("x1.val0",volts0*100);

         nex.writeNum("x1.val",att_cal*Fnex);
         nex.writeNum("x1.val",att_cal*Fnex);






    }// fim refreshPage5

    void refreshPage6() // 
    {
        
    }// fim refreshPage6

    void refreshPage7() // wave
    {
        
    }// fim refreshPage7


// trigger dado pelos botões
void trigger1() // actualizar coupler 1

{



   String s1_value="i";
// no botão event printh 23 02 54 xx     xx = ao numero do trigger
         dbm1_s1 = nex.readNumber("x3.val");  // valor mais alto em dbm 
         dbm1_s1 = nex.readNumber("x3.val");
         dbm1_s1=dbm1_s1/100;
         
         dbm2_s1 =nex.readNumber("x7.val");  // valor mais baixo em dbm 
         dbm2_s1 = nex.readNumber("x7.val");
         dbm2_s1=dbm2_s1/100;

         volt1_s1= nex.readNumber("x5.val");  //tensão para o valor dBm mais alto
         volt1_s1= nex.readNumber("x5.val"); 
          volt1_s1=volt1_s1/100;
      
         volt2_s1= nex.readNumber("x9.val");  //tensão para o valor dBm mais baixo
         volt2_s1= nex.readNumber("x9.val");
         volt2_s1=volt2_s1/100;
       
         att_s1= nex.readNumber("x0.val");
         att_s1= nex.readNumber("x0.val");
         att_s1=att_s1/100;

        s1_value=nex.readStr("send_value.txt");
        s1_value=nex.readStr("send_value.txt");

        vtest=nex.readNumber("xt.val");
        vtest=nex.readNumber("xt.val");
       
         vtest=vtest/100;

  att_cal=att_s1;
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

coupler_calib(1, dbm1_s1,dbm2_s1,volt1_s1, volt2_s1,att_s1);
readConfig(config_filename);
//______________________________________________________________________________
/*
        R.cal_AD[0].db10m=(dbm1_s1)*10;     // valor mais alto em dbm 

        R.cal_AD[1].db10m=(dbm2_s1)*10;    // valor mais baixo em dBm *10


        R.cal_AD[0].Fwd =VtomV(volt1_s1);  //tensão para o valor dBm mais alto em decimas de mV
        R.cal_AD[0].Rev = R.cal_AD[0].Fwd;  // o mesmo valor para reverse
        
        
        R.cal_AD[1].Fwd = VtomV(volt2_s1);           //tensão para o valor dBm mais baixo
        R.cal_AD[1].Rev = VtomV(volt2_s1);
*/
        int16_t dbm10c= R.cal_AD1[0].db10m;
        int16_t dbm10d= R.cal_AD1[1].db10m;

        float fwd1= mVtoV(R.cal_AD1[0].Fwd);
        float fwd2= mVtoV(R.cal_AD1[1].Fwd);

        nex.writeNum("x1.val",att_c1);
         nex.writeNum("x1.val",att_c1);

         nex.writeNum("x2.val",(dbm10c*100)/10);
         nex.writeNum("x2.val",(dbm10c*100)/10);

         nex.writeNum("x6.val",(dbm10d*100)/10);
         nex.writeNum("x6.val",(dbm10d*100)/10);

         nex.writeNum("x4.val",(fwd1*100));
         nex.writeNum("x4.val",(fwd1*100));

          nex.writeNum("x8.val",(fwd2*100));
          nex.writeNum("x8.val",(fwd2*100));

         

       
        nex.writeStr("send_value.txt","ok") ;
        nex.writeStr("send_value.txt","ok") ;

        nex.writeStr("t8.txt","ok") ;
        nex.writeStr("t8.txt","ok") ;
  
   refreshPage2();


}

void trigger2()  // actualizar coupler 2
{
//ATT_x02 dBm_h_x32 volt_hx52 dBd_H_x72 Volt_L_x92
   
  String s1_value="i";
// no botão event printh 23 02 54 xx     xx = ao numero do trigger
int16_t  dbm1_s = nex.readNumber("x32.val");  // valor mais alto em dbm 
         dbm1_s = nex.readNumber("x32.val");
         dbm1_s=dbm1_s/100;
         
int16_t  dbm2_s =nex.readNumber("x72.val");  // valor mais baixo em dbm 
         dbm2_s = nex.readNumber("x72.val");
         dbm2_s=dbm2_s/100;

double   volt1_s= nex.readNumber("x52.val");  //tensão para o valor dBm mais alto
         volt1_s= nex.readNumber("x52.val"); 
          volt1_s=volt1_s/100;
      
 double  volt2_s= nex.readNumber("x92.val");  //tensão para o valor dBm mais baixo
         volt2_s= nex.readNumber("x92.val");
         volt2_s=volt2_s/100;
       
 int     att_s= nex.readNumber("x0.val");
         att_s= nex.readNumber("x0.val");
         att_s=att_s/100;

        s1_value=nex.readStr("send_value.txt");
        s1_value=nex.readStr("send_value.txt");

        vtest=nex.readNumber("xt.val");
        vtest=nex.readNumber("xt.val");
       
         vtest=vtest/100;

  att_cal=att_s1;
  
// coupler_calib(int coupler_cal, int16_t dbmHigh,int16_t dbmLow,double fwd_h, double fwd_l )

coupler_calib(2, dbm1_s,dbm2_s,volt1_s, volt2_s, att_s1);

//______________________________________________________________________________
        int16_t dbm10c= R.cal_AD2[0].db10m;
        int16_t dbm10d= R.cal_AD2[1].db10m;

        float fwd1= mVtoV(R.cal_AD2[0].Fwd);
        float fwd2= mVtoV(R.cal_AD2[1].Fwd);

         nex.writeNum("x1.val",att_c2);
         nex.writeNum("x1.val",att_c2);

         nex.writeNum("x2.val",(dbm10c*100)/10);
         nex.writeNum("x2.val",(dbm10c*100)/10);

         nex.writeNum("x6.val",(dbm10d*100)/10);
         nex.writeNum("x6.val",(dbm10d*100)/10);

         nex.writeNum("x4.val",(fwd1*100));
         nex.writeNum("x4.val",(fwd1*100));

          nex.writeNum("x8.val",(fwd2*100));
          nex.writeNum("x8.val",(fwd2*100));

         

       
        nex.writeStr("send_value.txt","ok") ;
        nex.writeStr("send_value.txt","ok") ;

        nex.writeStr("t8.txt","ok") ;
        nex.writeStr("t8.txt","ok") ;
  
   refreshPage3();




 }  // fim trigger 2

void trigger3() //  // actualizar coupler 3
{
//ATT_x02 dBm_h_x32 volt_hx52 dBd_H_x72 Volt_L_x92
   
  String s1_value="i";
// no botão event printh 23 02 54 xx     xx = ao numero do trigger
int16_t  dbm1_s = nex.readNumber("x33.val");  // valor mais alto em dbm 
         dbm1_s = nex.readNumber("x33.val");
         dbm1_s=dbm1_s/100;
         
int16_t  dbm2_s =nex.readNumber("x73.val");  // valor mais baixo em dbm 
         dbm2_s = nex.readNumber("x73.val");
         dbm2_s=dbm2_s/100;

double   volt1_s= nex.readNumber("x53.val");  //tensão para o valor dBm mais alto
         volt1_s= nex.readNumber("x53.val"); 
          volt1_s=volt1_s/100;
      
 double  volt2_s= nex.readNumber("x93.val");  //tensão para o valor dBm mais baixo
         volt2_s= nex.readNumber("x93.val");
         volt2_s=volt2_s/100;
       
 int     att_s= nex.readNumber("x0.val");
         att_s= nex.readNumber("x0.val");
         att_s=att_s/100;

        s1_value=nex.readStr("send_value.txt");
        s1_value=nex.readStr("send_value.txt");

        vtest=nex.readNumber("xt.val");
        vtest=nex.readNumber("xt.val");
       
         vtest=vtest/100;

  att_cal=att_s1;
  
// coupler_calib(int coupler_cal, int16_t dbmHigh,int16_t dbmLow,double fwd_h, double fwd_l )

coupler_calib(3, dbm1_s,dbm2_s,volt1_s, volt2_s,att_s1);

//______________________________________________________________________________
 int16_t dbm10c= R.cal_AD3[0].db10m;
        int16_t dbm10d= R.cal_AD3[1].db10m;

        float fwd1= mVtoV(R.cal_AD3[0].Fwd);
        float fwd2= mVtoV(R.cal_AD3[1].Fwd);

         nex.writeNum("x1.val",att_c3);
         nex.writeNum("x1.val",att_c3);

         nex.writeNum("x2.val",(dbm10c*100)/10);
         nex.writeNum("x2.val",(dbm10c*100)/10);

         nex.writeNum("x6.val",(dbm10d*100)/10);
         nex.writeNum("x6.val",(dbm10d*100)/10);

         nex.writeNum("x4.val",(fwd1*100));
         nex.writeNum("x4.val",(fwd1*100));

          nex.writeNum("x8.val",(fwd2*100));
          nex.writeNum("x8.val",(fwd2*100));

         

       
        nex.writeStr("send_value.txt","ok") ;
        nex.writeStr("send_value.txt","ok") ;

        nex.writeStr("t8.txt","ok") ;
        nex.writeStr("t8.txt","ok") ;
  
   refreshPage4();





}// fim do trigger 3

void trigger4()  /// actualizar coupler 4
{

//ATT_x02 dBm_h_x32 volt_hx52 dBd_H_x72 Volt_L_x92
   
  String s1_value="i";
// no botão event printh 23 02 54 xx     xx = ao numero do trigger
int16_t  dbm1_s = nex.readNumber("x34.val");  // valor mais alto em dbm 
         dbm1_s = nex.readNumber("x34.val");
         dbm1_s=dbm1_s/100;
         
int16_t  dbm2_s =nex.readNumber("x74.val");  // valor mais baixo em dbm 
         dbm2_s = nex.readNumber("x74.val");
         dbm2_s=dbm2_s/100;

double   volt1_s= nex.readNumber("x54.val");  //tensão para o valor dBm mais alto
         volt1_s= nex.readNumber("x54.val"); 
          volt1_s=volt1_s/100;
      
 double  volt2_s= nex.readNumber("x94.val");  //tensão para o valor dBm mais baixo
         volt2_s= nex.readNumber("x94.val");
         volt2_s=volt2_s/100;
       
 int     att_s= nex.readNumber("x0.val");
         att_s= nex.readNumber("x0.val");
         att_s=att_s/100;

        s1_value=nex.readStr("send_value.txt");
        s1_value=nex.readStr("send_value.txt");

        vtest=nex.readNumber("xt.val");
        vtest=nex.readNumber("xt.val");
       
         vtest=vtest/100;

  att_cal=att_s1;
  
// coupler_calib(int coupler_cal, int16_t dbmHigh,int16_t dbmLow,double fwd_h, double fwd_l )

coupler_calib(4, dbm1_s,dbm2_s,volt1_s, volt2_s,att_s1);

//______________________________________________________________________________
 int16_t dbm10c= R.cal_AD4[0].db10m;
        int16_t dbm10d= R.cal_AD4[1].db10m;

        float fwd1= mVtoV(R.cal_AD4[0].Fwd);
        float fwd2= mVtoV(R.cal_AD4[1].Fwd);

         nex.writeNum("x1.val",att_c4);
         nex.writeNum("x1.val",att_c4);
        
         nex.writeNum("x2.val",(dbm10c*100)/10);
         nex.writeNum("x2.val",(dbm10c*100)/10);

         nex.writeNum("x6.val",(dbm10d*100)/10);
         nex.writeNum("x6.val",(dbm10d*100)/10);

         nex.writeNum("x4.val",(fwd1*100));
         nex.writeNum("x4.val",(fwd1*100));

          nex.writeNum("x8.val",(fwd2*100));
          nex.writeNum("x8.val",(fwd2*100));

         

       
        nex.writeStr("send_value.txt","ok") ;
        nex.writeStr("send_value.txt","ok") ;

        nex.writeStr("t8.txt","ok") ;
        nex.writeStr("t8.txt","ok") ;
  
   refreshPage4();




}// fim do trigger 4

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

void trigger6()
{

     current_coupler= 1;

          R.cal_AD[0].db10m =R.cal_AD1[0].db10m;
          R.cal_AD[0].Fwd = R.cal_AD1[0].Fwd;
          R.cal_AD[0].Rev = R.cal_AD1[0].Rev;
          // Set second calibration point at 30 dB less
          R.cal_AD[1].db10m = R.cal_AD1[1].db10m;
          R.cal_AD[1].Fwd = R.cal_AD1[1].Fwd;
          R.cal_AD[1].Rev = R.cal_AD1[1].Rev;  

}// fim do trigger 6

void trigger7()
{



}// fim do trigger 7

void trigger8()
{

  current_coupler= 1;

          R.cal_AD[0].db10m =R.cal_AD2[0].db10m;
          R.cal_AD[0].Fwd = R.cal_AD2[0].Fwd;
          R.cal_AD[0].Rev = R.cal_AD2[0].Rev;
          // Set second calibration point at 30 dB less
          R.cal_AD[1].db10m = R.cal_AD2[1].db10m;
          R.cal_AD[1].Fwd = R.cal_AD2[1].Fwd;
          R.cal_AD[1].Rev = R.cal_AD2[1].Rev;  
}// fim do trigger 8

void trigger9()
{



}// fim do trigger 9

void trigger10()
{

current_coupler= 3;


          R.cal_AD[0].db10m =R.cal_AD3[0].db10m;
          R.cal_AD[0].Fwd = R.cal_AD3[0].Fwd;
          R.cal_AD[0].Rev = R.cal_AD3[0].Rev;
          // Set second calibration point at 30 dB less
          R.cal_AD[1].db10m = R.cal_AD3[1].db10m;
          R.cal_AD[1].Fwd = R.cal_AD3[1].Fwd;
          R.cal_AD[1].Rev = R.cal_AD3[1].Rev;  

}// fim do trigger 10

void trigger11()
{



}// fim do trigger 11

void trigger12()
{

current_coupler= 4;


          R.cal_AD[0].db10m =R.cal_AD4[0].db10m;
          R.cal_AD[0].Fwd = R.cal_AD4[0].Fwd;
          R.cal_AD[0].Rev = R.cal_AD4[0].Rev;
          // Set second calibration point at 30 dB less
          R.cal_AD[1].db10m = R.cal_AD4[1].db10m;
          R.cal_AD[1].Fwd = R.cal_AD4[1].Fwd;
          R.cal_AD[1].Rev = R.cal_AD4[1].Rev;  

}// fim do trigger 12
