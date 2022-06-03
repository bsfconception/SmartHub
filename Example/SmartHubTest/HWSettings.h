#define __DEBUG__
#define __LOG_EVENT__

//#define __DEBUG_FCT__(a)  g_SerialDebug.println(__FUNCTION__)
//#define __DEBUG_LINE__(a)  g_SerialDebug.println(__LINE__)

#define __DEBUG_FCT__(a)
#define __DEBUG_LINE__(a)


// SD Card pins 
#define _SD_SCLK      25
#define _SD_MISO      18
#define _SD_MOSI      19
#define _SD_CS        33

#define _TFT_CS       23
#define _TFT_DC       15
#define _TFT_RESET    4 
#define _TFT_SCLK     25
#define _TFT_MOSI     19

#define _I2C_SCL      22
#define _I2C_SDA      21

#define _SIM_RESET    5
#define _SIM_TX       27
#define _SIM_RX       26

#define _RF_SENDER    2
#define _RF_RECEIVER  14

#define _D_BP1        35
#define _A_BP2        32


#define _IO12_        12
#define _IO13_        13
#define _IO34_        34
#define _S_VP_        36
#define _S_VN_        39


#define BUTTON_NONE      0
#define BUTTON_SELECT    1
#define BUTTON_LEFT      2 
#define BUTTON_MIDDLE    3
#define BUTTON_RIGHT     4
#define BUTTON_UP        5
#define BUTTON_DOWN      6
