/******************************************************************************
 * Code by IridiumOre
 * 
 * WashingMachineTimer on millis() scheduler
 * 
 * Wash Machine Model: Electrolux EWT 11262ILW
 * 
 * ***************************************************************************/

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <ezButton.h>
#include <RTClib.h>
#include <Wire.h>

//#include "wm_data.h"

#define buttonRightPin 8
#define buttonOkPin 9
#define buttonLeftPin 10

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);
RTC_DS1307 RTC;

unsigned long prevMillis = 0;
int butt_state = 0;
int led_state = 0;

const long led_blink_on = 1000;
const long led_blink_off = 1500;
const long lcd_refresh = 500;
const long butt_check = 100;

void setup()
{
  //LED for testing buttons
  pinMode(LED_BUILTIN, OUTPUT);

  //Buttons
  pinMode(8, INPUT);

  // Specify the LCD's number of columns and rows
  lcd.begin(16, 2);

  Wire.begin();
  RTC.begin();

  RTC.adjust(DateTime(__DATE__, __TIME__));
}

void loop()
{
  static uint32_t ledTimeOn = millis(), lcdTime = ledTimeOn, buttTime = ledTimeOn;

  if(millis() - lcdTime >= lcd_refresh)
  {
    lcdTime = millis();

    // // Set the cursor on the third column and the first row, counting starts at 0:
    // lcd.setCursor(2, 0);
    // // Print the string 'Hello World!':
    // lcd.print("Hello World!");
    // // Set the cursor on the third column and the second row:
    // lcd.setCursor(2, 1);
    // // Print the string 'LCD tutorial':
    // lcd.print("LCD tutorial");

    DateTime now = RTC.now();

    lcd.setCursor(0,0);
    lcd.print("RTC test");
    lcd.setCursor(0,1);
    lcd.print(now.hour());
    lcd.print(":");
    lcd.print(now.minute());
    lcd.print(":");
    lcd.print(now.second());
  }

  if(millis() - buttTime >= butt_check)
  {
    buttTime = millis();

    butt_state = digitalRead(buttonRightPin);
  }

  if(millis() - ledTimeOn >= led_blink_on && butt_state && !led_state)
  {
    ledTimeOn = millis();
    led_state = 1;
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if(millis() - ledTimeOn >= led_blink_off)
  {
    led_state = 0;
    digitalWrite(LED_BUILTIN, LOW);
  }
}



// 6:26 - 8:16 = 1h 50 min