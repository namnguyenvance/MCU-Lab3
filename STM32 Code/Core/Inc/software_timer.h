/*
 * software_timer.h
 *
 *  Created on: Nov 15, 2023
 *      Author: nvnha
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

//Timer index
#define EN_TIMER 0
#define TRAFFIC1_TIMER 1
#define TRAFFIC2_TIMER 2
#define CLOCK_TIMER1 3
#define CLOCK_TIMER2 4
#define MODE1_TIMER 5
#define BLINK_TIMER 6

//Set time on timer[index] = duration
void setTimer(int duration, int index);
//Check timer out on timer[index]
int isTimerOut(int index);
//Run timer (counter on timer)
void timerRun(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
