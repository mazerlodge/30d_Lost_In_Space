/*
30d Lost in Space Day 7

	Read a photo resistor.
	Simulate charging a battery, adding each sensor value to the 'battery level'
	
Revision History:
	20230422 - Initial version


*/

int photoSensePin = A0;
int onboardLED = 13;
int photoSenseValue = 0;
int prevSenseValue = -1;		// TODO: m/b not needed

// Using unsigned b/c 50k over int limit of ~32k
unsigned int battCapacity = 50000;
unsigned int battLevel = 0;
unsigned int ticks = 0;

unsigned int wait = 100;
unsigned int longWait = 20000;

double battPercentFull;
 
void setup() {
	pinMode(onboardLED, OUTPUT);
	Serial.begin(9600);
	
}
 
void PrintBatteryPercentage() {
	// Output elapsed time
	Serial.print(ticks);
	Serial.print(" ms    charge at ");
 
	//  Output batt status
	battPercentFull=100*((double)battLevel / (double)battCapacity);
	Serial.print(battPercentFull);
 	Serial.println("%");

}
 
void loop() {
	// Sample sensor and add val to battery level.
	photoSenseValue = analogRead(photoSensePin);
	battLevel += photoSenseValue;

	// Update elapsed time.
	ticks += wait;

	// Check for full battery.
	if(battLevel >= battCapacity) {
		battLevel = battCapacity; 

		// Output battery full message.
		Serial.print(ticks);
		Serial.print(" ms     ");
		Serial.println("FULLY CHARGED");
		ticks = 0;
		delay(longWait);

	}
	else {
		PrintBatteryPercentage();

	}

	delay(wait);
	
}
