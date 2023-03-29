/******************************************************************************
 * Code by IridiumOre
 * 
 * SunsetLamp on millis() scheduler
 * 
 * ***************************************************************************/

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <ezButton.h>
#include <RTClib.h>
#include <Wire.h>
#include "inc/pinout.hpp"

unsigned long prevMillis = 0;
int butt_state = 0;
int led_state = 0;

const long led_blink_on = 1000;
const long led_blink_off = 1500;

void setup()
{
  //LED for testing buttons
  pinMode(TEST_LED, OUTPUT);
}

void loop()
{
  static uint32_t ledTimeOn = millis();

  if(millis() - ledTimeOn >= led_blink_on && !led_state)
  {
    ledTimeOn = millis();
    led_state = 1;
    digitalWrite(TEST_LED, 1);
  }
  if(millis() - ledTimeOn >= led_blink_off)
  {
    ledTimeOn = millis();
    led_state = 0;
    digitalWrite(TEST_LED, LOW);
  }
}
