/*
 Name:		QuicKey.ino
 Created:	12/2/2021 4:48:37 PM
 Author:	Giemer Lozares
*/

#include <Keyboard.h>
#include "TimerOne.h"
#include "keyMatrix.h"

int port_rows[6] = { 18, 19, 20, 21, 22, 23 };
int port_cols[14] = { 17, 15, 16, 14, 3, 2, 0, 1, 30, 8, 9, 10, 5, 13 };




// the setup function runs once when you press reset or power the boarda
void setup() {
	Serial.begin(9600);
	Keyboard.begin();

	//initializing rows as output
	pinMode(18, OUTPUT); //row 0 PF7
	pinMode(19, OUTPUT); //row 4 PF6
	pinMode(20, OUTPUT); //row 3 PF5
	pinMode(21, OUTPUT); //row 2 PF4
	pinMode(22, OUTPUT); //row 1 PF1
	pinMode(23, OUTPUT); //row 1 PF0

	//initializing columns as input and enabling pull-up resistors
	pinMode(0, INPUT_PULLUP);  //column 7 PD1
	pinMode(1, INPUT_PULLUP);  //column 6 PD2
	pinMode(2, INPUT_PULLUP);  //column 5 PD1
	pinMode(3, INPUT_PULLUP);  //column 4 PD0
	pinMode(5, INPUT_PULLUP);  //column 12 PC6
	pinMode(8, INPUT_PULLUP);  //column 9 PB4
	pinMode(9, INPUT_PULLUP);  //column 10 PB5
	pinMode(10, INPUT_PULLUP); //column 11 PB6
	pinMode(13, INPUT_PULLUP); //column 13 PC7
	pinMode(14, INPUT_PULLUP); //column 3 PB3
	pinMode(15, INPUT_PULLUP); //column 1 PB1
	pinMode(16, INPUT_PULLUP); //column 2 PB2
	pinMode(17, INPUT_PULLUP); //column 0 PB0
	//pinMode(30, INPUT); //column 8 PD5
	DDRD &= ~(1 << DDD5);
	PIND |= (1 << PIND5);

	//Timer Initialization
	Timer1.initialize(20000);
	Timer1.attachInterrupt(keyboard_scan);
}

uint8_t returnedKey;
uint8_t releasedKey;

void keyboard_scan() {
	//setting all the rows to 1
	digitalWrite(18, HIGH);
	digitalWrite(19, HIGH);
	digitalWrite(20, HIGH);
	digitalWrite(21, HIGH);
	digitalWrite(22, HIGH);
	digitalWrite(23, HIGH);
	digitalWrite(30, HIGH); //enable pull-up resistor in column 8
	int i = 0;
	int j = 0;
	for (i = 0; i < 6; i++) {
		//setting a row to 0
		digitalWrite(port_rows[i], LOW);
		delay(5);

		//scan through the columns to see which button is pressed.
		for (j = 0; j < 14; j++) {

			if ((digitalRead(port_cols[j]) == 0)) {
				Keyboard.press(keyboard[i][j]);
			} 

			else if (digitalRead(port_cols[j] == 1)) {
				
				Keyboard.release(keyboard[i][j]);
				
			}

		}
		digitalWrite(port_rows[i], HIGH); //set the row back to 1 and move on to the next row
		digitalWrite(30, LOW); //disable pull-up resistor on column 8 to prevent ghosting

	}
	//return 0x00; //If nothing is found, return 0xFFF
}

void printSerial() {
	Serial.println("Hello world!");
}

// the loop function runs over and over again until power down or reset
void loop() {


}
