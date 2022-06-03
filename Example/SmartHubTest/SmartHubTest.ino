//#define __MANAGE_LCD__
#define __MANAGE_OLED__
#define __MANAGE_SIM__
#define __MANAGE_SDCARD__
#define __MANAGE_RF__
#define __MANAGE_KEYBOARD__
#define __MANAGE_RTC__

#include <SPI.h>
#include <FS.h>
#include <SD.h>
 
#include <Wire.h>
#include "HWSettings.h"


#ifdef __MANAGE_OLED__
  SPIClass SPI2(HSPI);
#endif


#ifdef __MANAGE_LCD__
// Modify the User_Setup_Select.h before compiling in C:\Users\**user**\Documents\Arduino\libraries\TFT_eSPI
// the configuration for this board is : SmartHub.h
#include <TFT_eSPI.h>       // Hardware-specific library
TFT_eSPI g_Display = TFT_eSPI();  // Invoke custom library
#endif


#ifdef __MANAGE_OLED__
  #include <U8g2lib.h>
  U8G2_SH1106_128X64_NONAME_F_HW_I2C g_Display(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
#endif

// Set serial for AT commands (to the SIM module)
#ifdef __MANAGE_SIM__
  #define g_SerialSIM  Serial1
#endif

#ifdef __MANAGE_RTC__
  #include "RTClib.h"
  DateTime g_curDateTime;  
  RTC_DS3231 g_rtc;
#endif

#ifdef __MANAGE_RF__
  #include <RCSwitch.h>
   RCSwitch g_RFModem = RCSwitch();
#endif


// Set serial for debug console (to the Serial Monitor, default speed 115200)
#define g_SerialDebug Serial




void setup(void) 
{

  g_SerialDebug.begin(115200);
  g_SerialDebug.println("Starting");


  // Set all chip selects high to avoid bus contention during initialisation of each peripheral
  digitalWrite(_SD_CS, HIGH); // SD card chips select
  digitalWrite(_TFT_CS, HIGH); // TFT screen chip select
  
  
  pinMode(_RF_SENDER, OUTPUT);   
  digitalWrite(_RF_SENDER, LOW); // RF message OFF
  pinMode(_RF_RECEIVER, INPUT);   

  pinMode(_D_BP1, INPUT);   
  pinMode(_A_BP2, INPUT);   

    // init i2C communication 
  Wire.begin(_I2C_SDA, _I2C_SCL);


#ifdef __MANAGE_LCD__
  _LCD_Setup();
  _LCD_DisplayStartMessage();
#endif

#ifdef __MANAGE_OLED__
  _OLED_Setup();
  _OLED_DisplayStartMessage();
#endif
 
#ifdef __MANAGE_SIM__
  _SIM_Init();
#endif
#ifdef __MANAGE_SDCARD__
  _SD_MountSDCard();
#endif
#ifdef __MANAGE_RTC__
  _RTC_Init();
#endif


#ifdef __MANAGE_RF__
  #include <RCSwitch.h>
   RCSwitch g_RFModem = RCSwitch();
  g_RFModem.enableTransmit(_RF_SENDER);
  g_RFModem.enableReceive(_RF_RECEIVER);  // Receiver on interrupt 0 => that is pin D5-Wemos

#endif


}

String MessageBuffer;

void loop() 
{
char c;
long siz;
int y, mo, d, h, m, s, res;
int BPVal=4096, BP;

 if (g_RFModem.available()) 
 {
    _RF_ProcessInput(g_RFModem.getReceivedValue(), g_RFModem.getReceivedBitlength(), g_RFModem.getReceivedDelay(),g_RFModem.getReceivedProtocol());
    g_RFModem.resetAvailable();
 }

    
  if (g_SerialDebug.available()) {      // If anything comes in Serial (USB),
      c = g_SerialDebug.read();
      g_SerialDebug.write(c);   
      g_SerialSIM.write(c);   
  }
 
  while (g_SerialSIM.available()) 
  {     // If anything comes in Serial1 (pins 0 & 1)
    g_SerialDebug.write(g_SerialSIM.read());   // read it and send it out Serial (USB)
  }

  
  res = _KEY_GetButton();
  if(res == BUTTON_SELECT)
  {
      // get SD info
      siz = SD_GetCardSize();
      g_SerialDebug.print("SDCard Mount PASS : ");
      g_SerialDebug.println(siz);
      
      // Get RTC info
      _RTC_GetCurrent(&y, &mo, &d, &h, &m, &s );
      MessageBuffer = (char)(h / 10 + '0');
      MessageBuffer = MessageBuffer + (char)(h % 10 + '0');
      MessageBuffer = MessageBuffer + ":";
      MessageBuffer = MessageBuffer + (char)(m / 10 + '0');
      MessageBuffer = MessageBuffer + (char)(m % 10 + '0');
      MessageBuffer = MessageBuffer + ":";
      MessageBuffer = MessageBuffer + (char)(s / 10 + '0');
      MessageBuffer = MessageBuffer + (char)(s % 10 + '0');
      
      g_SerialDebug.print("Time : ");
      g_SerialDebug.println( MessageBuffer.c_str() );
  
  }

  
  delay(500);

}
