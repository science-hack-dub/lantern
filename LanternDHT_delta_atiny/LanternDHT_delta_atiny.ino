/*
  Lantern DHT
  This sketch was written for Science hack day at the Tog Maker 
  space in Dublin, Ireland. 20 November 2016. 
  It it based on my LanternDHT_delta which was based on ladyada's 
  public domain DHTtester. But this sketch uses a thermister and 
  the analogue input to the Atiny85 in order to light a red or blue 
  LED based on temperature changes.

   Temperature cooler than last sample - threshold: Light Blue LED
   Temperature warmer as last sample + threshold: Light Red LED
   Temperature within threshold of last sample: Don't change LED state

   Bug: There is a state where neither LEDs are on until the temperature
   rises or falls by more than the threshold.
   
   Modified 22 November 2016 by Brian Nitz
  
  This code is in the public domain.
*/


int RED_LED = 0;
int BLUE_LED = 1;
int temp_c = 0;
int prev_temp_c = 0;
int loop_count = 0;
const int threashold = 10;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize the inputs and outputs
  pinMode (A3, INPUT); 
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  temp_c = analogRead(A3);
  prev_temp_c = temp_c;
  loop_count = 0;
}

void loop() {
  if (loop_count % 64 == 0) {
      // Analog reads are a bit slow so we'll only do it once every 64 loop iterations
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
