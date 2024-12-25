/* 
 * File:   ecu_layer_init.h
 * Author: KimoStore
 *
 * Created on September 28, 2024, 11:34 AM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

// section : includes

#include "LED/ecu_led.h"
#include "button/ecu_button.h"
#include "relay/ecu_relay.h"
#include "motor_dc/ecu_motor_dc.h"
#include "seven_segment/ecu_seven_segment.h"
#include "keypad/ecu_keypad.h"
#include "LCD_NEW/ecu_lcd_new.h"
#include "DS1307/ecu_DS1307.h"
#include "TC74/ecu_TC74.h"
#include "24C01C/ecu_24C01C.h"
#include "LDR/ecu_ldr.h"
// macros declarations


// macros functions declarations


// data type declarations


// function declarations

void ecu_layer_initialize(void);

#endif	/* ECU_LAYER_INIT_H */

