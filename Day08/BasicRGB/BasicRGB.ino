/*
30d Lost in Space Day 8

Basic RGB LED Demo
	
Revision History:
	20230426 - Initial version


*/ 

// Pins connected to RGB LED 
int redPin = 11;  
int greenPin = 10;
int bluePin = 9;
 
void setup() {
	
	// Init pins connected to RGB LED 
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);

}
 
void RGB_color(int red_value, int green_value, int blue_value) {

	analogWrite(redPin, red_value);
	analogWrite(greenPin, green_value);
	analogWrite(bluePin, blue_value);
}
 
 
 
void loop() {

	// Do basic color test. 
	RGB_color(125, 0, 0); // Red
	delay(800);
	RGB_color(0, 125, 0); // Green
	delay(800);
	RGB_color(0, 0, 125); // Blue
	delay(800);
	RGB_color(64, 32, 0); // yellow
	delay(800);
	RGB_color(125, 0, 125); // purple
	delay(800);
	RGB_color(125, 125, 125); // white
	delay(2000);
	
}