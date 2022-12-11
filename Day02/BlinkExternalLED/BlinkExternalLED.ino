/*
  Blink

  Turns an LED connected to pin 12 on and off rapidly 3 times, then pauses for 1 second and repeats.

*/

// Global vars
int LED_PIN = 12; 

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  
  
}

void loop() {

  for (int x=0;x<3;x++) {
    digitalWrite(LED_PIN, HIGH);
    delay(150); 
    digitalWrite(LED_PIN, LOW); 
    delay(150); 
  }
  
  delay(1000);
}
