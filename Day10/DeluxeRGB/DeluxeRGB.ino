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

	for (int r=0; r<255; r+=5) {
		if (bRIncreasing) 
			rVal += 5;
		else 
			rVal -= 5;

		for (int g=0; g<255; g+=5) {
			if (bGIncreasing) 
				gVal += 5;
			else 
				gVal -= 5;

			for (int b=0; b<255; b+=5) {

				if (bBIncreasing) 
					bVal += 5;
				else 
					bVal -= 5;
			
				RGB_color(rVal, gVal, bVal); 
				delay(COLOR_DELAY);
				
				Serial.print(rVal);
				Serial.print(" ");
				Serial.print(gVal);
				Serial.print(" ");
				Serial.print(bVal);
				Serial.println(" ");
				
			} // end b
			
			bBIncreasing = (bBIncreasing ? False : True); 
			
		} // end g

		bGIncreasing = (bGIncreasing ? False : True); 

	} // end r 
	
	bRIncreasing = (bRIncreasing ? False : True); 

	
}