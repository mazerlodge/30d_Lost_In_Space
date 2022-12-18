int PIN_LED1 = 10; 
int PIN_LED2 = 11; 
int PIN_LED3 = 12; 

int PIN_SWITCH1 = 2;
int PIN_SWITCH2 = 3;
int PIN_SWITCH3 = 4;


void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);

  pinMode(PIN_SWITCH1, INPUT);
  pinMode(PIN_SWITCH2, INPUT);
  pinMode(PIN_SWITCH3, INPUT);
  
}

void loop() {

  if (digitalRead(PIN_SWITCH1) == HIGH)  
    doBlinkPattern(PIN_LED1);
  else 
    digitalWrite(PIN_LED1, LOW);
  

  if (digitalRead(PIN_SWITCH2) == HIGH) 
    doBlinkPattern(PIN_LED2);
  else 
    digitalWrite(PIN_LED2, LOW);
  

  if (digitalRead(PIN_SWITCH3) == HIGH)  
    doBlinkPattern(PIN_LED3);
  else 
    digitalWrite(PIN_LED3, LOW);
  
}

void doBlinkPattern( int LED_PIN) {
  
    for (int x=0;x<3;x++) {
      digitalWrite(LED_PIN, HIGH);
      delay(150); 
      digitalWrite(LED_PIN, LOW); 
      delay(150); 
    }

    delay(1000);

}
