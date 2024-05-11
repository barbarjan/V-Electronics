/*
  433 MHz RF Module Transmitter Demonstration 1
  RF-Xmit-Demo-1.ino
  Demonstrates 433 MHz RF Transmitter Module
  Use with Receiver Demonstration 1

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

void setup()
{
    // Initialize ASK Object
    rf_driver.init();

    // Initialize builtin LED
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.println("START");
}

void loop()
{
    Serial.println("START");
    digitalWrite(LED_BUILTIN, HIGH);
    const char *msg = "Welcome to the Workshop!";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    Serial.println("sent packet");
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);


}