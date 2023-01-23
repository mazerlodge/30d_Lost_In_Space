
int photoSensePin = A0;
int onboardLED = 13;
int photoSenseValue = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(onboardLED, OUTPUT); 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  photoSenseValue = analogRead(photoSensePin); 

  digitalWrite(onboardLED, HIGH);
  delay(photoSenseValue);
  digitalWrite(onboardLED, LOW);
  delay(photoSenseValue);

  Serial.println(photoSenseValue);
  delay(photoSenseValue);
 

}
