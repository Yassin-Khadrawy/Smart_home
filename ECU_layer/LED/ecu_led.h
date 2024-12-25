/* 
 * File:   ecu_led.h
 * Author: KimoStore
 *
 * Created on September 16, 2024, 9:22 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H


// includes section

#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_led_config.h"
#include "../../MCAL_layer/CCP1/hal_ccp1.h"
// macros declarations


// macros functions declarations


// data type declarations
typedef enum
{
    LED_OFF,
    LED_ON,
}led_status;

typedef struct
{
    unit8 port_name : 4;
    unit8 pin : 3;
    unit8 led_status :1;
}led_t;



// function declarations
Std_ReturnType led_initialize(const led_t  *led );
Std_ReturnType led_turn_on_initialize(const led_t  *led );
Std_ReturnType led_turn_off_initialize(const led_t  *led );
Std_ReturnType led_turn_toggle_initialize(const led_t  *led );


#endif	/* ECU_LED_H */

