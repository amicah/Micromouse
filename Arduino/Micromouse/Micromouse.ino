/*  Description: Controls Micromouse by determining
      which values are passed into control object Navi.
    Author: A Micah McClain
    Email: a.micah.mcclain@gmail.com
    Date: 01/24/16
    Connection Instructions - Arduino Uno:
    AGSens - Accelerometer/Gyroscope MPU-6050
      VCC - +5V
      GND - Ground
      SCL - Analog Pin 5
      SDA - Analog Pin 4
      INT - Digital Pin 2
    IRSens - Reflectance Sensor(s) QTR-1A
      VIN - +5V
      GND - Ground
      Front Sensor:
        OUT - Analog Pin 0
      Back Sensor:
        OUT - Analog Pin 1
      Left Sensor:
        OUT - Analog Pin 2
      Right Sensor:
        OUT - Analog Pin 3
    Motor - Motor Driver L293D
      01 1,2EN - Digital Pin 6
      02 1A (M1L1) - Digital Pin 7
      03 1Y - Motor 1 Terminal 1
      04 GND - Ground
      05 GND - Ground
      06 2Y - Motor 1 Terminal 2
      07 2A (M1L2) - Digital Pin 8
      08 Vcc2 - Motor Power Supply
      09 3,4EN - Digital Pin 3
      10 3A (M2L1) - Digital Pin 4
      11 3Y - Motor 2 Terminal 1
      12 GND - Ground
      13 GND - Ground
      14 4Y (M2L2) - Motor 2 Terminal 2
      15 4A - Digital Pin 5
      16 Vcc1- IC Power Supply +5V
*/
#include<I2Cdev.h>
#include<MPU6050.h>
#include<Wire.h>
#include <Motor.h>
#include <IRSens.h>
#include <AGSens.h>
#include <Navi.h>

/* Create Navigation object for Micromouse */
Navi mouse;

void setup() {
  /* Enable Serial Printing (Ctrl + Shift + M to view) */
  Serial.begin(9600); // Allows user to view debug
  /* Enable IR Sensor(s) - (OUT) */
  mouse.setSF(new IRSens(0)); // Front
  mouse.setSB(new IRSens(1)); // Back
  mouse.setSL(new IRSens(2)); // Left
  mouse.setSR(new IRSens(3 )); // Right
  /* Enable Motor(s) - (EN, L1, L2) */
  mouse.setML(new Motor(6, 7, 8)); // Left
  mouse.setMR(new Motor(3, 4, 5)); // Right
  /* Enable AG Sensor */
  mouse.setAG(new AGSens());
  mouse.init(); // Initialize
}

void loop() {
  mouse.sense(); // Update sensor inputs
  mouse.go(); // Move the Micromouse
  mouse.debug(); // Print Raw Device Values
  //mouse.printPosition(); // Print X,Y Position Values
  Serial.println(""); // Line Break
}
