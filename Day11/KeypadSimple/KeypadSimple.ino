#include <Key.h>
#include <Keypad.h>

const byte MAX_ROWS = 4;
const byte MAX_COLS = 4;

/* Lesson Keypad layout 
char keypadButtons[MAX_ROWS][MAX_COLS] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'} 
};
*/

// Keypad from Sensor Kit, plugged in pins 9-->2 left-->right top view
char keypadButtons[MAX_ROWS][MAX_COLS] = {
	{'*', '7', '4', '1'},
	{'0', '8', '5', '2'},
	{'#', '9', '6', '3'},
	{'D', 'C', 'B', 'A'} 
};

 
byte rowPins[MAX_ROWS] = {5, 4, 3, 2};
byte colPins[MAX_COLS] = {6, 7, 8, 9};
 
Keypad pad = Keypad(makeKeymap(keypadButtons), rowPins, colPins, MAX_ROWS, MAX_COLS);
 
 
void setup() {
	Serial.begin(9600); 

}
 
void loop() {
	char result = pad.getKey();

	if (result){
		Serial.println(result);
	}

}