#include "ecu_layer_init.h"
chr_lcd_8bit_t lcd_1 = {
    .lcd_rs.port = PORTE_INDEX,
    .lcd_rs.pin = pin0,
    .lcd_rs.dirction = OUTPUT,
    .lcd_rs.logic = LOW,
    
    .lcd_enable.port = PORTE_INDEX,
    .lcd_enable.pin = pin1,
    .lcd_enable.dirction = OUTPUT,
    .lcd_enable.logic = LOW,
    
    .lcd_data[0].port = PORTB_INDEX,
    .lcd_data[0].pin = pin0,
    .lcd_data[0].dirction = OUTPUT,
    .lcd_data[0].logic = LOW,
    
    .lcd_data[1].port = PORTB_INDEX,
    .lcd_data[1].pin = pin1,
    .lcd_data[1].dirction = OUTPUT,
    .lcd_data[1].logic = LOW,
    
    .lcd_data[2].port = PORTB_INDEX,
    .lcd_data[2].pin = pin2,
    .lcd_data[2].dirction = OUTPUT,
    .lcd_data[2].logic = LOW,
    
    .lcd_data[3].port = PORTB_INDEX,
    .lcd_data[3].pin = pin3,
    .lcd_data[3].dirction = OUTPUT,
    .lcd_data[3].logic = LOW,
    
    .lcd_data[4].port = PORTB_INDEX,
    .lcd_data[4].pin = pin4,
    .lcd_data[4].dirction = OUTPUT,
    .lcd_data[4].logic = LOW,
    
    .lcd_data[5].port = PORTB_INDEX,
    .lcd_data[5].pin = pin5,
    .lcd_data[5].dirction = OUTPUT,
    .lcd_data[5].logic = LOW,
    
    .lcd_data[6].port = PORTB_INDEX,
    .lcd_data[6].pin = pin6,
    .lcd_data[6].dirction = OUTPUT,
    .lcd_data[6].logic = LOW,
    
    .lcd_data[7].port = PORTB_INDEX,
    .lcd_data[7].pin = pin7,
    .lcd_data[7].dirction = OUTPUT,
    .lcd_data[7].logic = LOW
};
keypad_t password_keypad =
{
    .keypad_col_pins[0].dirction = INPUT, 
    .keypad_col_pins[0].logic = LOW,
    .keypad_col_pins[0].pin = pin4,
    .keypad_col_pins[0].port = PORTD_INDEX,
    
    .keypad_col_pins[1].dirction = INPUT, 
    .keypad_col_pins[1].logic = LOW,
    .keypad_col_pins[1].pin = pin5,
    .keypad_col_pins[1].port = PORTD_INDEX,
    
    .keypad_col_pins[2].dirction = INPUT, 
    .keypad_col_pins[2].logic = LOW,
    .keypad_col_pins[2].pin = pin6,
    .keypad_col_pins[2].port = PORTD_INDEX,
    
    .keypad_col_pins[3].dirction = INPUT, 
    .keypad_col_pins[3].logic = LOW,
    .keypad_col_pins[3].pin = pin7,
    .keypad_col_pins[3].port = PORTD_INDEX,
    
    
    .keypad_row_pins[0].dirction = OUTPUT, 
    .keypad_row_pins[0].logic = LOW,
    .keypad_row_pins[0].pin = pin0,
    .keypad_row_pins[0].port = PORTD_INDEX,
    
    .keypad_row_pins[1].dirction = OUTPUT, 
    .keypad_row_pins[1].logic = LOW,
    .keypad_row_pins[1].pin = pin1,
    .keypad_row_pins[1].port = PORTD_INDEX,
    
    .keypad_row_pins[2].dirction = OUTPUT, 
    .keypad_row_pins[2].logic = LOW,
    .keypad_row_pins[2].pin = pin2,
    .keypad_row_pins[2].port = PORTD_INDEX,
    
    .keypad_row_pins[3].dirction = OUTPUT, 
    .keypad_row_pins[3].logic = LOW,
    .keypad_row_pins[3].pin = pin3,
    .keypad_row_pins[3].port = PORTD_INDEX,
};

led_t led_outdoor =
{
    .led_status = LED_OFF,
    .pin = pin2,
    .port_name = PORTC_INDEX,
};
dc_motor_t locker =
{
    .dc_motor[0].dc_motor_pin = pin1,
    .dc_motor[0].dc_motor_port = PORTA_INDEX,
    .dc_motor[0].dc_motor_status = DC_MOTOR_OFF_STATUS,
    .dc_motor[1].dc_motor_pin = pin5,
    .dc_motor[1].dc_motor_port = PORTC_INDEX,
    .dc_motor[1].dc_motor_status = DC_MOTOR_OFF_STATUS,
};
button_t on_keypad =
{
    .button_pin.dirction=INPUT,
    .button_pin.logic = LOW,
    .button_pin.pin = pin2,
    .button_pin.port = PORTE_INDEX,
    .button_state =  BUTTON_RELEASED,
    .button_connect = ACTIVE_HIGH,
};

button_t on_keypad_indoor =
{
    .button_pin.dirction=INPUT,
    .button_pin.logic = LOW,
    .button_pin.pin = pin3,
    .button_pin.port = PORTA_INDEX,
    .button_state =  BUTTON_RELEASED,
    .button_connect = ACTIVE_HIGH,
};
led_t PIR_led =
{
    .led_status = LOW,
    .pin = pin2,
    .port_name = PORTA_INDEX,
};