/*
 * fsm_automatic.c
 *
 *  Created on: Nov 15, 2023
 *      Author: nvnha
 */

#include "fsm_automatic.h"

/* Define -----*/
//State of fsm
#define INIT 0
#define RED_STATE 1
#define YELLOW_STATE 2
#define GREEN_STATE 3
//Clock counter
#define CLOCK_TIME 1000

/* Init -----*/
int status_auto_traffic1 = INIT;
int status_auto_traffic2 = INIT;

/* Function -----*/
void fsm_auto_traffic1(void) {
  if(isTimerOut(CLOCK_TIMER1)) {
    time_traffic1--;
    setTimer(CLOCK_TIME, CLOCK_TIMER1);
  }
  switch(status_auto_traffic1) {
  case INIT:
    status_auto_traffic1 = RED_STATE;
    time_traffic1 = time_red;
    setTimer(time_red * TIME_UNIT, TRAFFIC1_TIMER);
    setTimer(CLOCK_TIME, CLOCK_TIMER1);
    break;
  case RED_STATE:
	LED_on_road1(RED);
	if(isTimerOut(TRAFFIC1_TIMER) == 1) {
	  status_auto_traffic1 = GREEN_STATE;
	  time_traffic1 = time_green;
	  setTimer(time_green * TIME_UNIT, TRAFFIC1_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER1);
	}
    break;
  case YELLOW_STATE:
	LED_on_road1(YELLOW);
	if(isTimerOut(TRAFFIC1_TIMER) == 1) {
	  status_auto_traffic1 = RED_STATE;
	  time_traffic1 = time_red;
	  setTimer(time_red * TIME_UNIT, TRAFFIC1_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER1);
	}
    break;
  case GREEN_STATE:
	LED_on_road1(GREEN);
	if(isTimerOut(TRAFFIC1_TIMER) == 1) {
	  status_auto_traffic1 = YELLOW_STATE;
	  time_traffic1 = time_yellow;
	  setTimer(time_yellow * TIME_UNIT, TRAFFIC1_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER1);
	}
    break;
  }
}
void fsm_auto_road2(void) {
  if(isTimerOut(CLOCK_TIMER2)) {
    time_traffic--;
    setTimer(CLOCK_TIME, CLOCK_TIMER2);
  }
  switch(status_auto_road2) {
  case INIT:
    status_auto_road2 = GREEN_STATE;
    time_traffic2 = time_green;
    setTimer(time_green * TIME_UNIT, TRAFFIC2_TIMER);
    setTimer(CLOCK_TIME, CLOCK_TIMER2);
    break;
  case RED_STATE:
	LED_on_road2(RED);
	if(isTimerOut(TRAFFIC2_TIMER) == 1) {
	  status_auto_traffic2 = GREEN_STATE;
	  time_traffic2 = time_green;
	  setTimer(time_green * TIME_UNIT, TRAFFIC2_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER2);
	}
    break;
  case YELLOW_STATE:
	LED_on_road2(YELLOW);
	if(isTimerOut(TRAFFIC2_TIMER) == 1) {
	  status_auto_traffic2 = RED_STATE;
	  time_traffic2 = time_red;
	  setTimer(time_red * TIME_UNIT, TRAFFIC2_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER2);
	}
    break;
  case GREEN_STATE:
	LED_on_road2(GREEN);
	if(isTimerOut(TRAFFIC2_TIMER) == 1) {
	  status_auto_traffic2 = YELLOW_STATE;
	  time_traffic2 = time_yellow;
	  setTimer(time_yellow * TIME_UNIT, TRAFFIC2_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER2);
	}
    break;
  }
}
//Set state to INIT
void setInit(void) {
  status_auto_road1 = INIT;
  status_auto_road2 = INIT;
}
