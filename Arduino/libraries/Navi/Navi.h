/*  Description: Controls Other Objects Related to Movement
	Author: A Micah McClain
	Email: a.micah.mcclain@gmail.com
	Date: 01/24/16
*/
#include "Arduino.h"
#include "AGSens.h"
#include "IRSens.h"
#include "Motor.h"
#ifndef Navi_h
#define Navi_h
class Navi {
public:
	// Constructors
	Navi();
	// Destructor
	~Navi();
	// Functions
	void init();	// Initializes I/O for Motors
	void debug();	// Print Values for Debug Purposes
	void sense();		// Update sensors
	void printPosition();	// Prints Current x,y Position
	void updatePosition();	// Update Current x,y Position
	void go();		// Normal Operation Functions for Loop
	void drive();	// Begins Spin of Motors
	void cease();	// Ceases Spin of Motors
	void correction();	// Course Correction Avoids Side Collisions
	void setFwd();	// Sets Motors to Spin Forwards
	void setRev();	// Sets Motors to Spin Backwards
	void setSpin();	// Sets Motors to Spin Opposite
	void turnLeft();	// Slows Left Motor for Left Turn
	void turnRight();	// Slows Right Motor for Right Turn
	void turnAround();	// Turn Around to Avoid Front Collision
	// Accessors
	AGSens* getAG() const;	// Returns AGSens* @object aG
	IRSens* getSF() const;	// Returns IRSens* @object sF
	IRSens* getSB() const;	// Returns IRSens* @object sB
	IRSens* getSL() const;	// Returns IRSens* @object sL
	IRSens* getSR() const;	// Returns IRSens* @object sR
	Motor* getML() const;	// Returns Motor* @object mL
	Motor* getMR() const;	// Returns Motor* @object mR
	int getLeftC() const;	// Returns int @param leftC
	int getRightC() const;	// Returns int @param rightC
	int getPosX() const;	// Returns int @param posX
	int getPosY() const;	// Returns int @param posY
	// Mutators
	void setAG(AGSens*);
	void setSF(IRSens*);	// Sets IRSens* @object sF
	void setSB(IRSens*);	// Sets IRSens* @object sB
	void setSL(IRSens*);	// Sets IRSens* @object sL
	void setSR(IRSens*);	// Sets IRSens* @object sR
	void setML(Motor*);		// Sets Motor* @object mL
	void setMR(Motor*);		// Sets Motor* @object mR
	void setLeftC(int);		// Sets int @param leftC
	void setRightC(int);	// Sets int @param rightC
	void setPosX(int);		// Sets int @param posX
	void setPosY(int);		// Sets int @param posY
private:
	AGSens* aG;	// Accelerometer/Gyro Sensor
	bool aGConnected = false;
	IRSens* sF;	// Front IR Sensor
	bool sFConnected = false;
	IRSens* sB;	// Back IR Sensor
	bool sBConnected = false;
	IRSens* sL;	// Left IR Sensor
	bool sLConnected = false;
	IRSens* sR;	// Right IR Sensor
	bool sRConnected = false;
	Motor* mL;	// Left DC Motor
	bool mLConnected = false;
	Motor* mR;	// Right DC Motor
	bool mRConnected = false;
	int leftC;	// Left Course Correction Value
	int rightC;	// Right Course Correction Value
	int posX;	// Current X-Axis Position
	int posY;	// Current Y-Axis Position
};
#endif