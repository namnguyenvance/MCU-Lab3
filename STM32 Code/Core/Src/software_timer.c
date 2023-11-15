/*
 * software_timer.c
 *
 *  Created on: Nov 15, 2023
 *      Author: nvnha
 */
#include "software_timer.h"

int counter[NO_Timer] = {0};
int flag[NO_Timer] = {0};

/* Function -----*/
//Set time on timer[index] = duration
void setTimer(int duration, int index) {
  if(index >= 0 && index < NO_Timer) {
	  counter[index] = duration / TIMER_CYCLE;
	  flag[index] = 0;
  }
}

//Check timer out on timer[index]
int isTimerOut(int index) {
	if(index >= 0 && index < NO_Timer) {
		if(flag[index] == 1) {
			flag[index] = 0;
			return 1;
		}
	}
	return 0;
}

//Run timer (counter on timer)
void timerRun(void) {
  for(int i = 0; i < NO_Timer; i++) {
	if(counter[i] > 0) {
	  counter[i]--;
	  if(counter[i] <= 0) {
		counter[i] = 0;
		flag[i] = 1;
	  }
	}
  }
}
