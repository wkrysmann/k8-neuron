/*******************************************************************************************************************
 K8 Neutron is intended to be a fully featured, open source and open hardware pre-amplifier 

 project by vojcio: https://github.com/vojcio/k8-neuron

 credits: 
 Volume atenuator algorithm originally from: http://www.dimdim.gr/diyaudio/la-skala-attenuator/
 
 *******************************************************************************************************************/

#include <Wire.h>                                                         // Library for the I2C communication.
#include "Arduino.h"                                                      // Basic Arduino library 
#include "Volume.h"                                                       // Volume attenuator library
#include "Inputs.h"                                                       // Controll the inputs
#include "InputSource.h"                                                  // Input Source selector
#include "Log.h"                                                          // Logging class
#include "Eprom.h"                                                        // Library to controll Eeprom

// config
const int volUpPin = '3';                                                 // RotEnc A terminal for right rotary encoder.
const int volDownPin = '2';                                               // RotEnc B terminal for right rotary encoder.
const int srcUpPin = '5';                                                 // RotEnc A terminal for right rotary encoder.
const int srcDownPin = '4';                                               // RotEnc B terminal for right rotary encoder.
// logging conf
const boolean serialLog = 1;                                               // Enables or disables logging to serial output
const int logLevel = 3;                                                    // Possible log levels: 1 - Error, 2 - Notice, 3 - Debug - disable logging
const int baudRate = 9600;                                                 // Serial baud rate setting, default = 9600
float resVals[8] = {64, 32, 16, 8, 4, 2, 1, 0.5};                          // First relay will attenuate by 64db, Eighth relay will attenuate by 0.5db.                                    
// config end

const int volume = 1;                                                       // constants to point classes (inputs class, eeprom class) to valid execution
const int source = 2;

float volChange = 0;
int srcChange = 0;
unsigned int maxSrc = 8;
Volume vol(resVals, &volChange);                                  // Construct volume attenuation class
InputSource inSrc(&srcChange, maxSrc);                                    // Construct input source class
Inputs in(&volChange, &srcChange, volDownPin, volUpPin, srcUpPin, srcDownPin);                      // Construct inputs 
Log mBus;                                             // Construct log/message bus class
Eprom eprom;                                          // Construct class to use eeprom

void setup() {
  mBus.configure(logLevel, serialLog, baudRate);
  mBus.debug("Passed message bus configure with loglevel ", String(logLevel));
  //vol.initMcp();
//  vol.set(eprom.get(volume));                                              mBus.debug("setup starting volume, as fast as it can be, to avoid noises", "");
//  inSrc.set(eprom.get(source));                                            mBus.debug("setup starting input, as fast as it can be, to avoid unexpected behaviour");

mBus.info("MAIN LOOP BEGINS!!", ""); }
void loop() {
/*  
    if(in.getVolChange()) {
      Serial.print("volume will change: "); Serial.println(volChange);
      vol.change();
    }
    if(in.getSrcChange()) {
      Serial.print("Source will change: "); Serial.println(srcChange);
      inSrc.change();                                             //mBus.debug("Setting a new input source", "");
    }
    */
}
