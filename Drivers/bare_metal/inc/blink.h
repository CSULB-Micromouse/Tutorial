#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

/*
@brief initializes led
@param none
@return none
*/
void Enable_LED(void);

/*
@brief makes led go high 
@param none
@return none
*/
void LED_HIGH(void);

/*
@brief makes led go low 
@param none
@return none
*/
void LED_LOW(void);

#ifdef __cplusplus
}
#endif