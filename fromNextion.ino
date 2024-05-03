
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
/*__________________________________________________________________
                   P A  G E 0
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
    void refreshPage0() {
     
     int vgraf;
      if(current_coupler==1){
      nex.writeStr("sn.txt", coupler_name[0]);

      }
     if(current_coupler==2){
      nex.writeStr("sn.txt", coupler_name[1]);

      }
      if(current_coupler==3){
      nex.writeStr("sn.txt", coupler_name[2]);

      }
      if(current_coupler==4){
      nex.writeStr("sn.txt", coupler_name[3]);

      }
      if(current_coupler==5){
      nex.writeStr("sn.txt", "Teste");

      }
fsc=1000;

int ppk=power_mw_pk*10/1000;
      nex.writeNum("pp.val",ppk);
    
      nex.writeNum("Cdb.val=",ad8307_FdBm*100);
      nex.writeNum("Cw.val=",fwd_power_w*100);
      String pot=String(mWtoW(fwd_power_mw));
      nex.writeStr("tw.txt",pot);
      //int esc=escala();
      
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
/*__________________________________________________________________
                   P A  G E 1
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
    void refreshPage1() {
     
    }
/*__________________________________________________________________
                   P A  G E 2
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
    void refreshPage2() // CPL 1
    {
 
      static int16_t  current_selection;   
      uint8_t cal_set; // Determine whether CAL_SET0, CAL_SET1 or CAL_SET2
      

        int att1 = att_c1*Fnex;
       int16_t dbm10a=CdBm(R.cal_AD1[0].db10m)*Fnex;
       int16_t dbm10b=CdBm(R.cal_AD1[1].db10m)*Fnex;
       double fwdx1=mVtoV(R.cal_AD1[0].Fwd)*Fnex*10;
       double fwdx2=mVtoV(R.cal_AD1[1].Fwd)*Fnex*10;
       
      
       
         nex.writeNum("x1.val",att1);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x1.val",att1);

         nex.writeNum("x2.val",dbm10a);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x2.val",dbm10a);

         nex.writeNum("x6.val",dbm10b);
         nex.writeNum("x6.val",dbm10b);

         nex.writeNum("x4.val",fwdx1);
         nex.writeNum("x4.val",fwdx1); 

         nex.writeNum("x8.val",fwdx2);
         nex.writeNum("x8.val",fwdx2);
          
        nex.writeNum("x10.val",volts0*Fnex*10);
        nex.writeNum("x10.val",volts0*Fnex*10);
       
        nex.writeNum("x11.val",volts1*Fnex*10);
        nex.writeNum("x11.val",volts1*Fnex*10);
         onePointCal(R.cal_AD2[0].db10m, R.cal_AD2[0].Fwd);
          nex.writeNum("x30v.val",mVtoV(SecondPointVolt)*Fnex*10);
         nex.writeNum("x30v.val",mVtoV(SecondPointVolt)*Fnex*10);
         nex.writeNum("x30db.val",SecondPointdB/10*Fnex);
         nex.writeNum("x30db.val",SecondPointdB/10*Fnex);

    }//refresh page2

/*__________________________________________________________________
                   P A  G E 3
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
// coupler 2
    void refreshPage3() //  CPL 2
    {
        
      uint8_t cal_set; // Determine whether CAL_SET0, CAL_SET1 or CAL_SET2
      

       int att2 = att_c2*Fnex;
       int16_t dbm10a=CdBm(R.cal_AD2[0].db10m)*Fnex;
       int16_t dbm10b=CdBm(R.cal_AD2[1].db10m)*Fnex;
       double fwdx1=mVtoV(R.cal_AD2[0].Fwd)*Fnex*10;
       double fwdx2=mVtoV(R.cal_AD2[1].Fwd)*Fnex*10;
       
       Serial.print(dbm10a);Serial.print(";");
       
         nex.writeNum("x1.val",att2);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x1.val",att2);

         nex.writeNum("x2.val",dbm10a);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x2.val",dbm10a);

         nex.writeNum("x6.val",dbm10b);
         nex.writeNum("x6.val",dbm10b);

         nex.writeNum("x4.val",fwdx1);
         nex.writeNum("x4.val",fwdx1); 

         nex.writeNum("x8.val",fwdx2);
         nex.writeNum("x8.val",fwdx2);
          
        nex.writeNum("x10.val",volts2*Fnex*10);
        nex.writeNum("x10.val",volts2*Fnex*10);
        nex.writeNum("x11.val",volts3*Fnex*10);
        nex.writeNum("x11.val",volts3*Fnex*10);
         onePointCal(R.cal_AD2[0].db10m, R.cal_AD2[0].Fwd);
        nex.writeNum("x30db.val",SecondPointdB1/10*Fnex);
         nex.writeNum("x30db.val",SecondPointdB1/10*Fnex);
         nex.writeNum("x30v.val",mVtoV(SecondPointVolt1)*Fnex*10);
         nex.writeNum("x30v.val",mVtoV(SecondPointVolt1)*Fnex*10);
        
         

//___________________________
    }// fim refreshPage3
/*__________________________________________________________________
                   P A  G E 4
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
    void refreshPage4() // CPL 3
    {

 
      uint8_t cal_set; // Determine whether CAL_SET0, CAL_SET1 or CAL_SET2
      

       int att3 = att_c3*Fnex;
       int16_t dbm10a=CdBm(R.cal_AD3[0].db10m)*Fnex;
       int16_t dbm10b=CdBm(R.cal_AD3[1].db10m)*Fnex;
       double fwdx1=mVtoV(R.cal_AD3[0].Fwd)*Fnex*10;
       double fwdx2=mVtoV(R.cal_AD3[1].Fwd)*Fnex*10;
       
       Serial.print(dbm10a);Serial.print(";");
       
         nex.writeNum("x1.val",att3);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x1.val",att3);

         nex.writeNum("x2.val",dbm10a);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x2.val",dbm10a);

         nex.writeNum("x6.val",dbm10b);
         nex.writeNum("x6.val",dbm10b);

         nex.writeNum("x4.val",fwdx1);
         nex.writeNum("x4.val",fwdx1); 

         nex.writeNum("x8.val",fwdx2);
         nex.writeNum("x8.val",fwdx2);
          
        nex.writeNum("x10.val",volts0*Fnex*10);
       // nex.writeNum("x1.val0",volts0*100);ts0*100);

         

         

    }// fim refreshPage4
/*__________________________________________________________________
                   P A  G E 5
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
    void refreshPage5() // CPL 4
    {
     
  
      uint8_t cal_set; // Determine whether CAL_SET0, CAL_SET1 or CAL_SET2
      

       int att4 = att_c4*Fnex;
       int16_t dbm10a=CdBm(R.cal_AD4[0].db10m)*Fnex;
       int16_t dbm10b=CdBm(R.cal_AD4[1].db10m)*Fnex;
       double fwdx1=mVtoV(R.cal_AD4[0].Fwd)*Fnex*10;
       double fwdx2=mVtoV(R.cal_AD4[1].Fwd)*Fnex*10;
       
       Serial.print(dbm10a);Serial.print(";");
       
         nex.writeNum("x1.val",att4);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x1.val",att4);

         nex.writeNum("x2.val",dbm10a);  // valor de calibração * Fnex(100 para duas casas decimais)
         nex.writeNum("x2.val",dbm10a);

         nex.writeNum("x6.val",dbm10b);
         nex.writeNum("x6.val",dbm10b);

         nex.writeNum("x4.val",fwdx1);
         nex.writeNum("x4.val",fwdx1); 

         nex.writeNum("x8.val",fwdx2);
         nex.writeNum("x8.val",fwdx2);
          
        nex.writeNum("x10.val",volts0*Fnex*10);
       // nex.writeNum("x1.val0",volts0*100);
         

         


    }// fim refreshPage5
/*__________________________________________________________________
                   P A  G E 6
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
    void refreshPage6() // Config
    {
      String c1=coupler_name[0];
      String c2=coupler_name[1];
      String c3=coupler_name[2];
      String c4=coupler_name[3];



    nex.writeStr("t1.txt", c1);
    nex.writeStr("t2.txt", c2);
    nex.writeStr("t3.txt", c3);
    nex.writeStr("t4.txt", c4);
    


    }// fim refreshPage6
/*__________________________________________________________________
                   P A  G E 7
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
    void refreshPage7() // wave
    {
        
    }// fim refreshPage7
/*__________________________________________________________________
                   P A  G E 10
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

void refreshPage10() // wifi
    {

      if(fwifi){nex.writeNum("t5.bco",20256);}else{nex.writeNum("t5.bco",65535);}
        nex.writeStr("tlk.txt",String(linkOTA));
nex.writeStr("ssid.txt",ssid_from_display);
nex.writeStr("pass.txt",password_from_display);


    }// fim refreshPage10


/*__________________________________________________________________
                   P A  G E 11
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

void refreshPage11() // saver
    {
   
   millisTempozzz=millis();
  int ppk=power_mw_pk;
     nex.writeNum("va1.val=",nex.lastCurrentPageId);
   
      nex.writeNum("x0.val=",ppk);
 
if(fwd_power_mw > 0) {
   // Serial2.print("page 0");Serial2.print(endChar);

    Serial2.print(nex.lastCurrentPageId);Serial2.print(endChar);
   }

      
    }

/*__________________________________________________________________
                   P A  G E 11
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void refreshPage12(){


}