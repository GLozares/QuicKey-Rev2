/*
 Name:		QuicKey.ino
 Created:	12/2/2021 4:48:37 PM
 Author:	Giemer Lozares
*/

#include <Keyboard.h>
#include "keycode.h"

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	Keyboard.begin();
}

// the loop function runs over and over again until power down or reset
void loop() {
	Keyboard.press(0x61);
	delay(5);
	Keyboard.release(0x61);
	delay(5000);
}
