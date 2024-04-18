void SendNextionFwd(){
String  endChar = String(char(0xff)) + String(char(0xff)) + String(char(0xff));
 // digitalWrite(led,!(digitalRead(led)));
int32_t valw=fwd_power_mw;
int32_t wpp;
 //  double mw=pow(10,(ad8307_FdBm/10.0));
int32_t gwatts;
int32_t gwp;
 double mw=pow(10,ad8307_FdBm/10.0);
  // double mw=fwd_power_mw;
   //if(ad8307_FdBm < -70){mw=0;}
  float kw_val = mw/1000000;
  float W_val = mw/1000;
  float mW_val = mw/1;
  float nW_val = mw*1000;
  int fc=100;      // Fundo de escala do grafico de barras
 
  int Fmw_nex=int(mw*100); // vezes 100 para apresentar duas casas decimais
  double Rmw_nex=ref_power_mw;
 
Serial.print("escala --> ");Serial.println(escala());
#if !NEXTION
// ---------escala de Kw------
if(escala()==1 ){  // maior do que 1Kw

fc=2000;
Serial2.print("u1.txt=\"Kw\"" + endChar);
// escala do g. barras
Fmw_nex=mw/1000000+0.1;
Serial2.print("fsf.txt=\"2K\"" + endChar);
Serial2.print("fs2.txt=\"1.5K\"" + endChar);
Serial2.print("fsm.txt=\"1K\"" + endChar);
Serial2.print("fs1.txt=\"0.5K\"" + endChar);

valw=fwd_power_mw/1000000*Fnex;
Serial2.print("u1.txt=\"Kw\"" + endChar);
Serial2.print("Cw.val=");

Serial2.print(valw);
Serial2.print(endChar);

 gwatts=map(valw/Fnex,0,fc,0,100);


Serial2.print("Gw.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
wpp=power_mw_pk/1000000;
gwp=map(wpp,0,fc,0,100);
 Serial2.print("Gwp.val=");

Serial2.print(gwp);
Serial2.print(endChar);


}

//--------------------------escala de  watts -------
if(escala()==2 ){ //500w  a 1kw
fc=1000;
// escala do g. barras

Serial2.print("fsf.txt=\"1K\"" + endChar);
Serial2.print("fs2.txt=\"750\"" + endChar);
Serial2.print("fsm.txt=\"500\"" + endChar);
Serial2.print("fs1.txt=\"250\"" + endChar);



valw=fwd_power_mw/1000000*Fnex;
Serial2.print("u1.txt=\"Kw\"" + endChar);
Serial2.print("Cw.val=");
//Serial2.print(fwd_power_mw*Fnex/10);
Serial2.print(valw);
Serial2.print(endChar);

 gwatts=map(valw/Fnex,0,fc,0,100);


Serial2.print("Gw.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
wpp=power_mw_pk/1000000;
gwp=map(wpp,0,fc,0,100);
 Serial2.print("Gwp.val=");

Serial2.print(gwp);
Serial2.print(endChar);


}
if(escala()==3 ){ // 100w a 500w
fc=500;
// escala do g. barras

Serial2.print("fsf.txt=\"500\"" + endChar);
Serial2.print("fs2.txt=\"375\"" + endChar);
Serial2.print("fsm.txt=\"250\"" + endChar);
Serial2.print("fs1.txt=\"125\"" + endChar);

valw=fwd_power_mw/1000*Fnex;
Serial2.print("u1.txt=\"W\"" + endChar);
Serial2.print("Cw.val=");

Serial2.print(valw);
Serial2.print(endChar);

 gwatts=map(valw/Fnex,0,fc,0,100);

Serial2.print("Gw.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
wpp=power_mw_pk/1000;
gwp=map(wpp,0,fc,0,100);
 Serial2.print("Gwp.val=");

Serial2.print(gwp);
Serial2.print(endChar);
}

if(escala()==4 ){ // 50w a 100w
fc=100;
Serial2.print("fsf.txt=\"100\"" + endChar);
Serial2.print("fs2.txt=\"87\"" + endChar);
Serial2.print("fsm.txt=\"75\"" + endChar);
Serial2.print("fs1.txt=\"62\"" + endChar);

valw=fwd_power_mw/1000*Fnex;
Serial2.print("u1.txt=\"W\"" + endChar);
Serial2.print("Cw.val=");

Serial2.print(valw);
Serial2.print(endChar);

 gwatts=map(valw/Fnex,0,fc,0,100);


Serial2.print("Gw.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
wpp=power_mw_pk/1000;
gwp=map(wpp,0,fc,0,100);
 Serial2.print("Gwp.val=");

Serial2.print(gwp);
Serial2.print(endChar);
}

if(escala()==5 ){  //10 a 50w
  fc=50;
  Serial2.print("fsf.txt=\"50\"" + endChar);
Serial2.print("fs2.txt=\"40\"" + endChar);
Serial2.print("fsm.txt=\"30\"" + endChar);
Serial2.print("fs1.txt=\"20\"" + endChar);

valw=fwd_power_mw/1000*Fnex;
Serial2.print("u1.txt=\"W\"" + endChar);
Serial2.print("Cw.val=");
//Serial2.print(fwd_power_mw*Fnex/10);
Serial2.print(valw);
Serial2.print(endChar);

 gwatts=map(valw/Fnex,0,fc,0,100);


Serial2.print("Gw.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
wpp=power_mw_pk/100;
gwp=map(wpp,0,fc,0,100);
 Serial2.print("Gwp.val=");

Serial2.print(gwp);
Serial2.print(endChar);

}
if(escala()==6 ) //// 1w a 10w
{
fc=10;  

 Serial2.print("fsf.txt=\"10\"" + endChar);
Serial2.print("fs2.txt=\"7\"" + endChar);
Serial2.print("fsm.txt=\"5\"" + endChar);
Serial2.print("fs1.txt=\"2\"" + endChar);

 valw=fwd_power_mw/1000*Fnex;
Serial2.print("u1.txt=\"W\"" + endChar);
Serial2.print("Cw.val=");

Serial2.print(valw);
Serial2.print(endChar);
gwatts=map(valw/Fnex,0,fc,0,100);
 Serial2.print("Gw.val=");

Serial2.print(gwatts);
Serial2.print(endChar);
wpp=power_mw_pk/100;
gwp=map(wpp,0,fc,0,100);
 Serial2.print("Gwp.val=");

Serial2.print(gwp);
Serial2.print(endChar);

}
if(escala()==7 )// menor do que 1w
{
fc=1;  
 Serial2.print("fsf.txt=\"1\"" + endChar);
Serial2.print("fs2.txt=\".7\"" + endChar);
Serial2.print("fsm.txt=\".5\"" + endChar);
Serial2.print("fs1.txt=\".2\"" + endChar);
valw=fwd_power_mw/1000*Fnex;

Serial2.print("u1.txt=\"mW\"" + endChar);
Serial2.print("Cw.val=");
//Serial2.print(fwd_power_mw*Fnex/10);
Serial2.print(valw);
Serial2.print(endChar);
gwatts=map(valw/Fnex,0,fc,0,100);
 Serial2.print("Gw.val=");

Serial2.print(gwatts);
Serial2.print(endChar);

wpp=power_mw_pk/1;
gwp=map(wpp,0,fc,0,100);
 Serial2.print("Gwp.val=");

Serial2.print(gwp);
Serial2.print(endChar);

}


int valdb= int(ad8307_FdBm*100);
Serial2.print("Cdb.val=");
Serial2.print(valdb);
Serial2.print(endChar);

 int esc=escala();

Serial2.print("n0.val=");
Serial2.print(esc);
Serial2.print(endChar);


//int valw=pow(10,ad8307_FdBm/10.0)/1000*Fnex;
/*
int valw=fwd_power_mw/1000*Fnex;
Serial2.print("Cw.val=");
//Serial2.print(fwd_power_mw*Fnex/10);
Serial2.print(valw);
Serial2.print(endChar);
*/
#endif

}// fim fwd


void SendNextionRev()
{

 String  endChar = String(char(0xff)) + String(char(0xff)) + String(char(0xff)); 
int swr_nex= int(swr*10);
int gmwR;
int fc=100; 
Serial2.print("rw.val=");
Serial2.print(swr_nex);
Serial2.print(endChar);

if(ref_power_mw<=1.1){ref_power_mw=1;}

  
  
  int32_t Rmw_nex=int(ref_power_mw*100); // vezes 100 para apresentar duas casas decimais
  
 

#if !NEXTION
// ---------escala de Kw------
if(ref_power_mw >= 1000000 ){  // maior do que 1Kw

fc=2000;

// escala do g. barras
Rmw_nex=Rmw_nex/1000000+0.1;
Serial2.print("rsf.txt=\"2K\"" + endChar);
Serial2.print("rs2.txt=\"1.5K\"" + endChar);
Serial2.print("rsm.txt=\"1K\"" + endChar);
Serial2.print("rs1.txt=\"0.5K\"" + endChar);



 gmwR=map(Rmw_nex,0,fc,0,100);

Serial2.print("j1.val=");
Serial2.print(gmwR);
Serial2.print(endChar);


}

//--------------------------escala de  watts -------
if(ref_power_mw <1000000 and ref_power_mw >= 500000){ // menor  do que 1Kw e maior 500w
fc=1000;
// escala do g. barras

Serial2.print("rsf.txt=\"1K\"" + endChar);
Serial2.print("rs2.txt=\"750\"" + endChar);
Serial2.print("rsm.txt=\"500\"" + endChar);
Serial2.print("rs1.txt=\"250\"" + endChar);



Rmw_nex=Rmw_nex/1000+0.1;


 gmwR=map(Rmw_nex,0,fc,0,100);

Serial2.print("j1.val=");
Serial2.print(gmwR);
Serial2.print(endChar);
}
if(ref_power_mw<500000 and ref_power_mw >= 100000){ // menor  do que 1Kw e maior 100w
fc=500;
// escala do g. barras

Serial2.print("rsf.txt=\"500\"" + endChar);
Serial2.print("rs2.txt=\"375\"" + endChar);
Serial2.print("rsm.txt=\"250\"" + endChar);
Serial2.print("rs1.txt=\"125\"" + endChar);

Rmw_nex=Rmw_nex/1000+0.1;


 gmwR=map(Rmw_nex,0,fc,0,100);

Serial2.print("j1.val=");
Serial2.print(gmwR);
Serial2.print(endChar);
}

if(ref_power_mw <100000 and ref_power_mw >= 1000){ // menor  do que 1Kw e maior 1w
fc=100;
Serial2.print("rsf.txt=\"100\"" + endChar);
Serial2.print("rs2.txt=\"75\"" + endChar);
Serial2.print("rsm.txt=\"50\"" + endChar);
Serial2.print("rs1.txt=\"25\"" + endChar);

Rmw_nex=Rmw_nex/1000+0.1;

 gmwR=map(Rmw_nex,0,fc,0,100);

Serial2.print("j1.val=");
Serial2.print(gmwR);
Serial2.print(endChar);
}

if(ref_power_mw <1000 and ref_power_mw >= 1){
  fc=1;
  Serial2.print("rsf.txt=\"1\"" + endChar);
Serial2.print("rs2.txt=\".75\"" + endChar);
Serial2.print("rsm.txt=\".50\"" + endChar);
Serial2.print("rs1.txt=\".25\"" + endChar);

Rmw_nex=Rmw_nex/1+0.1;


 gmwR=map(Rmw_nex,0,fc,0,100);

Serial2.print("j1.val=");
Serial2.print(gmwR);
Serial2.print(endChar);
}




#endif
  

  }// fim rev