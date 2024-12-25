/*
 * File:   MAIN_MICRO.c
 * Author: Yassin_Khadrawy
 *
 * Created on September 7, 2024, 7:29 PM
 * 
 * Description: 
 * This file contains the main application logic and utility functions for 
 * interacting with various components such as sensors, motors, relays, 
 * seven-segment displays, and more. The file leverages the Microcontroller 
 * Abstraction Layer (MCAL) and Electronic Control Unit (ECU) layers to 
 * perform its operations.
 */

/*****************************************************************************/
// Section: Includes
/*****************************************************************************/

#include "MCAL_layer/mcal_layer_init.h" // Includes the initialization for the Microcontroller Abstraction Layer (MCAL).
#include "ECU_layer/ecu_layer_init.h"   // Includes the initialization for the Electronic Control Unit (ECU) layer.

/*****************************************************************************/
// Section: Macros Declarations
/*****************************************************************************/
#define there_is_gas       1
#define there_is_no_gas    0

/*****************************************************************************/
// Section: Variables
/*****************************************************************************/

/////////////////* read of gas sensor*/////////////////
logic_t gas_sensor_read;

/////////////////* ADC pressure sensor read*/////////////////
unit16 adc_result;
unit8  Vout;
float  pressure;
unit16 adc_res_2_txt[11];

/////////////////* button of the led */////////////////
button_state_t led_button_read = BUTTON_RELEASED;

/////////////////* temperature value transfer by I2C */////////////////
unit8 I2C_temperature_value;
unit16 temperature_value[11];

/////////////////* Slave start it's function by I2C */////////////////
unit8 I2C_SLAVE_ON;

/////////////////* seconds of DS1307 transfer by I2C */////////////////
unit8 I2C_Seconds_value;
unit16 Seconds_value[11];
unit8 seconds_correct = 0 ;
unit8 correct_total_seconds;

/////////////////* minutes of DS1307 transfer by I2C */////////////////
unit8 I2C_Minutes_value;
unit16 Minutes_value[11];
unit8 minutes_correct = 0 ;
unit8 correct_total_minutes;

/////////////////* hours of DS1307 transfer by I2C */////////////////
unit8 I2C_Hours_value;
unit16 Hours_value[11];
unit8 hours_correct = 0 ;
unit8 correct_total_hours;

/////////////////* days of DS1307 transfer by I2C */////////////////
unit8  I2C_Days_value;
unit16 Days_value[11];
unit8  Days_correct = 0 ;
unit8 correct_total_Days;

/////////////////* months of DS1307 transfer by I2C */////////////////
unit8  I2C_Months_value;
unit16 Months_value[11];
unit8  Months_correct = 0 ;
unit8 correct_total_Months;

/////////////////* years of DS1307 transfer by I2C */////////////////
unit8  I2C_Years_value;
unit16 Years_value[11];
unit8  Years_correct = 0 ;
unit8 correct_total_Years;

/////////////////* I2C interrupt counter */////////////////
unit8 counter = 0;
unit8 counter_i2c = 0;

/*****************************************************************************/
// Section: Extern Variables
/*****************************************************************************/
/*
 * Extern variables declared here are defined in other files and used across 
 * the application to manage different hardware components and peripherals.
 */
extern segment_t seven_segment_display;      /*< Seven-segment display control */
extern button_t led_indoor_button;           /*< Button for indoor LED control */
extern dc_motor_t fan;                       /*< DC motor control for fan */
extern mssp_i2c_t i2c_obj;                   /*< I2C configuration object */
extern pin_config_t gas_sensor;              /*< Gas sensor pin configuration */
extern pin_config_t speaker_gas_sensor;      /*< Speaker pin for gas sensor alert */
extern adc_conf_t adc;                       /*< ADC configuration for analog sensors */
extern chr_lcd_8bit_t lcd_1;                 /*< Character LCD configuration */
extern ccp_t PWM_FAN;                        /*< PWM control for the fan */
extern timer2_t timer_pwm;                   /*< Timer2 configuration for PWM */
extern relay_t relay_motor;                  /*< Relay control for motor */
extern relay_t relay_heater;                 /*< Relay control for heater */
extern pin_config_t seven_segment_1;         /*< Seven-segment digit 1 */
extern pin_config_t seven_segment_2;         /*< Seven-segment digit 2 */
extern pin_config_t seven_segment_3;         /*< Seven-segment digit 3 */
extern pin_config_t seven_segment_4;         /*< Seven-segment digit 4 */
extern pin_config_t seven_segment_5;         /*< Seven-segment digit 5 */
extern pin_config_t seven_segment_6;         /*< Seven-segment digit 6 */


/*****************************************************************************/
// Function Declarations
/*****************************************************************************/

/*
 * @brief initialize application.
 * it use for initialize the modules and devices 
 * It is the entry point for the system?s behavior and manages the flow of operations.
 */
void application(void);                   

/*
 * @brief Handles gas sensor readings and corresponding actions.
 * This function processes data from the gas sensor to detect harmful gases 
 * and triggers alerts or responses if needed.
 */
void gas_sensor_s(void);

/*
 * @brief Processes data from the pressure sensor.
 * This function reads and interprets data from the pressure sensor to 
 * monitor and control the pressure within the system.
 */
void pressure_Sensor(void);

/*
 * @brief Handles fan operations at high speed.
 * This function controls the fan to operate in high-speed mode, typically 
 * used for cooling or ventilation purposes.
 */
void Fan_application_high(void);

/*
 * @brief Processes data read from I2C slave devices.
 * This function reads data sent from I2C slave devices and performs 
 * necessary actions based on the received information.
 */
void MSSP_I2C_SLAVE_READ(void);

/*
 * @brief Reads temperature sensor data.
 * This function fetches temperature data from the sensor and processes it 
 * for display or control purposes.
 */
void Temperature_Read(void);

/*
 * @brief Reads and processes time from an external clock module.
 * This function reads the current time and stores it for further operations.
 * and display it on LCD
 */
void Time_Read(void);

/*
 * @brief Manages time in seconds.
 * This function processes and updates the seconds portion of the time.
 */
void Time_Seconds(void);

/*
 * @brief Manages time in minutes.
 * This function processes and updates the minutes portion of the time.
 */
void Time_Minutes(void);

/*
 * @brief Manages time in hours.
 * This function processes and updates the hours portion of the time.
 */
void Time_Hours(void);

/*
 * @brief Reads and processes the current date.
 * This function retrieves the date from an external clock module and 
 * processes it for further operations.
 */
void Date_Read(void);

/*
 * @brief Manages days in the date.
 * This function processes and updates the day portion of the date.
 * and display it on LCD
 */
void Date_Days(void);

/*
 * @brief Manages months in the date.
 * This function processes and updates the month portion of the date.
 */
void Date_Months(void);

/*
 * @brief Manages years in the date.
 * This function processes and updates the year portion of the date.
 */
void Date_Years(void);

/*
 * @brief Timer-based seven-segment display updates.
 * This function uses a timer to control the seven-segment display, ensuring 
 * proper timing for multiplexed displays.
 */
void Timer_7_Segment(void);
