/*********************************************************************
Arduino STAR OTTO with temperature/humidity sensor Si7021 

Websites (EN) https://time4ee.com
(CZ/SK) https://chiptron.cz

Si7021 arduino library by https://learn.sparkfun.com/tutorials/si7021-humidity-and-temperature-sensor-hookup-guide 

This code has to contain "Serial.begin", because without this, OTTO is stopped. SparkFun lib contains serial messages
This bug is reported on arduino-org github
*********************************************************************/

#include "SparkFun_Si7021_Breakout_Library.h"
#include <Wire.h>

float humidity = 0;
float tempC = 0;

//Create Instance of HTU21D or SI7021 temp and humidity sensor and MPL3115A2 barrometric sensor
Weather sensor;

//---------------------------------------------------------------
void setup()
{
    SerialUSB.begin(9600);   // open serial over USB at 9600 baud
    Serial.begin(9600);   // open serial at 9600 baud, Si7021 SparkFun lib contains serial messages
    
    //Initialize the I2C sensors and ping them
    sensor.begin();

}
//---------------------------------------------------------------
void loop()
{
  //Get readings from all sensors
  //Measure Relative Humidity from the HTU21D or Si7021
  humidity = sensor.getRH();

  //Measure Temperature from the HTU21D or Si7021
  tempC = sensor.getTemp();

  SerialUSB.print("Temp:");
  SerialUSB.print(tempC);
  SerialUSB.print(" °C, ");

  SerialUSB.print("Humidity:");
  SerialUSB.print(humidity);
  SerialUSB.println(" %");
  
  delay(1000);

}

