/*
 * File:   MAIN_MICRO.c
 * Author: Yassin_Khadrawy
 *
 * Created on September 7, 2024, 7:29 PM
 */

/*****************************************************************************/
// section : includes
/*****************************************************************************/

#include "MCAL_layer/mcal_layer_init.h" // Includes the initialization for the Microcontroller Abstraction Layer (MCAL).
#include "ECU_layer/ecu_layer_init.h"   // Includes the initialization for the Electronic Control Unit (ECU) layer.

/*****************************************************************************/
// section : macros declarations
/*****************************************************************************/
#define SLAVE_MCU  0x60

#define there_is_someone_out        1
#define there_is_no_someone_out     0

/*****************************************************************************/
// section : variables
/*****************************************************************************/

/////////////////* detect the read of PIR sensor */////////////////
logic_t PIR_read;

/////////////////* data the master receive from TC74 */////////////////
unit8 TC74_read_value ;
unit8 TC74_ACK_read_value;

/////////////////* Slave ACK bit */////////////////
unit8 ACK_Slave;
unit8 transfer = 0;

/////////////////* data the master receive from DS1307 */////////////////
unit8 DS1307_read_value_0x00;
unit8 DS1307_read_value_0x01;
unit8 DS1307_read_value_0x02;
unit8 DS1307_read_value_0x04;
unit8 DS1307_read_value_0x05;
unit8 DS1307_read_value_0x06;

/////////////////* ACK of the master when it receive from DS1307 */////////////////
unit8 DS1307_ACK_read_value_0x00;
unit8 DS1307_ACK_read_value_0x01;
unit8 DS1307_ACK_read_value_0x02;
unit8 DS1307_ACK_read_value_0x04;
unit8 DS1307_ACK_read_value_0x05;
unit8 DS1307_ACK_read_value_0x06;

/////////////////* PWM LDR sensor and it's led */////////////////
unit16 adc_A0;
unit8 PWM_LDR;

/////////////////* keypad variables outdoor */////////////////
unit8 password__keypad_read = 0;
unit8 password = 0;
unit16 password_match = 0;
unit8 passowrd_counter = 0;
unit8 password_clear_counter = 0;
unit8 password_try = 0;
button_state_t password_logic_b;
unit8 password_locker = 1 ;

/////////////////* keypad variables indoor */////////////////
unit8 password__keypad_read_indoor = 0;
unit8 password_indoor = 0;
unit16 password_match_indoor = 0;
unit8 passowrd_counter_indoor = 0;
unit8 password_clear_counter_indoor = 0;
unit8 password_try_indoor = 0;
button_state_t password_logic_indoor_b;
unit8 password_locker_indoor = 1 ;


/////////////////* delay variables we used at timer0 and timer1 */////////////////
volatile unit8 delay_flag_timer0 = 0;
volatile unit8 delay_flag_timer1 = 0;


/*****************************************************************************/
// section : extern
/*****************************************************************************/
/*
 * Extern variables declared here are defined in other files and used across 
 * the application to manage different hardware components and peripherals.
 */

extern chr_lcd_8bit_t lcd_1;                /*< Character LCD configuration for displaying text */
extern keypad_t password_keypad;            /*< Keypad configuration for password input */
extern led_t led_outdoor;                   /*< LED control for outdoor lighting */
extern dc_motor_t locker;                   /*< DC motor control for locker mechanism */
extern mssp_i2c_t i2c_obj;                  /*< I2C configuration object for communication with I2C devices */
extern pin_config_t speaker;                /*< Pin configuration for the speaker */
extern pin_config_t PIR;                    /*< Pin configuration for PIR motion sensor */
extern led_t PIR_led;                       /*< LED control for PIR sensor status indication */
extern button_t on_keypad;                  /*< Button on keypad for triggering events */
extern ccp_t PWM_LED;                       /*< PWM control for LED brightness */
extern timer2_t timer_pwm;                  /*< Timer2 configuration for PWM signal generation */
extern timer0_t timer0;                     /*< Timer0 configuration for general timing or delays */
extern timer1_t timer1;                     /*< Timer1 configuration for timing functions */
extern adc_conf_t adc;                      /*< ADC configuration for analog-to-digital conversion */
extern button_t on_keypad_indoor;

/*****************************************************************************/
// function declarations
/*****************************************************************************/

// Main application and utility functions

/*
 * it use for initialize the modules and devices 
 * It is the entry point for the system?s behavior and manages the flow of operations.
 */
void application(void);

/*
 * This function reads the input from the user through the keypad and stores it for further processing.
 * It is responsible for capturing user input, typically a password, by detecting key presses.
 */
void password_read(void);

/*
 * This function checks if the password entered by the user matches the predefined password.
 * It compares the stored input with the expected password and returns the result of the comparison.
 */
void detect_the_password(void);
/*
 * This function checks if the password entered by the user matches the predefined password.
 * It compares the stored input with the expected password and returns the result of the comparison.
 */
void detect_the_password_indoor(void);

/*
 * This function handles the outcome when the user inputs a correct or incorrect password.
 * If the password is correct, it proceeds with the authorized action (e.g., opening the locker).
 * If incorrect, it may prompt for re-entry or trigger an error.
 */
void correct_incorrect_password(void);
/*
 * This function handles the outcome when the user inputs a correct or incorrect password.
 * If the password is correct, it proceeds with the authorized action (e.g., closing the locker).
 * If incorrect, it may prompt for re-entry or trigger an error.
 */
void correct_incorrect_password_indoor(void);
/*
 * This function activates the DC motor connected to the locker mechanism, allowing it to unlock or lock.
 * It is used when the user successfully enters the correct password, for example, to unlock the locker.
 */
void locker_on(void);
/*
 * This function activates the DC motor connected to the locker mechanism, allowing it to unlock or lock.
 * It is used when the user successfully enters the correct password, for example, to lock the locker.
 */
void locker_reverse(void);

/*
 * This function handles the initialization and reading of analog-to-digital converter (ADC) values.
 * It is responsible for processing sensor data (e.g., temperature, light intensity) that requires analog input.
 */
void ADC_application(void);

/*
 * This function controls the brightness of an LED by adjusting the pulse width modulation (PWM) signal.
 * It can be used to dim or brighten the LED, or create visual effects such as blinking or fading.
 */
void PWM_LED_OUT(void);

/*
 * This function communicates with the TC74 temperature sensor over the I2C interface to read temperature data.
 * It requests and processes the temperature reading from the TC74 device, which is typically an 8-bit output.
 */
void I2C_TC74_read(void);

/*
 * This function reads the current date and time from the DS1307 Real-Time Clock (RTC) via the I2C interface.
 * It retrieves the date, time, and possibly other information such as alarms or status flags from the DS1307 chip.
 */
void I2C_DS1307_read(void);

/*
 * This function handles the transfer of data over the I2C bus.
 * It can be used to send data to or receive data from I2C devices (e.g., sensors, displays).
 * The function may handle addressing, sending data, and ensuring proper communication protocols.
 */
void I2C_transfer_data(void);

/*
 * This function monitors the status of a Passive Infrared (PIR) sensor to detect motion.
 * If motion is detected, it could trigger an event, such as turning on a light.
 */
void PIR_sensor_s(void);

/*
 * This function generates a delay of 1000 milliseconds (1 second).
 * It is useful for providing debouncing, controlling timing for sensors, or introducing a pause between operations.
 */
void Delay_1000ms(void);

/*
 * This function converts a string representation of a number (e.g., "123") into its corresponding byte value.
 * It is used for parsing input from the user or from a communication interface where data is represented as strings.
 * 
 * Parameters:
 *   - str: Pointer to the string containing the number to be converted.
 *   - value: Pointer to a byte where the converted value will be stored.
 * 
 * Returns:
 *   - Std_ReturnType: The function's return type, indicating success or failure of the conversion.
 */
Std_ReturnType convert_string_to_byte(unit8 *str, unit8 *value);
