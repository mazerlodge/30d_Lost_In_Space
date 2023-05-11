/*
30d Lost in Space Day 10

Deluxe RGB LED Demo
	
Revision History:
	20230510 - Initial version


*/ 

#define False 0
#define True  1

// Pins connected to RGB LED 
int redPin = 11;  
int greenPin = 10;
int bluePin = 9;

bool bRIncreasing = True;
bool bGIncreasing = True;
bool bBIncreasing = True;

int rVal = 0;
int gVal = 0;
int bVal = 0;

bool bIncreasing = True;
int rgbVals[] = {0, 0, 0};
int idx=0;

int COLOR_DELAY = 42;
 
void setup() {
	
	// Init pins connected to RGB LED 
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);

	// Start serial monitor
	Serial.begin(9600);

}
 
void RGB_color(int red_value, int green_value, int blue_value) {

	analogWrite(redPin, red_value);
	analogWrite(greenPin, green_value);
	analogWrite(bluePin, blue_value);
}
 
 
 
void loop() {

	for (int x=0; x<255; x+=5) {

		if (bIncreasing) 
			rgbVals[idx] += 5;
		else 
			rgbVals[idx] -= 5;

		RGB_color(rgbVals[0], rgbVals[1], rgbVals[2]); 
		delay(COLOR_DELAY);
		
		Serial.print(rgbVals[0]);
		Serial.print(" ");
		Serial.print(rgbVals[1]);
		Serial.print(" ");
		Serial.print(rgbVals[2]);
		Serial.println(" ");

	}

	// Update index (indicator of which color is changing)	
	if (!bIncreasing) {
		idx++; 
		if (idx > 2) 
			idx = 0; 
	}
		
	// If were increasing, switch to decreasing and vice versa.
	bIncreasing = (bIncreasing ? False : True); 

	
}