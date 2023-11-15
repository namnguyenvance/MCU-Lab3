/*
 * fsm_manual.c
 *
 *  Created on: Nov 15, 2023
 *      Author: nvnha
 */

#include "fsm_manual.h"

/* Define -----*/
//State of fsm
#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4
//Time for fsm
#define RETURN_MODE1 10000

/* Init -----*/
int status_manual = MODE1;

/* Function ----*/
//Auto return to MODE1
void returnMODE1(void) {
  status_manual = MODE1;
  setInit();
}
//Increasing time
void inc_time(void) {
  time_traffic2++;
  if(time_traffic2 > 99) {
    time_traffic2 = 0;
  }
}
//state machine
void fsm_manual(void) {
  switch(status_manual) {
  case MODE1:
    fsm_auto_traffic1();
    fsm_auto_traffic2();
    if(isButtonPressed(MODE_BUTTON) == 1) {
      status_manual = MODE2;
      time_traffic1 = MODE2;
      time_traffic2 = time_red;
      setTimer(RETURN_MODE1, MODE1_TIMER);
    }
    break;
  case MODE2:
	if(isButtonPressed(MODE_BUTTON) == 1) {
	  status_manual = MODE3;
	  time_traffic1 = MODE3;
	  time_traffic2 = time_yellow;
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isButtonPressed(MODIFY_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isButtonPressed(SET_BUTTON) == 1) {
	  time_red = time_traffic2;
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isTimerOut(MODE1_TIMER) == 1) {
	  restartDisplay();
	  returnMODE1();
	}
	break;
  case MODE3:
	if(isButtonPressed(MODE_BUTTON) == 1) {
	  status_manual = MODE4;
	  time_traffic1 = MODE4;
	  time_traffic2 = time_green;
      restartDisplay();
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isButtonPressed(MODIFY_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isButtonPressed(SET_BUTTON) == 1) {
	  time_yellow = time_traffic2;
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isTimerOut(MODE1_TIMER) == 1) {
	  returnMODE1();
	}
	break;
  case MODE4:
	if(isButtonPressed(MODE_BUTTON) == 1) {
	  status_manual = MODE1;
	  setInit();
	}
	if(isButtonPressed(MODIFY_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isButtonPressed(SET_BUTTON) == 1) {
	  time_green = time_traffic2;
	  setTimer(RETURN_MODE1, MODE1_TIMER);
	}
	if(isTimerOut(MODE1_TIMER) == 1) {
	  returnMODE1();
	}
	break;
  }
}
