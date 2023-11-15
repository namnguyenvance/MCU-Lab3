/*
 * global.c
 *
 *  Created on: Nov 15, 2023
 *      Author: nvnha
 */
int time_traffic1 = 0;
int time_traffic2 = 0;
int time_red = 5;
int time_yellow = 2;
int time_green = 3;

int checkIndex(int index, int max) {
  if(index >= 0 && index < max) {
	return 1;
  }
  return 0;
}
