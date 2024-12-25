/* 
 * File:   mcal_layer_init.h
 * Author: KimoStore
 *
 * Created on November 28, 2024, 11:07 AM
 */

#ifndef MCAL_LAYER_INIT_H
#define	MCAL_LAYER_INIT_H

// section : includes

#include "ADC/hal-adc.h"
#include "hal_EEPROM/eeprom.h"
#include "Timer1/hal_timer1.h"
#include "Timer2/hal_timer2.h"
#include "Timer3/hal_timer3.h"
#include "Timer0/Mcal_timer0.h"
#include "USART/mcal_usart.h"
#include "GPIO/hal_gpio.h"
#include "mcal_std_types.h"
#include "I2C/hal_i2c.h"
#include "CCP1/hal_ccp1.h"
// macros declarations


// macros functions declarations


// data type declarations


// function declarations
void Timer0_DefaultInterruptHandler_1000ms(void);
void Timer1_DefaultInterruptHandler_100ms(void);
void ADC_application(void);
#endif	/* MCAL_LAYER_INIT_H */

