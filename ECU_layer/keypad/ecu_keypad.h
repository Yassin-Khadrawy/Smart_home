/* 
 * File:   ecu_keypad.h
 * Author: KimoStore
 *
 * Created on September 25, 2024, 1:23 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

#include "ecu_keypad_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"

#define ECU_KEYPAD_ROW       4
#define ECU_KEYPAD_COL       4
// macros functions declarations


// data type declarations
typedef struct
{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROW];
    pin_config_t keypad_col_pins[ECU_KEYPAD_COL];
}keypad_t;

// function declarations
Std_ReturnType keypad_initialize(const keypad_t *keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t *keypad_obj , unit8 *value);
Std_ReturnType enter_password(const keypad_t *keypad_obj);
#endif	/* ECU_KEYPAD_H */

