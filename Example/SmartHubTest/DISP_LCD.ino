#ifdef __MANAGE_LCD__

void _LCD_Setup( void )
{
  g_Display.init();
  g_Display.setRotation(1);
  g_Display.fillScreen(TFT_BLACK); 
}

void _LCD_DisplayTestMessage( void )
{
  #ifdef __DEBUG__
    g_SerialDebug.println("LCD : init");
  #endif
  
}


void _LCD_DisplayStartMessage( void )
{
  // Set "cursor" at top left corner of display (0,0) and select font 4
  g_Display.setCursor(0, 0, 4);
  // Set the font colour to be white with a black background
  g_Display.setTextColor(TFT_WHITE, TFT_BLACK);
  // We can now plot text on screen using the "print" class
  g_Display.println("Initialised\n");
}
#endif
