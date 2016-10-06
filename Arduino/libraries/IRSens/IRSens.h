/*  Description: Controls a QTR-1A Reflectance Sensor
	Author: A Micah McClain
	Email: a.micah.mcclain@gmail.com
	Date: 01/24/16
*/
#include "Arduino.h"
#ifndef IRSens_h
#define IRSens_h
class IRSens {
public:
	// Constructors
	IRSens();
	IRSens(int); // Input int @param in, thresh
	// Destructor
	~IRSens();
	// Functions
	void update();	// Updates IRSens Input
	void printOut();// Prints int @param out
	bool sensObj(); // Returns True if Object below Threshold
	void swap(IRSens*);	// Swap IRSens Designation
	// Accessors
	int getIn() const;		// Returns int @param in
	int getOut() const;		// Returns int @param out
	// Mutators
	void setIn(int);	// Sets int @param in
	void setOut(int);	// Sets int @param out
private:
	int in;		// Pin# for IRSens Input
	int out;	// IRSens Output Value
};
#endif