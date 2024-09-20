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

#include "MicroBit.h"
#include "kitronik_servo_lite.hpp"

MicroBit uBit;

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();

    // Calibrate the servos
    biasDriving(50);
    setDegreesPerSecond(190);

    // Square dance
    for (int i = 0; i < 4; i++)
    {
        driveForwards(100);
        uBit.sleep(1000);
        turnRight(50);
        uBit.sleep(1000);
    }
    
    // If main exits, there may still be other fibers running 
    // or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. 
    // Worse case, we then sit in the idle task forever, 
    // in a power efficient sleep.
    release_fiber();


    // while(1)
    // {
    // }
}

