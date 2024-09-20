#include "MicroBit.h"
#include "kitronik_servo_lite.h"

const int milliSecInASecond = 1000;
int distancePerSec = 100;
int numberOfDegreesPerSec = 200;
int biasToApply = 50;  // in the middle is the place to start

void biasDriving(int bias) 
{
    if (bias > 120) 
    {
        bias = 120;
    } 
    else if (bias < 0) 
    {
        bias = 0;
    }

    biasToApply = bias;
}

void forward()
{
    int P1Output = 0;
    int P2Output = 180;

    if (biasToApply < 50) 
    {
        // Want to move 180 towards 90
        P2Output -= 50 - biasToApply;
    } 
    else if (biasToApply > 50) 
    {
        // Want to move 0 towards 90
        P1Output += biasToApply - 50;
    }

    uBit.io.P1.setServoValue(P1Output);
    uBit.io.P2.setServoValue(P2Output);
}

void backward() 
{
    int P1Output = 180;
    int P2Output = 0;

    if (biasToApply < 50) 
    {
        // Want to move 0 towards 90
        P2Output += 50 - biasToApply;
    } 
    else if (biasToApply > 50) 
    {
        // Want to move 180 towards 90
        P1Output -= biasToApply - 50;
    }

    uBit.io.P1.setServoValue(P1Output);
    uBit.io.P2.setServoValue(P2Output);
}

void left() {
    uBit.io.P1.setServoValue(0);
    uBit.io.P2.setServoValue(0);
}

void right() {
    uBit.io.P1.setServoValue(180);
    uBit.io.P2.setServoValue(180);
}

void stop() {
    uBit.io.P1.setAnalogValue(0);
    uBit.io.P2.setAnalogValue(0);
}

void neutral() {
    uBit.io.P1.setServoValue(90);
    uBit.io.P2.setServoValue(90);
}

void driveForwards(int howFar) 
{
    // Done this way round to avoid zero rounding
    int timeToWait = (howFar * milliSecInASecond) / distancePerSec;
    forward();
    uBit.sleep(timeToWait);
    stop();
}

void driveBackwards(int howFar) 
{
    // Done this way round to avoid zero rounding
    int timeToWait = (howFar * milliSecInASecond) / distancePerSec;
    backward();
    uBit.sleep(timeToWait);
    stop();
}

void turnRight(int deg) 
{
    // Done this way round to avoid zero rounding
    int timeToWait = (deg * milliSecInASecond) / numberOfDegreesPerSec;
    uBit.io.P1.setServoValue(130);
    uBit.io.P2.setServoValue(130);
    uBit.sleep(timeToWait);
    stop();
}

void turnLeft(int deg) 
{
    // Done this way round to avoid zero rounding
    int timeToWait = (deg * milliSecInASecond) / numberOfDegreesPerSec;
    uBit.io.P1.setServoValue(50);
    uBit.io.P2.setServoValue(50);
    uBit.sleep(timeToWait);
    stop();
}

void setDegreesPerSecond(int degPerSec) 
{
    numberOfDegreesPerSec = degPerSec;
}

void setDistancePerSecond(int distPerSec) 
{
    distancePerSec = distPerSec;
}