/*  Description: Controls an MPU-6050 Accel/Gyro
	Author: A Micah McClain
	Email: a.micah.mcclain@gmail.com
	Date: 01/24/16
*/
#include"Arduino.h"
#ifndef AGSens_h
#define AGSens_h
class AGSens {
public:
	// Constructor
	AGSens();
	// Destructor
	~AGSens();
	// Functions
	void init();	// Initializes Device
	void printAccel();	// Print int @param aX, aY, aZ
	void printT();	// Print int @param T
	void printG();	// Print int @param gX, gY, gZ
	void update();	// Update int @param aX, aY, aZ, gX, gY, gZ
	// Accessors
	int getAX() const;	// Returns int @param aX
	int getAY() const;	// Returns int @param aY
	int getAZ() const;	// Returns int @param aZ
	int getT() const;	// Returns int @param T
	int getGX() const;	// Returns int @param gX
	int getGY() const;	// Returns int @param gY
	int getGZ() const;	// Returns int @param gZ
	// Mutators
	void setAX(int);	// Sets int @param aX
	void setAY(int);	// Sets int @param aY
	void setAZ(int);	// Sets int @param aZ
	void setT(int);		// Sets int @param T
	void setGX(int);	// Sets int @param gX
	void setGY(int);	// Sets int @param gY
	void setGZ(int);	// Sets int @param gZ
private:
	int aX;	// Accelerometer - X Axis Reading
	int aY;	// Accelerometer - Y Axis Reading
	int aZ;	// Accelerometer - Z Axis Reading
	int T;	// Temperature Reading
	int gX;	// Gyroscope - X Axis Reading
	int gY;	// Gyroscope - Y Axis Reading
	int gZ;	// Gyroscope - Z Axis Reading
};
#endif