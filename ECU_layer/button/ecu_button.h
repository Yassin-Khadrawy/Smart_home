/* 
 * File:   ecu_button.h
 * Author: KimoStore
 *
 * Created on September 18, 2024, 7:11 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

// includes section
#include "ecu_button_config.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
// macros declaration section
// macros function declaration section
// data type declaration section
typedef enum
{
    ACTIVE_HIGH,
    ACTIVE_LOW,
}button_active_t;
typedef enum
{
    BUTTON_PRESSED,
    BUTTON_RELEASED,
}button_state_t;

typedef struct
{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connect;
}button_t;

// function declarations

Std_ReturnType button_intialized(button_t *BUTTON);
Std_ReturnType button_read_intialized(button_t *BUTTON , button_state_t *button_read);


#endif	/* ECU_BUTTON_H */

