/*  Description: Controls a L293D DC Motor Driver
    Author: A Micah McClain
	Email: a.micah.mcclain@gmail.com
    Date: 01/24/16
*/
#include "Arduino.h"
#ifndef Motor_h
#define Motor_h
class Motor {
 public:
	// Constructors
	Motor();
    Motor(int,int,int); // Input int @param _P, _L1, _L2
	// Destructor
	~Motor();
	// Functions
    void init();	// Initializes Motor I/O
	void printPWM();// Print int @param _PWM
	void printData(); // Print int @params _P, _L1, _L2
	void spin();	// Begins Motor Spin
	void halt();	// Ceases Motor Spin
    void forward(); // Sets Motor Spin to Forward
    void reverse(); // Sets Motor Spin to Reverse
	void swap(Motor*);	// Swap Motor Designation
	// Accessors
    int getP() const;	// Returns int @param _P
    int getL1() const;	// Returns int @param _L1
    int getL2() const;	// Returns int @param _L2
	int getPWM() const;	// Returns int @param _PWM
	// Mutators
    void setP(int);	// Sets int @param _P
    void setL1(int);// Sets int @param _L1
    void setL2(int);// Sets int @param _L2
	void setPWM(int);// Sets int @param _PWM
 private:
    int _P;		// Pin# for Motor Power
    int _L1;	// Pin# for Motor Logic 1
    int _L2;	// Pin# for Motor Logic 2
	int _PWM;	// Pusle Width Modulation
};
#endif
