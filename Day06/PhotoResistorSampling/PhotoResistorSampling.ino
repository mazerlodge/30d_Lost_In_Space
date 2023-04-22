/*
30d Lost in Space Day 6

	Read a photo resistor.
	Blink the onboard LED for a period equal to the sensor value.
	More light it slower blink (longer on and off interval).
	
Revision History:
	20230122 - Initial version
	20230422 - Mod to only output to the serial port if the sensor value changed by +/-2.
			 - Comments added.

*/
int photoSensePin = A0;
int onboardLED = 13;
int photoSenseValue = 0;
int prevSenseValue = -1;

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	pinMode(onboardLED, OUTPUT); 

}

void loop() {
	// Get the sensor value, more light = higher number.
	photoSenseValue = analogRead(photoSensePin); 

	// light the onboard LED for time relative to sensor value.
	digitalWrite(onboardLED, HIGH);
	delay(photoSenseValue);
	digitalWrite(onboardLED, LOW);
	delay(photoSenseValue);

	// Only output to the serial console if the sensor value changed.
	if ((photoSenseValue < prevSenseValue - 2)
		|| (photoSenseValue > prevSenseValue + 2)) { 
		prevSenseValue = photoSenseValue;
		Serial.println(photoSenseValue);
		delay(photoSenseValue);

	}

}
