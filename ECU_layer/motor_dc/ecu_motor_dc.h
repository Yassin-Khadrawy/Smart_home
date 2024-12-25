/* 
 * File:   ecu_motor_dc.h
 * Author: KimoStore
 *
 * Created on September 20, 2024, 4:23 PM
 */

#ifndef ECU_MOTOR_DC_H
#define	ECU_MOTOR_DC_H

// includes section
#include "ecu_motor_dc.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
// macros declaration section
#define DC_MOTOR_ON_STATUS   0x01
#define DC_MOTOR_OFF_STATUS  0x00

#define DC_MOTOR_PIN_ZERO   0x00
#define DC_MOTOR_PIN_ONE  0x01

// macros functions declarations

// data type declarations
typedef struct 
{
    unit8 dc_motor_port   : 4;
    unit8 dc_motor_pin    : 3 ;
    unit8 dc_motor_status : 1;
}dc_motor_pin_t;

typedef struct 
{
    dc_motor_pin_t dc_motor[2];
}dc_motor_t;

// function declarations

Std_ReturnType dc_motor_initialized(const dc_motor_t  *dc_motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t  *dc_motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t  *dc_motor);
Std_ReturnType dc_motor_stop(const dc_motor_t  *dc_motor);
#endif	/* ECU_DC_MOTOR_H */

