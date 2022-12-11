/*
  Blink

  Turns an LED connected to pin 12 when a switch on pin 2 is detected as on
  
*/

// Global vars
int LED_PIN = 12; 
int SWITCH_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  

  pinMode(SWITCH_PIN, INPUT); 
  
}

void loop() {

  if (digitalRead(SWITCH_PIN) == HIGH) {

    for (int x=0;x<3;x++) {
      digitalWrite(LED_PIN, HIGH);
      delay(150); 
      digitalWrite(LED_PIN, LOW); 
      delay(150); 
    }
    
    delay(1000);

  } // end if 
  
}
