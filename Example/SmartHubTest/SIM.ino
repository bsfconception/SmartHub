#ifdef __MANAGE_SIM__



void _SIM_Init()
{
    // Set GSM module baud rate and UART pins
    digitalWrite(_SIM_RESET, LOW); // SIM Reset to LOW
    g_SerialSIM.begin(9600, SERIAL_8N1, _SIM_RX, _SIM_TX);
}


#endif
