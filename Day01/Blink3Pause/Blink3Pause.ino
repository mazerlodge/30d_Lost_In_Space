/*
  Blink

  Turns the onboard LED on and off rapidly 3 times, then pauses for 1 second and repeats.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  for (int x=0;x<3;x++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(150); 
    digitalWrite(LED_BUILTIN, LOW); 
    delay(150); 
  }
  
  delay(1000);
}
