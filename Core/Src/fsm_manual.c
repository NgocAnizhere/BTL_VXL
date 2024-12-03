/*
 * fsm_manual.c
 *
 *  Created on: Oct 27, 2024
 *      Author: admin
 */

#include "fsm_manual.h"

const int MAX_LED = 2;
int index_led = 0;
int index_led_t =0;
int mode = 2;
void fsm_manual_run(){
	switch(status){
	case MAN_RED:
		//TODO
		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(led1_bit1_GPIO_Port,led1_bit1_Pin);
			HAL_GPIO_TogglePin(led1_bit2_GPIO_Port,led1_bit2_Pin);

			HAL_GPIO_TogglePin(led2_bit1_GPIO_Port,led2_bit1_Pin);
			HAL_GPIO_TogglePin(led2_bit2_GPIO_Port,led2_bit2_Pin);

			// 7-segment
//			updateLedBuffer(mode);
//			updateLedBuffer_t(tmpTimeRed/100);
//			if(index_led >= MAX_LED){index_led = 0;}
//			if(index_led_t >= MAX_LED){index_led_t = 0;}
//
//			update7SEG_t(index_led_t ++);
//			update7SEG(index_led ++);

			setTimer1(50);
		}

//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);

		if(isButton1Pressed() == 1){
			mode = 3;
			HAL_GPIO_WritePin(led1_bit1_GPIO_Port, led1_bit1_Pin, 0);
			HAL_GPIO_WritePin(led1_bit2_GPIO_Port, led1_bit2_Pin, 0);

			HAL_GPIO_WritePin(led2_bit1_GPIO_Port, led2_bit1_Pin, 0);
			HAL_GPIO_WritePin(led2_bit2_GPIO_Port, led2_bit2_Pin, 0);
			status = MAN_YELLOW;
			setTimer1(50);
		}

		tmpTimeRed = fsm_setting_run(tmpTimeRed);

		if(isButton3Pressed() == 1){
			redTime = tmpTimeRed;
		}

		break;
	case MAN_YELLOW:
		//TODO
		HAL_GPIO_WritePin(led1_bit1_GPIO_Port, led1_bit1_Pin, 0);
		HAL_GPIO_WritePin(led2_bit1_GPIO_Port, led2_bit1_Pin, 0);
		if (timer1_flag == 1){

			HAL_GPIO_TogglePin(led1_bit2_GPIO_Port,led1_bit2_Pin);
			HAL_GPIO_TogglePin(led2_bit2_GPIO_Port,led2_bit2_Pin);

			// 7-segment
//			updateLedBuffer(mode);
//			updateLedBuffer_t(tmpTimeYellow/100);
//			if(index_led >= MAX_LED){index_led = 0;}
//			if(index_led_t >= MAX_LED){index_led_t = 0;}
//			update7SEG_t(index_led_t ++);
//			update7SEG(index_led ++);


			setTimer1(50);
		}

//		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);



		if(isButton1Pressed() == 1){
			mode = 4;
			HAL_GPIO_WritePin(led1_bit1_GPIO_Port, led1_bit1_Pin, 0);
			HAL_GPIO_WritePin(led1_bit2_GPIO_Port, led1_bit2_Pin, 0);

			HAL_GPIO_WritePin(led2_bit1_GPIO_Port, led2_bit1_Pin, 0);
			HAL_GPIO_WritePin(led2_bit2_GPIO_Port, led2_bit2_Pin, 0);
			status = MAN_GREEN;
			setTimer1(50);
		}

		tmpTimeYellow = fsm_setting_run(tmpTimeYellow);

		if(isButton3Pressed() == 1){
			yellowTime = tmpTimeYellow;
		}

		break;

	case MAN_GREEN:
		//TODO
		HAL_GPIO_WritePin(led1_bit2_GPIO_Port, led1_bit2_Pin, 0);
		HAL_GPIO_WritePin(led2_bit2_GPIO_Port, led2_bit2_Pin, 0);
		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(led1_bit1_GPIO_Port,led1_bit1_Pin);
			HAL_GPIO_TogglePin(led2_bit1_GPIO_Port,led2_bit1_Pin);
			// 7-segment
//			updateLedBuffer(mode);
//			updateLedBuffer_t(tmpTimeGreen/100);
//			if(index_led >= MAX_LED){index_led = 0;}
//			if(index_led_t >= MAX_LED){index_led_t = 0;}
//			update7SEG_t(index_led_t ++);
//			update7SEG(index_led ++);


			setTimer1(50);
		}

//		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);

		if(isButton1Pressed() == 1){

			status = INIT;
			setTimer1(50);
		}

		tmpTimeGreen = fsm_setting_run(tmpTimeGreen);

       if(isButton3Pressed() == 1){
    	   greenTime = tmpTimeGreen;
       }

		break;
	default:
		break;
	}
}
