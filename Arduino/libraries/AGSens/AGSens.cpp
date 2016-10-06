/*  Description: Controls an MPU-6050 Accel/Gyro
	Author: A Micah McClain
	Email: a.micah.mcclain@gmail.com
	Date: 01/24/16
*/
#include "Arduino.h"
#include "AGSens.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
	#include "Wire.h"
#endif
MPU6050 D_135;
AGSens::AGSens() { }
AGSens::~AGSens() { }
void AGSens::init() {
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
	Wire.begin();
#elif I2CDEV_IMPLEMENTATION == I2DEV_BUILTIN_FASTWIRE
	Fastwire::setup(400, true);
#endif
	D_135.initialize();
}
void AGSens::printAccel() {
	Serial.print("x");
	Serial.print(getAX());
	Serial.print(",y");
	Serial.print(getAY());
}
void AGSens::printT() {
	Serial.print("Temp: ");
	Serial.print(getT());
	Serial.print("\t");
}
void AGSens::printG() {
	Serial.print("Gyro: ");
	Serial.print(getGX());
	Serial.print("\t");
	Serial.print(getGY());
	Serial.print("\t");
	Serial.print(getGZ());
	Serial.print("\t");
}
void AGSens::update() {
	setAX(D_135.getAccelerationX());
	setAY(D_135.getAccelerationY());
	setAZ(D_135.getAccelerationZ());
	setT(D_135.getTemperature());
	setGX(D_135.getRotationX());
	setGY(D_135.getRotationY());
	setGZ(D_135.getRotationZ());
}
int AGSens::getAX() const { return aX; }
int AGSens::getAY() const { return aY; }
int AGSens::getAZ() const { return aZ; }
int AGSens::getT() const { return T; }
int AGSens::getGX() const { return gX; }
int AGSens::getGY() const { return gY; }
int AGSens::getGZ() const { return gZ; }
void AGSens::setAX(int n) { aX = n / 328.00; }
void AGSens::setAY(int n) { aY = n / 328.00; }
void AGSens::setAZ(int n) { aZ = n / 328.00; }
void AGSens::setT(int n) { T = n / 340.00 + 36.53; }
void AGSens::setGX(int n) { gX = n / 328.00; }
void AGSens::setGY(int n) { gY = n / 328.00; }
void AGSens::setGZ(int n) { gZ = n / 328.00; }