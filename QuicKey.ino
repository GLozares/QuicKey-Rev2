/*
 Name:		QuicKey.ino
 Created:	12/2/2021 4:48:37 PM
 Author:	Giemer Lozares
*/

#include <Keyboard.h>
#include "TimerOne.h"
// the setup function runs once when you press reset or power the boarda
void setup() {
	Serial.begin(9600);

	//Timer Initialization
	Timer1.initialize(1000000);
	Timer1.attachInterrupt(printSerial);
}

void printSerial() {
	Serial.println("Hello world!");
}

// the loop function runs over and over again until power down or reset
void loop() {
	int x = 1;
	while (x == 1) {

	}
}
