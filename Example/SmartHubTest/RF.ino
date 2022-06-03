#ifdef __MANAGE_RF__

void _RF_ProcessInput(unsigned long decimal, unsigned int length, unsigned int delay, unsigned int protocol) 
{
char  str[64];
unsigned int l_delay_min, l_delay_max, l_decimal, l_length, l_protocol;

  #ifdef __DEBUG__
    g_SerialDebug.print("Value: ");
    g_SerialDebug.print(decimal);
    g_SerialDebug.print(" Length:");
    g_SerialDebug.print( length );
    g_SerialDebug.print(" Type: ");
    g_SerialDebug.print(protocol);
    g_SerialDebug.print(" Delay: ");
    g_SerialDebug.println(delay);
  #endif  

}



  

#endif
