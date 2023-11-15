/*
 * fsm_automatic.h
 *
 *  Created on: Nov 15, 2023
 *      Author: nvnha
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"
#include "software_timer.h"

/* Function -----*/
void fsm_auto_traffic1(void);
void fsm_auto_traffic2(void);
//Set state to INIT
void setInit(void);

#endif /* INC_FSM_AUTOMATIC_H_ */
