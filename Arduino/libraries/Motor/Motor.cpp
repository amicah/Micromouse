/*  Description: Controls a L293D DC Motor Driver
	Author: A Micah McClain
	Email: a.micah.mcclain@gmail.com
	Date: 01/24/16
*/
#include "Arduino.h"
#include "Motor.h"
Motor::Motor() { }
Motor::Motor(int P, int L1, int L2) {
	setP(P);
	setL1(L1);
	setL2(L2);
}
Motor::~Motor() { }
void Motor::init() {
	pinMode(getP(), OUTPUT);
	pinMode(getL1(), OUTPUT);
	pinMode(getL2(), OUTPUT);
	digitalWrite(getP(), LOW);
}
void Motor::printPWM() {
	Serial.print("@");
	Serial.print(getPWM());
}
void Motor::printData() {
	Serial.print("Mot: ");
	Serial.print(getP());
	Serial.print(",");
	Serial.print(getL1());
	Serial.print(",");
	Serial.print(getL2());
}
void Motor::spin() {
	analogWrite(getP(), getPWM());
}
void Motor::halt() {
	analogWrite(getP(), 0);
}
void Motor::forward() {
	digitalWrite(getL1(), HIGH);
	digitalWrite(getL2(), LOW);
}
void Motor::reverse() {
	digitalWrite(getL1(), LOW);
	digitalWrite(getL2(), HIGH);
}
void Motor::swap(Motor* obj) {
	int p = getP(), l1 = getL1(), l2 = getL2();
	setP(obj->getP());
	setL1(obj->getL1());
	setL2(obj->getL2());
	obj->setP(p);
	obj->setL1(l1);
	obj->setL2(l2);
}
int Motor::getP() const { return _P; }
int Motor::getL1() const { return _L1; }
int Motor::getL2() const { return _L2; }
int Motor::getPWM() const { return _PWM; }
void Motor::setP(int P) { _P = P; }
void Motor::setL1(int L1) { _L1 = L1; }
void Motor::setL2(int L2) { _L2 = L2; }
void Motor::setPWM(int PWM) { _PWM = PWM; }
