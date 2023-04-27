/*
30d Lost in Space Day 6 (supplement)

Video said don't try this w/o explanation, so...

Revision History:
	20230422 - Initial version
	20230426 - Revised to use POW function to demo max double

*/
#include <math.h>

#define False 0
#define True  1

double val = 1.0;
bool bDone = False; 

void setup() {

	Serial.begin(9600); 
	
}

void go() {

	for (int x=0; x<38; x++) {	
		val = pow(2,x); 
		Serial.print(x); 
		Serial.print(" -> ");
		Serial.println(val);
	
	}
	
	bDone = True;

}

void loop() { 

	if (!bDone) 
		go();
	
	val = 1;
}
