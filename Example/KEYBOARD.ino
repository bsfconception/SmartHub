#ifdef __MANAGE_KEYBOARD__



int _KEY_GetButton( void )
{
int BPVal=4096, BP;
int Btn = BUTTON_NONE;

  BP = digitalRead(_D_BP1);
  BPVal = analogRead(_A_BP2);
/*  
  #ifdef __DEBUG__
    g_SerialDebug.print("_A_BP2 : ");
    g_SerialDebug.println(BPVal);
  #endif  
*/
  if(BP == 0)
  {
    Btn = BUTTON_SELECT;
  } 
  else
  {
    if( BPVal < 265 )
    {
      Btn = BUTTON_LEFT;
    }
    else
    {
      if( BPVal < 966 )
      {
        Btn = BUTTON_UP;
      }
      else
      {
        if( BPVal < 1780 )
        {
          Btn = BUTTON_RIGHT;
        }
        else
        {
          if( BPVal < 2587 )
          {
            Btn = BUTTON_DOWN;
          }
          else
          {
            if( BPVal < 3557 )
              Btn = BUTTON_MIDDLE;
          }
        }
      }
    }
  }
   
  #ifdef __DEBUG__
    g_SerialDebug.print("KEYB : ");
    g_SerialDebug.println( Btn );
  #endif
  return(Btn);
}


#endif
