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


int RED_LED = 0;
int BLUE_LED = 1;
int temp_c = 0;
int prev_temp_c = 0;
int loop_count = 0;
const int threashold = 10;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode (A3, INPUT); 
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  temp_c = analogRead(A3);
  prev_temp_c = temp_c;
  loop_count = 0;
}

void loop() {
  if (loop_count % 64 == 0) {
      temp_c = analogRead(A3);
      if (abs(temp_c - prev_temp_c) > threashold) {
          if (temp_c - prev_temp_c) {
              digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
              digitalWrite(BLUE_LED, LOW);   // turn the LED on (HIGH is the voltage level)
          }
          if (temp_c < prev_temp_c) {
              digitalWrite(RED_LED, LOW);    // turn the LED off by making the voltage LOW
              digitalWrite(BLUE_LED, HIGH);    // turn the LED off by making the voltage LOW
          }
      prev_temp_c = temp_c;
      }
  } 
  loop_count ++;

}
