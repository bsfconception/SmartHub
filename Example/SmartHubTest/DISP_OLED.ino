#ifdef __MANAGE_OLED__

#define OLED_Font_Size6  u8g2_font_profont10_tr // 6PX
#define OLED_Font_Size8  u8g2_font_profont12_tr // 8PX
#define OLED_Font_Size11  u8g2_font_profont17_tr // 11PX
#define OLED_Font_Size14  u8g2_font_profont22_tr // 14PX
#define OLED_Font_Size19  u8g2_font_profont29_tr // 19PX

void _OLED_Setup( void )
{
  #ifdef __DEBUG__
    g_SerialDebug.println("OLED : init");
  #endif

  g_Display.begin();
  g_Display.clearBuffer();          // clear the internal memory
}


void _OLED_DisplayStartMessage( void )
{
  g_Display.clearBuffer();          // clear the internal memory
  g_Display.setFont(OLED_Font_Size8); // choose a suitable font

  g_Display.drawStr(0,10,"BSF Conception");  // write something to the internal memory
  g_Display.sendBuffer();     
}


#endif
