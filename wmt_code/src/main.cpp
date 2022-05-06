/******************************************************************************
 * Code by IridiumOre
 * 
 * WashingMachineTimer on millis() scheduler
 * 
 * Wash Machine Model: 
 * 
 * ***************************************************************************/

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <ezButton.h>

#define buttonRightPin 8
#define buttonLeftPin 9
#define buttonOkPin 10

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);

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
}

void loop()
{
  static uint32_t ledTimeOn = millis(), lcdTime = ledTimeOn, buttTime = ledTimeOn;

  if(millis() - lcdTime >= lcd_refresh)
  {
    lcdTime = millis();

    // Set the cursor on the third column and the first row, counting starts at 0:
    lcd.setCursor(2, 0);
    // Print the string 'Hello World!':
    lcd.print("Hello World!");
    // Set the cursor on the third column and the second row:
    lcd.setCursor(2, 1);
    // Print the string 'LCD tutorial':
    lcd.print("LCD tutorial");
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