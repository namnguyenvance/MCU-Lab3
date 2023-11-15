/*
 * button.h
 *
 *  Created on: Nov 15, 2023
 *      Author: nvnha
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button_flag[3];
extern int TimeOutForKeyPress[3];
void getKeyInput();
int isButtonPressed(int index);

#endif /* INC_BUTTON_H_ */
