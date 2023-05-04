/*
30d Lost in Space Day 9

Basic RGB LED Demo
	
Revision History:
	20230503 - Initial version


*/ 
 
int sensorPin = A0;   
int sensorValue = 0;  
 
// Output pins for three LED colors 
int redPin = 11;  
int greenPin = 10;
int bluePin = 9;
 
unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
unsigned int ticks = 0;
unsigned int wait = 100;
double percentFull;
 
//******************************************
 
void setup() {

  // Declare the RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
 
  // Start serial monitor
  Serial.begin(9600);
  
}
 
void setRGBColor(int red_value, int green_value, int blue_value) {
	// Set three PWM color channels to any given mixture
 
	analogWrite(redPin, red_value);
	analogWrite(greenPin, green_value);
	analogWrite(bluePin, blue_value);

}
 
 double getBatteryPercentage() {
	// Calculates battery charge percentage
	// returns the result as a double precision number

	return (((double) batteryLevel / (double) batteryCapacity) * 100);
 
}
 
void showBatteryPercentage() {
  	//  Send battery results to both serial and LED outputs

	//  calculate the charge percentage with a custom function...
	percentFull=getBatteryPercentage();
 
	// print the elasped time and percent full
	Serial.print(ticks);
	Serial.print(" ms    charge at ");
	Serial.print(percentFull);
	Serial.println("%");
 
	// Light the LED with the appropriate color...
	if (percentFull > 0 && percentFull <= 25) {
		setRGBColor(125, 0, 0); // red
	}
	else if (percentFull > 25 && percentFull <= 50) {
		setRGBColor(125, 80, 0); // yellow-ish
		
	}
	else if (percentFull > 50 && percentFull <= 75) {
		setRGBColor(0, 125, 125); // blue-ish
	}
	else if (percentFull > 75 && percentFull < 100) {
		setRGBColor(125, 125, 125); // white
	}

}
  
void loop() {
	sensorValue = analogRead(sensorPin); // read the value from the sensor
	batteryLevel += sensorValue;
	ticks += wait;

	if(batteryLevel >= batteryCapacity) {
		Serial.print(ticks);
		Serial.print(" ms     ");
		Serial.println("FULLY CHARGED");
		batteryLevel = batteryCapacity; // to prevent integer from continuing to increase
		ticks = 0;
		setRGBColor(0, 125, 0); // Green for charging complete
		delay(30000);      // long pause
	}
	else {
		showBatteryPercentage();
	}

	delay(wait);

}