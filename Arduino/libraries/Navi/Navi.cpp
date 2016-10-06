/*  Description: Controls Other Objects Related to Movement
	Author: A Micah McClain
	Email: a.micah.mcclain@gmail.com
	Date: 02/06/16
*/
#include "Arduino.h"
#include "AGSens.h"
#include "IRSens.h"
#include "Motor.h"
#include "Navi.h"
#define maxPWM 255
bool fwd = true;
Navi::Navi() { }
Navi::~Navi() { }
void Navi::init() {
	if (aGConnected) {
		getAG()->init();
		getAG()->update();
		setPosX(0);
		setPosY(0);
	}
	if (mLConnected || mRConnected) {
		getML()->init();
		getMR()->init();
		getML()->setPWM(maxPWM);
		getMR()->setPWM(maxPWM);
		setLeftC(maxPWM);
		setRightC(maxPWM);
		setFwd();
	}
}
void Navi::debug() {
	if (sFConnected) {
		Serial.print("f");
		getSF()->printOut();
		Serial.print("\t");
	}
	if (sBConnected) {
		Serial.print("b");
		getSB()->printOut();
		Serial.print("\t");
	}
	if (sLConnected) {
		Serial.print("l");
		getSL()->printOut();
		Serial.print("\t");
	}
	if (sRConnected) {
		Serial.print("r");
		getSR()->printOut();
		Serial.print("\t");
	}
	if (mLConnected) {
		Serial.print("l");
		getML()->printData();
		getML()->printPWM();
		Serial.print("\t");
	}
	if (mRConnected) {
		Serial.print("r");
		getMR()->printData();
		getMR()->printPWM();
		Serial.print("\t");
	}
	if (aGConnected) {
		Serial.print("Acc: ");
		getAG()->printAccel();
		Serial.print("\t");
	}
}
void Navi::sense() {
	// Read IR Sensor Data
	if (sFConnected) {
		getSF()->update();
	}
	if (sBConnected) {
		getSB()->update();
	}
	if (sLConnected) {
		getSL()->update();
	}
	if (sRConnected) {
		getSR()->update();
	}
	// Read Accel/Gyro Sensor Data
	if (aGConnected) {
		updatePosition();
	}
}
void Navi::printPosition() {
	if (aGConnected) {
		Serial.print("Pos: ");
		Serial.print(getPosX());
		Serial.print(",");
		Serial.print(getPosY());
		Serial.print("\t");
	}
}
void Navi::updatePosition() {
	int tempX1, tempY1, tempX2, tempY2;
	tempX1 = getAG()->getAX();
	tempY1 = getAG()->getAY();
	getAG()->update();
	tempX2 = getAG()->getAX();
	tempY2 = getAG()->getAY();
	if (tempX2 >= (tempX1 + 5) || tempX2 <= (tempX1 - 5)) {
		setPosX(getPosX() - (tempX1 - tempX2));
	}
	if (tempY2 >= (tempY1 + 5) || tempY2 <= (tempY1 - 5)) {
		setPosY(getPosY() - (tempY1 - tempY2));
	}
}
void Navi::go() {
	drive();
	correction();
	//=======Test with 2 Sensors========
	if (getSF()->sensObj()) {
		turnAround();
	}
	//=======Test with 2 Sensors========
	//// If the sensor is reading correctly
	//if (getSF()->getOut() > 0) {
	//	// If the Front sensor sees an object
	//	if (getSF()->sensObj()) {
	//		// If the Left sensor sees and object
	//		if (getSL()->sensObj()) {
	//			// If the Right Sensor sees and object
	//			if (getSR()->sensObj()) {
	//				turnAround(); // Turn around
	//			}
	//			// If the Right sensor sees nothing
	//			else {
	//				turnRight(); // Turn right
	//			}
	//		}
	//		// If the Left sensor sees nothing
	//		else {
	//			// If the Right sensor sees an object
	//			if (getSR()->sensObj()) {
	//				turnLeft(); // Turn left
	//			}
	//		}
	//	}
	//}
}
void Navi::drive() {
	getML()->spin();
	getMR()->spin();
}
void Navi::cease() {
	getML()->halt();
	getMR()->halt();
}
void Navi::correction() {
	// Avoid Left/Right Wall Collisions
	setLeftC(maxPWM * (getSR()->getOut()) / 1023);
	setRightC(maxPWM * (getSL()->getOut()) / 1023);
	if (getSR()->getOut() < 975) {
		getML()->setPWM(0);
	}
	else {
		getML()->setPWM(maxPWM);
	}
	if (getSL()->getOut() < 975) {
		getMR()->setPWM(0);
	}
	else {
		getMR()->setPWM(maxPWM);
	}
}
void Navi::setFwd() {
	getML()->forward();
	getMR()->forward();
}
void Navi::setRev() {
	getML()->reverse();
	getMR()->reverse();
}
void Navi::setSpin() {
	getML()->forward();
	getMR()->reverse();
}
void Navi::turnLeft() {
	getML()->halt();
	getMR()->spin();
}
void Navi::turnRight() {
	getML()->spin();
	getMR()->halt();
}
void Navi::turnAround() { // Reverse bot
	cease();
	// Swap Front and Back IRSens
	getSF()->swap(getSB());
	// Swap Left and Right IRSens
	getSL()->swap(getSR());
	// Swap Left and Right Motors
	getML()->swap(getMR());
	// Set Motors to Go Backwards
	if (fwd) {
		setRev();
		fwd = false;
	}
	else {
		setFwd();
		fwd = true;
	}
}
AGSens* Navi::getAG() const { return aG; }
IRSens* Navi::getSF() const { return sF; }
IRSens* Navi::getSB() const { return sB; }
IRSens* Navi::getSL() const { return sL; }
IRSens* Navi::getSR() const { return sR; }
Motor* Navi::getML() const { return mL; }
Motor* Navi::getMR() const { return mR; }
int Navi::getLeftC() const { return leftC; }
int Navi::getRightC() const { return rightC; }
int Navi::getPosX() const { return posX; }
int Navi::getPosY() const { return posY; }
void Navi::setAG(AGSens* obj) {
	aG = obj;
	aGConnected = true;
}
void Navi::setSF(IRSens* obj) {
	sF = obj;
	sFConnected = true;
}
void Navi::setSB(IRSens* obj) {
	sB = obj;
	sBConnected = true;
}
void Navi::setSL(IRSens* obj) {
	sL = obj;
	sLConnected = true;
}
void Navi::setSR(IRSens* obj) {
	sR = obj;
	sRConnected = true;
}
void Navi::setML(Motor* obj) {
	mL = obj;
	mLConnected = true;
}
void Navi::setMR(Motor* obj) {
	mR = obj;
	mRConnected = true;
}
void Navi::setLeftC(int n) { leftC = n; }
void Navi::setRightC(int n) { rightC = n; }
void Navi::setPosX(int n) { posX = n; }
void Navi::setPosY(int n) { posY = n; }