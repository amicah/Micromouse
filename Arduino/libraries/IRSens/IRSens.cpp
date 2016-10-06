/*  Description: Controls a QTR-1A Reflectance Sensor
	Author: A Micah McClain
	Email: a.micah.mcclain@gmail.com
	Date: 01/24/16
*/
#include "Arduino.h"
#include "IRSens.h"

// Threshold Value determines how close an object must be
// for the IR Sensor to consider it an obstacle.
#define thresh 950

IRSens::IRSens() { }
IRSens::IRSens(int i) {
	setIn(i);
}
IRSens::~IRSens() { }
void IRSens::update() {
	setOut(analogRead(getIn()));
}
void IRSens::printOut() {
	Serial.print("IR: ");
	Serial.print(getOut());
}
bool IRSens::sensObj() {
	return getOut() < thresh ? true : false;
}
void IRSens::swap(IRSens* obj) {
	int in = getIn();
	setIn(obj->getIn());
	obj->setIn(in);
}
int IRSens::getIn() const { return in; }
int IRSens::getOut() const { return out; }
void IRSens::setIn(int n) { in = n; }
void IRSens::setOut(int n) { out = n; }