/*
MIT License

Copyright (c) 2024 kitnhl
This software is provided by Kit (Hong Long Nguyen).

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/**
 * Blocks for driving the Kitronik Servo:Lite Board
 */
#ifndef KITRONIK_SERVO_LITE_H
#define KITRONIK_SERVO_LITE_H

#include "MicroBit.h"

extern MicroBit uBit;

extern const int milliSecInASecond;
extern int distancePerSec;
extern int numberOfDegreesPerSec;
extern int biasToApply;

/**
 * Apply a bias to the wheels. 0 to 60 for left, 60 to 120 for right.
 * @param bias: The bias value to apply, between 0 and 120.
 */
void biasDriving(int bias);

/**
 * Drives forwards. Call `stop` to stop.
 */
void forward();

/**
 * Drives backwards. Call `stop` to stop.
 */
void backward();

/**
 * Turns left. Call `stop` to stop.
 */
void left();

/**
 * Turns right. Call `stop` to stop.
 */
void right();

/**
 * Stop for 360 servos.
 * Rather than write 90, which may not stop the servo moving if it's out of trim
 * this stops sending servo pulses, which has the same effect.
 * On a normal servo this will stop the servo where it is, rather than return it
 * to neutral position.
 * It will also not provide any holding force.
 */
void stop();

/**
 * Sends servos to 'neutral' position.
 * On a well-trimmed 360 servo, this is stationary; on a normal servo, 
 * this is 90 degrees.
 */
void neutral();

/**
 * Drives forwards the requested distance and then stops.
 * @param howFar: The distance to move in millimeters.
 */
void driveForwards(int howFar);

/**
 * Drives backwards the requested distance and then stops.
 * @param howFar The distance to move in millimeters.
 */
void driveBackwards(int howFar);

/**
 * Turns right through the requested degrees and then stops.
 * Needs NumberOfDegreesPerSec tuned to make accurate, as it uses
 * a simple turn, wait, stop method.
 * Runs the servos at slower than the right function to reduce wheel slip.
 * @param deg: How far to turn, eg: 90.
 */
void turnRight(int deg);

/**
 * Turns left through the requested degrees and then stops.
 * Needs NumberOfDegreesPerSec tuned to make accurate, as it uses
 * a simple turn, wait, stop method.
 * Runs the servos at slower than the right function to reduce wheel slip.
 * @param deg: How far to turn, eg: 90.
*/
void turnLeft(int deg);

/**
 * Sets the turn speed in degrees per second.
 * @param degPerSec: The number of degrees per second.
 */
void setDegreesPerSecond(int degPerSec);

/**
 * Sets the movement speed in millimeters per second.
 * @param distPerSec: The number of millimeters per second.
 */
void setDistancePerSecond(int distPerSec);

#endif // KITRONIK_SERVO_LITE_H