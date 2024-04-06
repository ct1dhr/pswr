/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                      PSWR Version 1.03.01
                Platform Esp32 with Nextion Display
                          CT1DHR

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

  based on the project of Loftur E. Jonasson  (tf3lj [at] arrl [dot] net)
   See README.md file

  
-----------------------  V E R S I O N   N O T E S ---------------------
  Build .01   2024MAR04
 -Erased -EEPROMAnything.h  and used SPIFFS.h  instead EEPROM.h to store 
   config variables.



+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <SPIFFS.h>
#include <ArduinoJson.h>    
#include "SWR.h"
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>




#include "EasyNextionLibrary.h"  // Include EasyNextionLibrary
      EasyNex nex(Serial2); 

const char* ssid = "CCebolais3";
const char* password = "CasadoVelho";     

void SendNextionFwd();
void SendNextionRev();
/*
float receive_att();

float receive_v2();
float receive_v1();
float receive_db1();
float receive_db2();
*/
void firstRefresh();
void refereshCurrentPage();
void refreshPage0();
void refreshPage1();
void refreshPage2();
void refreshPage3();
void refreshPage4();
bool readConfig(String file_name);
bool saveConfig(String file_name);

#define FORMAT_SPIFFS_IF_FAILED true
const String config_filename = "/config.json";

#if ADS1115
Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
#endif
volatile adbuffer_t measure;// Two 256 byte circular buffers carrying the sampled adc-inputs
                            // from the interrupt function to the main loop.
                            
double      adc_ref;        // ADC reference (Teensy or external AD7991)
int16_t     fwd;            // AD input - 12 bit value, v-forward
int16_t     rev;            // AD input - 12 bit value, v-reverse
double      f_inst;         // Calculated Forward voltage
double      r_inst;         // Calculated Reverse voltage
#if AD8307_INSTALLED
double      ad8307_FdBm;    // Measured AD8307 forward voltage in dBm
double      ad8307_RdBm;    // Measured AD8307 reverse current in dBm
#endif
double      fwd_power_mw;   // Calculated forward power in mW
double      ref_power_mw;   // Calculated reflected power in mW
double      power_mw;       // Calculated power in mW
double      power_mw_pk;    // Calculated 100ms peak power in mW
double      power_mw_pep;   // Calculated PEP power in mW (1s, 2.5s or 5s)
double      power_mw_long;  // Calculated MAX power in mW, 30 sec or longer window
double      power_mw_avg;   // Calculated AVG power in mW, 100ms
double      power_mw_1savg; // Calculated AVG power in mW, 1 second
double      power_db;       // Calculated power in dBm
double      power_db_pk;    // Calculated 100ms peak power in dBm
double      power_db_pep;   // Calculated PEP power in dBm
double      power_db_long;  // Calculated MAX power in dBm, 30 sec or longer window
double      swr=1.0;        // SWR as an absolute value
double      swr_avg=1.0;    // SWR average over 10 ms (smoothed value)
int16_t adc0, adc1, adc2, adc3;
     double volts0, volts1, volts2, volts3, vtest;
uint16_t    menu_level = 0; // Used with PSWRmenu. Keep track of which menu we are in
char        lcd_buf[82];    // Used to process data to be passed to LCD and USB Serial

uint16_t    power_timer;    // Used to stay out of Screensaver
uint16_t    Menu_exit_timer;// Used for a timed display when returning from Menu
uint8_t     mode_display;   // Active display
push_flags  flag;           // Various op flags
touch_flags touch;          // Touchscreen flags

bool        Reverse;        // BOOL: True if reverse power is greater than forward power
bool        modScopeActive; // BOOL: Feed stuff to the Modulation Scope
volatile bool X_LedState;   // BOOL: Debug LED    

uint8_t     mode_band = 0;   // Band mode active
int         cur_band = 1;   // Band mode active
unsigned long refresh_timer = millis(); 
//-
int led = 2;
int att_c0, att_c1,att_c2,att_c3,att_c4 ;

// Variables in ram/flash rom (default)
var_t  R  = {
{ // Coupler 1 Meter calibration for HF    1
{
      CAL1_NOR_VALUE,       // First calibrate point in 10 x dBm
      CALFWD1_DEFAULT,      // First Calibrate point, Forward direction, Volts
      CALREV1_DEFAULT       // First Calibrate point, Reverse direction, Volts
    },
    {
      CAL2_NOR_VALUE,       // Second Calibrate point in 10 x dBm
      CALFWD2_DEFAULT,      // Second Calibrate point, Forward direction, Volts
      CALREV2_DEFAULT       // Second Calibrate point, Reverse direction, Volts
    }
  },
 


          {
    { // Coupler 1 Meter calibration for HF    1
      CAL1_NOR_VALUE,       // First calibrate point in 10 x dBm
      CALFWD1_DEFAULT,      // First Calibrate point, Forward direction, Volts
      CALREV1_DEFAULT       // First Calibrate point, Reverse direction, Volts
    },
    {
      CAL2_NOR_VALUE,       // Second Calibrate point in 10 x dBm
      CALFWD2_DEFAULT,      // Second Calibrate point, Forward direction, Volts
      CALREV2_DEFAULT       // Second Calibrate point, Reverse direction, Volts
    }
  },
  {
    { // Coupler 2 Meter calibration for HF     2
      CAL1_NOR_VALUE,       // First calibrate point in 10 x dBm
      CALFWD1_DEFAULT,      // First Calibrate point, Forward direction, Volts
      CALREV1_DEFAULT       // First Calibrate point, Reverse direction, Volts
    },
    {
      CAL2_NOR_VALUE,       // Second Calibrate point in 10 x dBm
      CALFWD2_DEFAULT,      // Second Calibrate point, Forward direction, Volts
      CALREV2_DEFAULT       // Second Calibrate point, Reverse direction, Volts
    }
  },

  {
    { // Coupler 1 Meter calibration for 6M      3   
      CAL1_NOR_VALUE,       // First calibrate point in 10 x dBm
      CALFWD1_DEFAULT,      // First Calibrate point, Forward direction, Volts
      CALREV1_DEFAULT       // First Calibrate point, Reverse direction, Volts
    },
    {
      CAL2_NOR_VALUE,       // Second Calibrate point in 10 x dBm
      CALFWD2_DEFAULT,      // Second Calibrate point, Forward direction, Volts
      CALREV2_DEFAULT       // Second Calibrate point, Reverse direction, Volts
    }
  },
  {
    { // Coupler 2 Meter calibration for 2M    4
      CAL1_NOR_VALUE,       // First calibrate point in 10 x dBm
      CALFWD1_DEFAULT,      // First Calibrate point, Forward direction, Volts
      CALREV1_DEFAULT       // First Calibrate point, Reverse direction, Volts
    },
    {
      CAL2_NOR_VALUE,       // Second Calibrate point in 10 x dBm
      CALFWD2_DEFAULT,      // Second Calibrate point, Forward direction, Volts
      CALREV2_DEFAULT       // Second Calibrate point, Reverse direction, Volts
    }
  },

                                        // Meter calibration if diode detectors
              (uint8_t) METER_CAL*100,  // Calibration fudge of diode detector style meter
              SWR_ALARM,                // Default SWR Alarm trigger, defined in PSWR_A.h
              SWR_THRESHOLD,            // Default SWR Alarm power threshold defined in PSWR_A.h
              0,                        // USB Continuous reporting off
              1,                        // USB Reporting type, 1=Instantaneous Power (raw format) and SWR to USB 
              PEP_PERIOD,               // PEP envelope sampling time in SAMPLE_TIME increments
              0,                        // Default AVG sampling time, 0 for short, 1 for 1 second
              {  
                SCALE_RANGE1,           // User definable Scale Ranges, up to 3 ranges per decade
                SCALE_RANGE2,           // e.g. ... 6W 12W 24W 60W 120W 240W ...
                SCALE_RANGE3            // If all values set as "2", then ... 2W 20W 200W ...
              },
              SLEEPMSG,                 // Shown when nothing else to display on LCD
                                        // Configurable by USB Serial input command: $sleepmsg="blabla"
              SLEEPTHRESHOLD,           // Minimum relevant power to exit Sleep Display (0.001=1uW),
                                        // valid values are 0, 0.001, 0.01, 0.1, 1 and 10
              FLOOR_NOISEFLOOR,         // No low power level threshold, lowest power shown is the effective noise floor
              DEFAULT_MODE,             // Set default Display Mode
              POWER_BARPK,              // Default initial shortcut Display Mode (anything other than MODSCOPE)
              MODSCOPE_DIVISOR,         // Modultion Scope scan rate divisor
                                        // total time of a scan = SAMPLE_TIMER * TFT_x_axis * Divisor
                                        // e.g. 1000us * 300 * 1 = 0.3 seconds for a full sweep
              {
                0,                      // 1 for Upside down, else 0
                7                       // PWM value for tft backlight. 10 max, 0 min
              }
            };

bool leitura_c1 = false;
bool leitura_c2 = false;
bool leitura_c3 = false;
bool leitura_c4 = false;


 int led2 =2;
 int current_coupler = 1;
#if PUSHBUTTON_ENABLED
 static uint8_t  multi_button;             // State of Multipurpose Enact Switch
                                            // (Multipurpose pushbutton)
  static uint8_t  old_multi_button;         // Last state of Multipurpose Enact Switch

static IRAM_ATTR void enc_cb(void* arg) {
  
  ESP32Encoder* enc = (ESP32Encoder*) arg;
  Serial.printf("enc cb: count: %d\n", enc->getCount());
  static bool leds = false;
  digitalWrite(led2, (int)leds);
  leds = !leds;
}

void IRAM_ATTR Enc_SW() {
 multi_button =  multipurpose_pushbutton();

      

}           
#endif
 unsigned long timer ;
       unsigned long pageRefreshTimer = millis(); // Timer for DATA_REFRESH_RATE
        #define DATA_REFRESH_RATE 1000 

couplerSens SensHF1;  // para guardar as calibrações highdbm;  voltHdbn; lowdbm; voltLdbm;
couplerSens SensHF2;
couplerSens SensVHF;
couplerSens SensUHF;
couplerSens DefaultSens;
couplerSens CurrentSens; // coupler selecionado


   // defenir aqui variaveis nextion
   // page 0
        String text1,text2 ;
        // sensor 1 page 2
        int16_t dbm1_s1 ;
        int16_t dbm2_s1 ;
        float volt1_s1;
        float volt2_s1;
        float att_s1;
        float att_cal;
        
        bool newPageLoaded = false; 
    //  page 1



    // page 2


    //page 3
   // ---fim das variaveis nextion

#define Fnex 100  // duas casas decimais para xfloat do nextion
///////////////////////////////////////////////////////////////////
///////////////////  S E T U P   //////////////////////////////////
///////////////////////////////////////////////////////////////////

void setup() {
Serial.begin(115200);
WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

   uint8_t coldstart;
 //---------------------------------------------------------------------------------  
// Mount SPIFFS and read in config file
 if(!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)){
    Serial.println("setup -> SPIFFS Mount Failed");
  }
  else{
    Serial.println("setup -> SPIFFS mounted successfully");
    if(readConfig(config_filename) == false) {
      Serial.println("setup -> Could not read Config file -> initializing new file");
      // if not possible -> save new config file
      if (saveConfig(config_filename)) {
        Serial.println("setup -> Config file saved");
      }   
    }

    //Serial.println("Value1 = " + String(value1) + ", value2 = " + String(value2) + ", user_string = " + user_string);
  }


//----------------------------------------------------------------------------------

  
          
readConfig(config_filename);

  pinMode(led, OUTPUT);

  #if NEXTION
   if (nexInit()){
   //nexSerial.begin(115200, SERIAL_8N1,17,16);
 nexSerial.begin(115200);
    
    }else
    {
Serial.print("NO Nextion!...");

    }
    
 #endif
//-------------------------------------------
  #if EASYNEXTION
 
 nex.begin(115200);
    
  
    
 #endif

//----------------------------------------------
#if (!NEXTION and !EASYNEXTION)
Serial2.begin(115200);
#endif
#if ADS1115
 if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
 #endif
 
EEPROM.begin(512);

coldstart = EEPROM.read(0);               // Grab the coldstart byte indicator in EEPROM for

                                         // comparison with the COLDSTART_REFERENCE
  // Initialize all memories if first upload or if COLDSTART_REF has been modified
  // either through PSWR_A.h or through Menu functions
  if (coldstart != COLDSTART_REF)
  { 
    EEPROM.write(0,COLDSTART_REF);          // COLDSTART_REF in first byte indicates all initialized
    EEPROM_writeAnything(1,R);              // Write default settings into EEPROM
  }
  else                                      // EEPROM contains stored data, retrieve the data
  {
    EEPROM_readAnything(1,R);               // Read the stored data
  }

}// FIM SETUP

///////////////////////////////////////////////////////////////////
///////////////////  L O O P   ////////////////////////////////////
///////////////////////////////////////////////////////////////////

void loop() {

ArduinoOTA.handle();

#if EASYNEXTION
 nex.NextionListen(); 
 if ((millis() - timer) > LOOP_TIME) {
          
            refereshCurrentPage();
            firstRefresh();
         
            timer = millis();
        } else {
            
        }
#endif

  adc_poll_and_feed_circular();
  pswr_sync_from_interrupt();               // Read and process circular buffers containing adc input,
  calc_SWR_and_power();   
  SendNextionFwd();
  SendNextionRev();
  //Serial.print("recebido do nextion : ");
 // Serial.println(volt1_s1);
  //receive_att();
  bool leitura_c1 = false;
bool leitura_c2 = false;
bool leitura_c3 = false;
bool leitura_c4 = false;

}// FIM do LOOP
