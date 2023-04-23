/*
30d Lost in Space Day 6 (supplement)

Video said don't try this w/o explanation, so...

Revision History:
	20230122 - Initial version

*/

#define False 0
#define True  1

double val = 1.0;
bool bDone = False; 

void setup() {

	Serial.begin(9600); 
	
}

void go() {

	for (int x=0; x<308; x++) {
	
		val = 10.0 * val; 
		
		if (x < 100) {
			Serial.print(x); 
			Serial.print(" -> ");
			Serial.println(val);

		}
	
	}
	
	bDone = True;

}

void loop() { 

	if (!bDone) 
		go();
	
	val = 1;
}
