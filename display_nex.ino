void SendNextionFwd(){
String  endChar = String(char(0xff)) + String(char(0xff)) + String(char(0xff));
  digitalWrite(led,!(digitalRead(led)));
  float kw_val = fwd_power_mw/1000000;
  float W_val = fwd_power_mw/1000;
  float mW_val = fwd_power_mw/1;
  float nW_val = fwd_power_mw*1000;
  int fc=100;      // Fundo de escala do grafico de barras
 
  int Fmw_nex=int(fwd_power_mw*100); // vezes 100 para apresentar duas casas decimais
  double Rmw_nex=ref_power_mw;
 

#if !NEXTION
// ---------escala de Kw------
if(fwd_power_mw >= 1000000 ){  // maior do que 1Kw

fc=2000;
Serial2.print("u1.txt=\"Kw\"" + endChar);
// escala do g. barras
Fmw_nex=Fmw_nex/1000000+0.1;
Serial2.print("fsf.txt=\"2K\"" + endChar);
Serial2.print("fs2.txt=\"1.5K\"" + endChar);
Serial2.print("fsm.txt=\"1K\"" + endChar);
Serial2.print("fs1.txt=\"0.5K\"" + endChar);


Serial2.print("Cw.val=");
Serial2.print(Fmw_nex);

Serial2.print(endChar);

int gwatts=(Fmw_nex/100)*100/fc;

Serial2.print("Gw.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
}

//--------------------------escala de  watts -------
if(fwd_power_mw <1000000 and fwd_power_mw >= 500000){ // menor  do que 1Kw e maior 500w
fc=1000;
// escala do g. barras

Serial2.print("fsf.txt=\"1K\"" + endChar);
Serial2.print("fs2.txt=\"750\"" + endChar);
Serial2.print("fsm.txt=\"500\"" + endChar);
Serial2.print("fs1.txt=\"250\"" + endChar);



Fmw_nex=Fmw_nex/1000+0.1;
Serial2.print("u1.txt=\"W\"" + endChar);
Serial2.print("Cw.val=");
Serial2.print(Fmw_nex);
Serial2.print(endChar);

int gwatts=(Fmw_nex/100)*100/fc;

Serial2.print("Gw.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
}
if(fwd_power_mw <500000 and fwd_power_mw >= 100000){ // menor  do que 1Kw e maior 100w
fc=500;
// escala do g. barras

Serial2.print("fsf.txt=\"500\"" + endChar);
Serial2.print("fs2.txt=\"375\"" + endChar);
Serial2.print("fsm.txt=\"250\"" + endChar);
Serial2.print("fs1.txt=\"125\"" + endChar);

Fmw_nex=Fmw_nex/1000+0.1;
Serial2.print("u1.txt=\"W\"" + endChar);
Serial2.print("Cw.val=");
Serial2.print(Fmw_nex);
Serial2.print(endChar);

int gwatts=(Fmw_nex/100)*100/fc;

Serial2.print("Gw.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
}

if(fwd_power_mw <100000 and fwd_power_mw >= 1000){ // menor  do que 1Kw e maior 1w
fc=100;
Serial2.print("fsf.txt=\"100\"" + endChar);
Serial2.print("fs2.txt=\"75\"" + endChar);
Serial2.print("fsm.txt=\"50\"" + endChar);
Serial2.print("fs1.txt=\"25\"" + endChar);

Fmw_nex=Fmw_nex/1000+0.1;
Serial2.print("u1.txt=\"W\"" + endChar);
Serial2.print("Cw.val=");
Serial2.print(Fmw_nex);
Serial2.print(endChar);

int gwatts=(Fmw_nex/100)*100/fc;

Serial2.print("Gw.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
}

if(fwd_power_mw <1000 and fwd_power_mw >= 1){
  fc=1;
  Serial2.print("fsf.txt=\"1\"" + endChar);
Serial2.print("fs2.txt=\".75\"" + endChar);
Serial2.print("fsm.txt=\".50\"" + endChar);
Serial2.print("fs1.txt=\".25\"" + endChar);

Fmw_nex=Fmw_nex/1+0.1;
Serial2.print("u1.txt=\"mW\"" + endChar);
Serial2.print("Cw.val=");
Serial2.print(Fmw_nex);
Serial2.print(endChar);

int gwatts=(Fmw_nex/100)*100/fc;

Serial2.print("Gw.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
}

int valdb= int(ad8307_FdBm*100);
Serial2.print("Cdb.val=");
Serial2.print(valdb);
Serial2.print(endChar);

#endif
  

}// fim fwd


void SendNextionRev()
{

 String  endChar = String(char(0xff)) + String(char(0xff)) + String(char(0xff)); 
int swr_nex= int(swr*10);
Serial2.print("rw.val=");
Serial2.print(swr_nex);
Serial2.print(endChar);

if(ref_power_mw<=2){ref_power_mw=1;}

  
  float kw_val = ref_power_mw/1000000;
  float W_val  = ref_power_mw/1000;
  float mW_val = ref_power_mw/1;
  float nW_val = ref_power_mw*1000;
  int fc=100;      // Fundo de escala do grafico de barras
  
  int Rmw_nex=int(ref_power_mw*100); // vezes 100 para apresentar duas casas decimais
  
 

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




int gwatts=(Rmw_nex/100)*100/fc;

Serial2.print("j1.val=");
Serial2.print(gwatts);
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


int gwatts=(Rmw_nex/100)*100/fc;

Serial2.print("j1.val=");
Serial2.print(gwatts);
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


int gwatts=(Rmw_nex/100)*100/fc;

Serial2.print("j1.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
}

if(ref_power_mw <100000 and ref_power_mw >= 1000){ // menor  do que 1Kw e maior 1w
fc=100;
Serial2.print("rsf.txt=\"100\"" + endChar);
Serial2.print("rs2.txt=\"75\"" + endChar);
Serial2.print("rsm.txt=\"50\"" + endChar);
Serial2.print("rs1.txt=\"25\"" + endChar);

Rmw_nex=Rmw_nex/1000+0.1;


int gwatts=(Rmw_nex/100)*100/fc;

Serial2.print("j1.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
}

if(ref_power_mw <1000 and ref_power_mw >= 1){
  fc=1;
  Serial2.print("rsf.txt=\"1\"" + endChar);
Serial2.print("rs2.txt=\".75\"" + endChar);
Serial2.print("rsm.txt=\".50\"" + endChar);
Serial2.print("rs1.txt=\".25\"" + endChar);

Rmw_nex=Rmw_nex/1+0.1;
;

int gwatts=(Rmw_nex/100)*100/fc;

Serial2.print("j1.val=");
Serial2.print(gwatts);
Serial2.print(endChar);
}




#endif
  


  }// fim rev