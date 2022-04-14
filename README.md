# SmartHub
ESP32 Multipurpose interface board


#### What is it?
System composed of 2 PCB boards : the Master and optionnel Slave boards.
The main board includes the following features : 
- ESP32 Wrover Processor with BT / Wifi
- USB to Serial CHG340 interface (communication and programming)
- DS3231 RTC Clock + backup battery holder
- DC/DC power converter from 5-9V to 3.3V and 4.1V
- MicroSD Card holder
- GPRS SIM800L module support with signal level convertor
- RF Transmitter and Receiver module printout
- DC power supply input
- 
the optional Slave Board supports:
- 1.44' SPI LCD TFT screen (or)
- 1.2' I2C OLED screen 
- 6 push-button keyboard
- Power Switch
- IO connectors

#### Why did you make it?
I did create a lot of individual systems to interconnect IOT and Domotic devices to math to all my needs like
- Domotic Web Serveur -> All IOT devices
- GPRS SMS -> RF controlled Gates and Door
- Alexa -> Connected Lights and Switches
- RF Transmitter -> RF Switches, gates, lights
- Rest API -> RF receivers
- ....

At the and, the global control and communication requires at least 4 bridges dedicated to specific protocol conversion.

I've decided to merge all of the into a one unique smart hub able to
-> Receive messages from 
  - Alexa : using Philips Hue and Wemos protocols
  - RF message : PT2262 / EV1527 protocol
  - Rest API switch and light control
  - GPRS SMS orders 
-> Convert and forward to
  - Philips Hue, Wemos, Redmi Light
  - RF switches : PT2262 / EV1527 protocol
  - Rest API custom URL
  - GPRS SMS messages 

But, according to you need you can totally adapt the usage of the module according to your needs.

#### What makes it special?

It it provided in an small form factor including the most current communication interfaces. 
The module does not require additional system to ne programmed or to run .. just a power supply. The included USB to Serial interface also controls the programming signals. 
The board is 100% compatible with Arduino GUI and libraries.

The PCB are provided WITHOUT any soldered devices.
A presoldered ans tested version can be provided on request.
