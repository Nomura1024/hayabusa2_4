/*
 * adjustment.c
 *
 *  Created on: Mar 16, 2022
 *      Author: Owner
 */
#include <adjustment.h>
#include "stdbool.h"
#include "string.h"
#include "stdio.h"
#include "main.h"
#include <flash.h>
#include <AQM0802.h>
#include <infor.h>
#include "initial.h"

uint16_t Accm;
uint16_t Decm;

void adjust_spped(){
	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("Ave_speed");
	lcd_locate(0,1);
	lcd_printf("%d",Average_speed);
	TIM4 -> CNT=32768;
	while(switch_cheack()){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
		if(TIM4 -> CNT>32768+2000){
			Average_speed += 100;
			lcd_locate(0,1);
			lcd_printf("%d",Average_speed);
			TIM4 -> CNT=32768;
		}
		if(TIM4 -> CNT<32768-2000){
			Average_speed -= 100;
			lcd_locate(0,1);
			lcd_printf("%d",Average_speed);
			TIM4 -> CNT=32768;
		}
	}
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
	work_ram[26]=Average_speed;

}
void adjust_Kp(){
	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("Kp");
	lcd_locate(0,1);
	lcd_printf("%d",Kp);
	TIM4 -> CNT=32768;
	while(switch_cheack()){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
		if(TIM4 -> CNT>32768+2000){
			Kp ++;
			lcd_locate(0,1);
			lcd_printf("%d",Kp);
			TIM4 -> CNT=32768;
		}

		if(TIM4 -> CNT<32768-2000) {
			Kp --;
			lcd_locate(0,1);
			lcd_printf("%d",Kp);
			TIM4 -> CNT=32768;
		}
		}
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
	work_ram[27]=Kp;

}
void adjust_Ki(){
	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("Ki");
	lcd_locate(0,1);
	lcd_printf("%d",Ki);
	TIM4 -> CNT=32768;
	while(switch_cheack()){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
		if(TIM4 -> CNT>32768+2000){
			Ki++;
			lcd_locate(0,1);
			lcd_printf("%d",Ki);
			TIM4 -> CNT=32768;
		}
		if(TIM4 -> CNT<32768-2000) {
			Ki --;
			lcd_locate(0,1);
			lcd_printf("%d",Ki);
			TIM4 -> CNT=32768;
		}
		}
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
	work_ram[28]=Ki;
}
void adjust_Kd(){
	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("Kd");
	lcd_locate(0,1);
	lcd_printf("%d",Kd);
	TIM4 -> CNT=32768;
	while(switch_cheack()){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
		if(TIM4 -> CNT>32768+2000){
			Kd++;
			lcd_locate(0,1);
			lcd_printf("%d",Kd);
			TIM4 -> CNT=32768;
		}
		if(TIM4 -> CNT<32768-2000) {
			Kd --;
			lcd_locate(0,1);
			lcd_printf("%d",Kd);
			TIM4 -> CNT=32768;
		}
		}
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
	work_ram[29]=Kd;

}
void tuning(){
		adjust_spped();
		HAL_Delay(100);
		adjust_Kp();
		HAL_Delay(100);
		adjust_Ki();
		HAL_Delay(100);
		adjust_Kd();
		HAL_Delay(100);

	Flash_store();
	lcd_clear();
}
void adjust_Accm(){

	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("Accm");
	lcd_locate(0,1);
	lcd_printf("%d",Accm);
	TIM4 -> CNT=32768;
	while(switch_cheack()){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
		if(TIM4 -> CNT>32768+2000){
			Accm ++;
			lcd_locate(0,1);
			lcd_printf("%d",Accm);
			TIM4 -> CNT=32768;
		}

		if(TIM4 -> CNT<32768-2000) {
			Accm --;
			lcd_locate(0,1);
			lcd_printf("%d",Accm);
			TIM4 -> CNT=32768;
		}
		//HAL_Delay(100);
		}
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
	work_ram[31]=Accm;

}
void adjust_Decm(){

	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("Decm");
	lcd_locate(0,1);
	lcd_printf("%d",Decm);
	TIM4 -> CNT=32768;
	while(switch_cheack()){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
		if(TIM4 -> CNT>32768+2000){
			Decm ++;
			lcd_locate(0,1);
			lcd_printf("%d",Decm);
			TIM4 -> CNT=32768;
		}

		if(TIM4 -> CNT<32768-2000) {
			Decm --;
			lcd_locate(0,1);
			lcd_printf("%d",Decm);
			TIM4 -> CNT=32768;
		}
		//HAL_Delay(100);
		}
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
	work_ram[32]=Decm;

}
void accel_tuning(){
	adjust_Accm();
	HAL_Delay(100);
	adjust_Decm();
	HAL_Delay(100);

	Flash_store();
	lcd_clear();
}
void adjust_spped_100(){
	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("100");
	lcd_locate(0,1);
	uint speed_100 =work_ram[33];
	lcd_printf("%d",speed_100);
	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_14)==1){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2)==0){
			speed_100 += 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed_100);
		}
		HAL_Delay(100);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_15)==0) {
			speed_100 -= 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed_100);
		}
		HAL_Delay(100);
		}
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	work_ram[33]=speed_100;
}
void adjust_spped_300(){
	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("300");
	lcd_locate(0,1);
	uint speed = work_ram[34];
	lcd_printf("%d",speed);
	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_14)==1){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2)==0){
			speed += 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed);
		}
		HAL_Delay(100);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_15)==0) {
			speed -= 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed);
		}
		HAL_Delay(100);
		}
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	work_ram[34]=speed;
}
void adjust_spped_500(){
	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("500");
	lcd_locate(0,1);
	uint speed = work_ram[35];
	lcd_printf("%d",speed);
	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_14)==1){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2)==0){
			speed += 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed);
		}
		HAL_Delay(100);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_15)==0) {
			speed -= 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed);
		}
		HAL_Delay(100);
		}
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	work_ram[35]=speed;
}
void adjust_spped_800(){
	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("800");
	lcd_locate(0,1);
	uint speed= work_ram[36];
	lcd_printf("%d",speed);
	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_14)==1){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2)==0){
			speed += 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed);
		}
		HAL_Delay(100);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_15)==0) {
			speed -= 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed);
		}
		HAL_Delay(100);
		}
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	work_ram[36]=speed;
}
void adjust_spped_1000(){
	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("1000");
	lcd_locate(0,1);
	uint speed= work_ram[37];
	lcd_printf("%d",speed);
	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_14)==1){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2)==0){
			speed += 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed);
		}
		HAL_Delay(100);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_15)==0) {
			speed -= 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed);
		}
		HAL_Delay(100);
		}
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	work_ram[37]=speed;
}
void adjust_spped_MAX(){
	lcd_init();
	lcd_clear();
	lcd_locate(0,0);
	lcd_printf("MAX");
	lcd_locate(0,1);
	uint speed= work_ram[38];
	lcd_printf("%d",speed);
	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_14)==1){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2)==0){
			speed += 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed);
		}
		HAL_Delay(100);
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_15)==0) {
			speed -= 100;
			lcd_locate(0,1);
			lcd_printf("%d",speed);
		}
		HAL_Delay(100);
		}
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	work_ram[38]=speed;
}
void speed_tuning(){
	adjust_spped_100();
	HAL_Delay(100);
	adjust_spped_300();
	HAL_Delay(100);
	adjust_spped_500();
	HAL_Delay(100);
	adjust_spped_800();
	HAL_Delay(100);
	adjust_spped_1000();
	HAL_Delay(100);
	adjust_spped_MAX();
	HAL_Delay(100);

	Flash_store();
	lcd_clear();
}
