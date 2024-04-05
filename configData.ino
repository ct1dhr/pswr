bool readConfig(String file_name) {
  String file_content = readFile(SPIFFS, file_name);

  int config_file_size = file_content.length();
  Serial.println("Config file size: " + String(config_file_size));

  if(config_file_size > 1024) {
    Serial.println("Config file too large");
    return false;
  }
  StaticJsonDocument<1024> doc;
  auto error = deserializeJson(doc, file_content);
  if ( error ) { 
    Serial.println("Error interpreting calib file");
    return false;
  }
//***********************************************
const int16_t  dbmHigh = doc["dbmHigh"];
  const int16_t  dbmLow = doc["dbmLow"];
  const double   fwd_h = doc["fwd_h"];
  const double   fwd_l = doc["fwd_l"];
  const int   att = doc["att"];

           att_c0= att;
          R.cal_AD[0].db10m = dbmHigh;
          R.cal_AD[0].Fwd =  fwd_h;
          R.cal_AD[0].Rev = R.cal_AD1[0].Fwd;
          // Set second calibration point at 30 dB less
          R.cal_AD[1].db10m =  dbmLow;
          R.cal_AD[1].Fwd   =  fwd_l;
          R.cal_AD[1].Rev   =  fwd_l; 
//---------------------------------------------

  const int16_t  dbmHigh1 = doc["dbmHigh1"];
  const int16_t  dbmLow1 = doc["dbmLow1"];
  const double   fwd_h1 = doc["fwd_h1"];
  const double   fwd_l1 = doc["fwd_l1"];
  const int   att1 = doc["att1"];
        
          att_c1=att1;
          R.cal_AD1[0].db10m = dbmHigh1;
          R.cal_AD1[0].Fwd =  fwd_h1;
          R.cal_AD1[0].Rev = R.cal_AD1[0].Fwd;
          // Set second calibration point at 30 dB less
          R.cal_AD1[1].db10m =  dbmLow1;
          R.cal_AD1[1].Fwd   =  fwd_l1;
          R.cal_AD1[1].Rev   =  fwd_l1; 
//---------------------------------------------


  const int16_t  dbmHigh2 = doc["dbmHigh2"];
  const int16_t  dbmLow2 = doc["dbmLow2"];
  const double   fwd_h2 = doc["fwd_h2"];
  const double   fwd_l2 = doc["fwd_l2"];
   const int     att2 = doc["att2"];

           att_c2=att2;
          R.cal_AD2[0].db10m = dbmHigh2;
          R.cal_AD2[0].Fwd =  fwd_h2;
          R.cal_AD2[0].Rev = R.cal_AD2[0].Fwd;
          // Set second calibration point at 30 dB less
          R.cal_AD2[1].db10m =  dbmLow2;
          R.cal_AD2[1].Fwd   =  fwd_l2;
          R.cal_AD2[1].Rev   =  fwd_l2; 
//---------------------------------------------
       const int16_t  dbmHigh3 = doc["dbmHigh3"];
  const int16_t  dbmLow3 = doc["dbmLow3"];
  const double   fwd_h3 = doc["fwd_h3"];
  const double   fwd_l3 = doc["fwd_l3"];
  const int   att3 = doc["att3"];
      
           att_c3=att3;
          R.cal_AD3[0].db10m = dbmHigh3;
          R.cal_AD3[0].Fwd =  fwd_h3;
          R.cal_AD3[0].Rev = R.cal_AD3[0].Fwd;
          // Set second calibration point at 30 dB less
          R.cal_AD3[1].db10m =  dbmLow3;
          R.cal_AD3[1].Fwd   =  fwd_l3;
          R.cal_AD3[1].Rev   =  fwd_l3; 
//-----------------------------------------------

const int16_t    dbmHigh4 = doc["dbmHigh4"];
  const int16_t  dbmLow4 = doc["dbmLow4"];
  const double   fwd_h4 = doc["fwd_h4"];
  const double   fwd_l4 = doc["fwd_l4"];
  const int   att4 = doc["att4"];
          
          att_c4=att4;
          R.cal_AD4[0].db10m = dbmHigh4;
          R.cal_AD4[0].Fwd =  fwd_h4;
          R.cal_AD4[0].Rev = R.cal_AD4[0].Fwd;
          // Set second calibration point at 30 dB less
          R.cal_AD4[1].db10m =  dbmLow4;
          R.cal_AD4[1].Fwd   =  fwd_l4;
          R.cal_AD4[1].Rev   =  fwd_l4; 
//---------------------------------------------

//---------------------------------------------
  //********************************************
  return true;
}

bool saveConfig(String file_name) {
  StaticJsonDocument<1024> doc;
//**************************************
  // write variables to JSON file
   doc["att"]  = att_c0;
   doc["dbmHigh"]  =  R.cal_AD[0].db10m;
   doc["fwd_h"]  =    R.cal_AD[0].Fwd;
   doc["dbmLow"]  =   R.cal_AD[1].db10m;
    doc["fwd_l"]  =   R.cal_AD[1].Fwd;
   //------------------------------------- 

   doc["att1"]  = att_c1;
   doc["dbmHigh1"]  =  R.cal_AD1[0].db10m;
   doc["fwd_h1"]  =    R.cal_AD1[0].Fwd;
   doc["dbmLow1"]  =   R.cal_AD1[1].db10m;
    doc["fwd_l1"]  =   R.cal_AD1[1].Fwd;
   //-------------------------------------    
     doc["att2"]  = att_c2; 
    doc["dbmHigh2"]  =  R.cal_AD2[0].db10m;
    doc["fwd_h2"]  =    R.cal_AD2[0].Fwd;
    doc["dbmLow2"]  =   R.cal_AD2[1].db10m;
    doc["fwd_l2"]  =   R.cal_AD2[1].Fwd;
   //-------------------------------------    
     doc["att3"]  = att_c3;
   doc["dbmHigh3"]  =  R.cal_AD3[0].db10m;
   doc["fwd_h3"]  =    R.cal_AD3[0].Fwd;
   doc["dbmLow3"]  =   R.cal_AD3[1].db10m;
    doc["fwd_l3"]  =   R.cal_AD3[1].Fwd;
   //-------------------------------------      
    doc["att4"]  = att_c4;
    doc["dbmHigh4"]  =  R.cal_AD4[0].db10m;
    doc["fwd_h4"]  =    R.cal_AD4[0].Fwd;
    doc["dbmLow4"]  =   R.cal_AD4[1].db10m;
    doc["fwd_l4"]  =   R.cal_AD4[1].Fwd;
   //-------------------------------------     


         
         

  //***************************************
  // write config file
  String tmp = "";
  serializeJson(doc, tmp);
  writeFile(SPIFFS, config_filename, tmp);
  
  return true;
}

void writeFile(fs::FS &fs, String filename, String message){
  Serial.println("writeFile -> Writing file: " + filename);

  File file = fs.open(filename, FILE_WRITE);
  if(!file){
    Serial.println("writeFile -> failed to open file for writing");
    return;
  }
  if(file.print(message)){
    Serial.println("writeFile -> file written");
  } else {
    Serial.println("writeFile -> write failed");
  }
  file.close();
}

String readFile(fs::FS &fs, String filename){
  Serial.println("readFile -> Reading file: " + filename);

  File file = fs.open(filename);
  if(!file || file.isDirectory()){
    Serial.println("readFile -> failed to open file for reading");
    return "";
  }

  String fileText = "";
  while(file.available()){
    fileText = file.readString();
  }

  file.close();
  return fileText;
}