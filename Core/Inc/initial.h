/*
 * initial.h
 *
 *  Created on: 2021/11/02
 *      Author: Owner
 */

#ifndef INC_INITIAL_H_
#define INC_INITIAL_H_

#include "main.h"

void init();
void LED(uint8_t x);
void LED2(uint8_t x);
void error();
void stop();
void Motor(int16_t MotorL,int16_t MotorR);
void init();
void stop();
void sidemaker();
void fan_pressure(float L,float R);
void driv_fan(float speed_now);
void flashcheck();
uint8_t switch_cheack();
uint8_t switch_cheack2();
int8_t mode_change();
int mode_Selection(uint8_t cheak);
#endif /* INC_INITIAL_H_ */
