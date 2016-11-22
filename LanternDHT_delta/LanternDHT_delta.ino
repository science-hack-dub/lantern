/*
  Lantern DHT
  This sketch was written for Science hack day at the Tog Maker 
  space in Dublin, Ireland. 20 November 2016. 
  It it based on ladyada's public domain DHTtester. 
  This sketch uses uses only the temperature 
  from the DHT temperature and humidity sensor. 

  The DHT sensor is slow so we only read it every 64 loop iterations
   
  Modified 22 November 2016 by Brian Nitz
  
  This example code is in the public domain.
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
int loop_count = 0;

DHT dht(DHTPIN, DHTTYPE);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize red and green LED pins as outputs.
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  dht.begin();
  temp_c = dht.readTemperature();
  prev_temp_c = temp_c;
  loop_count = 0;
}

void loop() {
  if (loop_count % 64 == 0) {
      temp_c = dht.readTemperature();
        // Check if any reads failed and exit early (to try again).
      if (isnan(temp_c)) {
          return;
      }
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
