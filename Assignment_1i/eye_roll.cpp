#include "eye_roll.h"
#include "owl-pwm.h"
#include <math.h>
#include <chrono>


#define ROLL_SPEED 10.0
#define FREQ 1 / ROLL_SPEED

#define PI 3.14159265

using namespace std::chrono;


void eye_roll(int& rx, int& ry, int& lx, int& ly)
{
    // Get current time in ms
    auto millis = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    // Move x and y in circular pattern at given frequency
    rx = static_cast<int>(RxLm  +  ((RxRm - RxLm)) * (sin(2.0 * PI * FREQ * (millis/1000.0)) + 1) / 2.0);
    ry = static_cast<int>(RyBm  +  ((RyTm - RyBm)) * (cos(2.0 * PI * FREQ * (millis/1000.0)) + 1) / 2.0);

    // Move x and y in circular pattern at given frequency
    lx = static_cast<int>(LxLm  +  ((LxRm - LxLm)) * (sin(2.0 * PI * FREQ * (millis/1000.0)) + 1) / 2.0);
    ly = static_cast<int>(LyBm  -  ((LyBm - LyTm)) * (cos(2.0 * PI * FREQ * (millis/1000.0)) + 1) / 2.0);

}
