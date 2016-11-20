/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.
  HDT22

  modified 8 May 2014
  by Scott Fitzgerald
 */

 #include "DHT.h"
 #define DHTTYPE DHT11   // DHT 11

 #define DHTPIN 2 // what digital pin we're connected to

int RED_LED = 12;
int BLUE_LED = 13;
int RED_ON = 100;
int BLUE_ON = 20;

const int BLINK_MIN = 1;
const int BLINK_MAX = 20;

float temp_c = 0.0;
float prev_temp_c = 0.0;


DHT dht(DHTPIN, DHTTYPE);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  // Serial.begin(9600);
  //Serial.println("DHTxx test!");
  dht.begin();
  temp_c = dht.readTemperature();
  prev_temp_c = temp_c;
  temp_int_c = int(temp_c * TEMP_SCALE);
  loop_count = 0;
}

void loop() {
  if (loop_count % 64 == 0) {
      temp_c = dht.readTemperature();
        // Check if any reads failed and exit early (to try again).
      if (isnan(temp_c)) {
          return;
      }
      temp_int_c = int(temp_c * TEMP_SCALE);
      if (temp_c > prev_temp_c) {
          digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(BLUE_LED, LOW);   // turn the LED on (HIGH is the voltage level)
      }
      if (temp_c < prev_temp_c) {
          digitalWrite(RED_LED, LOW);    // turn the LED off by making the voltage LOW
          digitalWrite(BLUE_LED, HIGH);    // turn the LED off by making the voltage LOW
      }
      prev_temp_c = temp_c;
  } 
  loop_count ++;
  


}
