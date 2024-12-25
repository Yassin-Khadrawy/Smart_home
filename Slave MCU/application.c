/*
 * File:   MAIN_MICRO.c
 * Author: Yassin_Khadrawy
 *
 * Created on September 7, 2024, 7:29 PM
 */
#include "application.h"
#include "MCAL_layer/I2C/hal_i2c.h"

/*
 * The main() function initializes the system and enters an infinite loop, performing the following tasks:
 * 1. Initializes peripherals by calling `application()`.
 * 2. Checks if `I2C_SLAVE_ON` is 'a' and adjusts system relays based on `I2C_temperature_value`:
 *    - If temperature >= 30, sets fan to high and turns off heater.
 *    - If 20 <= temperature < 30, turns off motor and heater.
 *    - If temperature < 20, turns on heater.
 * 3. Reads sensor values for gas, pressure, temperature, time, and date.
 * 4. Updates a seven-segment display by repeatedly calling `Timer_7_Segment()`.
 * 
 * This loop continuously monitors sensors, adjusts relays, and updates the display based on conditions.
 */
int main()
{
    
    Std_ReturnType ret = E_OK;
    application();
    while(1)
    { 
        if(I2C_SLAVE_ON == 'a' )
        {
            if(I2C_temperature_value >= 30)
            {
                Fan_application_high();
                ret = relay_turn_off(&relay_heater);
            }
            else if((I2C_temperature_value < 30) && (I2C_temperature_value >= 20))
            {
                ret = relay_turn_off(&relay_motor);
                ret = relay_turn_off(&relay_heater);
            }
            else if(I2C_temperature_value < 20)
            {
                ret = relay_turn_on(&relay_heater);
            }
            gas_sensor_s();
            pressure_Sensor();
            Temperature_Read();
            Time_Read();
            Date_Read();
            for(unit8 co = 0 ; co < 200 ; ++co)
            {
                Timer_7_Segment();  
            }
        }
        else if(I2C_SLAVE_ON == 'b' )
        {
            ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR );
            ret = relay_turn_off(&relay_motor);
            ret = relay_turn_off(&relay_heater);
            
        }
    }
    return (EXIT_SUCCESS);
}

/*
 * @brief Main application logic.
 * This function contains the primary functionality of the system and initialize of modules and 
 * integrates various modules to achieve the desired behavior.
 */
void application(void)
{
    ADC_ANALOG_DIGITAL_PORT_CONFIG(0x0E);
    Std_ReturnType ret = E_OK;
    ret = button_intialized(&led_indoor_button);
    ret = dc_motor_initialized(&fan);
    ret = seven_segment_initialized(&seven_segment_display);
    ret = gpio_pin_intialize(&gas_sensor);
    ret = gpio_pin_intialize(&speaker_gas_sensor);
    ret = gpio_pin_intialize(&seven_segment_1);
    ret = gpio_pin_intialize(&seven_segment_2);
    ret = gpio_pin_intialize(&seven_segment_3);
    ret = gpio_pin_intialize(&seven_segment_4);
    ret = MSSP_I2C_Init(&i2c_obj);
    ret = gpio_port_direction_intialize(PORTD_INDEX , OUTPUT);
    ret = ADC_Init(&adc);
    ret = lcd_8bit_initialized(&lcd_1);
    ret = CCP_Init(&PWM_FAN);
    ret = relay_initialized(&relay_motor);
    ret = relay_initialized(&relay_heater);
    
}
/*
 * @brief Processes data read from I2C slave devices.
 * This function reads data sent from I2C slave devices and performs 
 * necessary actions based on the received information.
 */
void MSSP_I2C_SLAVE_READ(void)
{
    Std_ReturnType ret = E_OK;
    I2C_CLOCK_STREATCH_ENABLE();
    if((SSPSTATbits.R_nW == 0) && (SSPSTATbits.D_nA == 0))
    {
        unit8 buffer = SSPBUF;
        while(!SSPSTATbits.BF);
        if((counter == 0) && (counter_i2c == 0))
        {
            I2C_temperature_value = SSPBUF;
            counter_i2c++;
        }
        else if((counter == 1) && (counter_i2c == 2))
        {
            I2C_Seconds_value = SSPBUF;
            counter++;
            counter_i2c++;
        }
        else if((counter == 2) && (counter_i2c == 3))
        {
            I2C_Minutes_value = SSPBUF;
            counter++;
            counter_i2c++;
        }
        else if((counter == 3) && (counter_i2c == 4))
        {
            I2C_Hours_value = SSPBUF;
            counter++;
            counter_i2c++;
        }
        else if((counter == 4) && (counter_i2c == 5))
        {
            I2C_Days_value = SSPBUF;
            counter++;
            counter_i2c++;
        }
        else if((counter == 5) && (counter_i2c == 6))
        {
            I2C_Months_value = SSPBUF;
            counter++;
            counter_i2c++;
        }
        else if((counter == 6) && (counter_i2c == 7))
        {
            I2C_Years_value = SSPBUF;
            counter++;
            counter_i2c++;
        }
        else if((counter == 7) && (counter_i2c == 8))
        {
            I2C_SLAVE_ON = SSPBUF;
            counter = 0;
            counter_i2c = 0;
        }
        if((SSPBUF == 1) && (counter_i2c % 2 == 1))
        {
            counter++;
            counter_i2c++;
        }
    }
    I2C_RELEASE_CLOCK_ENABLE();
}
/*
 * @brief Handles gas sensor readings and corresponding actions.
 * This function processes data from the gas sensor to detect harmful gases 
 * and triggers alerts or responses if needed.
 */
void gas_sensor_s(void)
{
    Std_ReturnType ret = E_OK;
    ret = gpio_pin_read_logic(&gas_sensor , &gas_sensor_read);
    if(gas_sensor_read == there_is_gas)
    {
        ret = gpio_pin_write_logic(&speaker_gas_sensor ,HIGH );
    }
    else if(gas_sensor_read == there_is_no_gas)
    {
        ret = gpio_pin_write_logic(&speaker_gas_sensor ,LOW );
    }else{/*nothing*/}
}

/*
 * @brief Processes data from the pressure sensor.
 * This function reads and interprets data from the pressure sensor to 
 * monitor and control the pressure within the system.
 */
void pressure_Sensor(void)
{
    Std_ReturnType ret = E_OK; 
    ret = ADC_StartConversion_Interrupt( &adc , ADC_CHANNEL_AN0 );
    ret = ADC_GetConversionResult( &adc , &adc_result);
    pressure = adc_result;
    pressure = (((adc_result * 5.0) / 1023.0) / (5.0 * 0.009)) + 10.56 - 1.50;
    ret = convert_float_two_dec_to_string(pressure , adc_res_2_txt);
    ret = lcd_8bit_send_string_pos(&lcd_1  , 4 , 1 , "Air:" );
    ret = lcd_8bit_send_string_pos(&lcd_1  , 4 , 5 , adc_res_2_txt );
    ret = lcd_8bit_send_string_pos(&lcd_1  , 4 , 9 , "KPa" );  
}
/*
 * @brief Handles fan operations at high speed.
 * This function controls the fan to operate in high-speed mode, typically 
 * used for cooling or ventilation purposes.
 */
void Fan_application_high(void)
{
    Std_ReturnType ret = E_OK;
    dc_motor_move_right(&fan);
    ret = relay_turn_on(&relay_motor);
    ret = Timer2_Init(&timer_pwm);
    ret = CCP2_PWM_Set_Duty(80);
    ret = CCP2_PWM_Start();
    ret = Timer2_DeInit(&timer_pwm); 
}
/*
 * @brief Reads temperature sensor data.
 * This function fetches temperature data from the sensor and processes it 
 * for display or control purposes.
 */
void Temperature_Read(void)
{
    Std_ReturnType ret = E_OK;
    ret = convert_byte_to_string(I2C_temperature_value , &temperature_value );
    ret = lcd_8bit_send_string_pos( &lcd_1 , 3 , 1 , "TEMP:");
    ret = lcd_8bit_send_string_pos( &lcd_1 , 3 , 6 , temperature_value);
    ret = lcd_8bit_send_string_pos( &lcd_1 , 3 , 8 , ".0C");
}
/*
 * @brief Reads and processes time from an external clock module.
 * This function reads the current time and stores it for further operations.
 * and display it on LCD
 */
void Time_Read(void)
{
    Std_ReturnType ret = E_OK;
    Time_Seconds();
    Time_Minutes();
    Time_Hours();
    correct_total_seconds = I2C_Seconds_value - seconds_correct ;
    correct_total_minutes = I2C_Minutes_value - minutes_correct ;
    correct_total_hours   = I2C_Hours_value - hours_correct ;
    
    ret = convert_byte_to_string(correct_total_seconds , &Seconds_value );
    ret = convert_byte_to_string(correct_total_minutes , &Minutes_value );
    ret = convert_byte_to_string(correct_total_hours , &Hours_value );
    
    //////////////////////////////////////////////////////////////////////////////
    if(I2C_Seconds_value < 16)
    {
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 2 , 13 , '0' );
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 2 , 15 , ' ' );
        ret = lcd_8bit_send_string_pos( &lcd_1 , 2 , 14 , Seconds_value);
    }
    else
    {
        ret = lcd_8bit_send_string_pos( &lcd_1 , 2 , 13 , Seconds_value);
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 2 , 15 , ' ' );
    }
    //////////////////////////////////////////////////////////////////////////////
    if(I2C_Minutes_value < 16)
    {
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 2 , 10 , '0' );
        ret = lcd_8bit_send_string_pos( &lcd_1 , 2 , 11 , Minutes_value);
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 2 , 12 , ':' );
    }
    else
    {
        ret = lcd_8bit_send_string_pos( &lcd_1 , 2 , 10 , Minutes_value);
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 2 , 12 , ':' );
    }
    //////////////////////////////////////////////////////////////////////////////
    if(I2C_Hours_value < 16)
    {
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 2 , 7 , '0' );
        ret = lcd_8bit_send_string_pos( &lcd_1 , 2 , 8 , Hours_value);
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 2 , 9 , ':' );
    }
    else
    {
        ret = lcd_8bit_send_string_pos( &lcd_1 , 2 , 7 , Hours_value);
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 2 , 9 , ':' );
    }
}
/*
 * @brief Manages time in seconds.
 * This function processes and updates the seconds portion of the time.
 */
void Time_Seconds(void)
{
    Std_ReturnType ret = E_OK;
    if(I2C_Seconds_value < 16)
    {
        seconds_correct = 0;
    }
    if( (I2C_Seconds_value >= 16) && ((I2C_Seconds_value < 32)))
    {
        seconds_correct = 6;
    }
    else if((I2C_Seconds_value >= 32) && ((I2C_Seconds_value < 48)))
    {
        seconds_correct = 12;
    }
    else if((I2C_Seconds_value >= 48) && (I2C_Seconds_value < 64))
    {
        seconds_correct = 18;
    }
    else if((I2C_Seconds_value >= 64) && (I2C_Seconds_value < 80))
    {
        seconds_correct = 24;
    }
    else if((I2C_Seconds_value >= 80) && (I2C_Seconds_value < 96))
    {
        seconds_correct = 30;
    }
    else{/*nothing*/}
}
/*
 * @brief Manages time in minutes.
 * This function processes and updates the seconds portion of the time.
 */
void Time_Minutes(void)
{
    Std_ReturnType ret = E_OK;
    if(I2C_Minutes_value < 16)
    {
        minutes_correct = 0;
    }
    if( (I2C_Minutes_value >= 16) && ((I2C_Minutes_value < 32)))
    {
        minutes_correct = 6;
    }
    else if((I2C_Minutes_value >= 32) && ((I2C_Minutes_value < 48)))
    {
        minutes_correct = 12;
    }
    else if((I2C_Minutes_value >= 48) && (I2C_Minutes_value < 64))
    {
        minutes_correct = 18;
    }
    else if((I2C_Minutes_value >= 64) && (I2C_Minutes_value < 80))
    {
        minutes_correct = 24;
    }
    else if((I2C_Minutes_value >= 80) && (I2C_Minutes_value < 96))
    {
        minutes_correct = 30;
    }
    else{/*nothing*/}
}
/*
 * @brief Manages time in hours.
 * This function processes and updates the seconds portion of the time.
 */
void Time_Hours(void)
{
    Std_ReturnType ret = E_OK;
    if(I2C_Hours_value < 16)
    {
        hours_correct = 0;
    }
    if( (I2C_Hours_value >= 16) && ((I2C_Hours_value < 32)))
    {
        hours_correct = 6;
    }
    else if((I2C_Hours_value >= 32) && ((I2C_Hours_value < 48)))
    {
        hours_correct = 12;
    }else{/*nothing*/}
}
/*
 * @brief Manages days in the date.
 * This function processes and updates the day portion of the date.
 * and display it on LCD
 */
void Date_Read(void)
{
    Std_ReturnType ret = E_OK;
    Date_Days();
    Date_Months();
    Date_Years();
    correct_total_Days = I2C_Days_value - Days_correct ;
    correct_total_Months = I2C_Months_value - Months_correct ;
    correct_total_Years   = I2C_Years_value - Years_correct ;
    
    ret = convert_byte_to_string( correct_total_Days , &Days_value );
    ret = convert_byte_to_string(correct_total_Months , &Months_value );
    ret = convert_byte_to_string(correct_total_Years , &Years_value );
    
    ret = lcd_8bit_send_string_pos( &lcd_1 , 1 , 6 , "20");
    ret = lcd_8bit_send_char_data_pos( &lcd_1 , 1 , 10 , '/' );
    ret = lcd_8bit_send_char_data_pos( &lcd_1 , 1 , 13 , '/' );
    //////////////////////////////////////////////////////////////////////////////
    if(I2C_Days_value < 16)
    {
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 1 , 14 , '0' );
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 1 , 16 , ' ' );
        ret = lcd_8bit_send_string_pos( &lcd_1 , 1 , 15 , Days_value);
    }
    else
    {
        ret = lcd_8bit_send_string_pos( &lcd_1 , 1 , 14 , Days_value);
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 1 , 16 , ' ' );
    }
    //////////////////////////////////////////////////////////////////////////////
    if(I2C_Months_value < 16)
    {
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 1 , 11 , '0' );
        ret = lcd_8bit_send_string_pos( &lcd_1 , 1 , 12 , Months_value);
    }
    else
    {
        ret = lcd_8bit_send_string_pos( &lcd_1 , 1 , 11 , Months_value);
    }
    //////////////////////////////////////////////////////////////////////////////
    if(I2C_Years_value < 16)
    {
        ret = lcd_8bit_send_char_data_pos( &lcd_1 , 1 , 8 , '0' );
        ret = lcd_8bit_send_string_pos( &lcd_1 , 1 , 9 , Years_value);
    }
    else
    {
        ret = lcd_8bit_send_string_pos( &lcd_1 , 1 , 8 , Years_value);
    }
    //////////////////////////////////////////////////////////////////////////////

}
/*
 * @brief Manages days in the date.
 * This function processes and updates the month portion of the date.
 */
void Date_Days(void)
{
    Std_ReturnType ret = E_OK;
    if(I2C_Days_value < 16)
    {
        Days_correct = 0;
    }
    if( (I2C_Days_value >= 16) && ((I2C_Days_value < 32)))
    {
        Days_correct = 6;
    }
    else if((I2C_Days_value >= 32) && ((I2C_Days_value < 48)))
    {
        Days_correct = 12;
    }else{/*nothing*/}
}
/*
 * @brief Manages months in the date.
 * This function processes and updates the month portion of the date.
 */
void Date_Months(void)
{
    Std_ReturnType ret = E_OK;
    if(I2C_Months_value < 16)
    {
        Months_correct = 0;
    }
    if( (I2C_Months_value >= 16) && ((I2C_Months_value < 32)))
    {
        Months_correct = 6;
    }else{/*nothing*/}
}
/*
 * @brief Manages years in the date.
 * This function processes and updates the month portion of the date.
 */
void Date_Years(void)
{
    Std_ReturnType ret = E_OK;
    if(I2C_Years_value < 16)
    {
        Years_correct = 0;
    }
    if( (I2C_Years_value >= 16) && ((I2C_Years_value < 32)))
    {
        Years_correct = 6;
    }
    else if((I2C_Years_value >= 32) && ((I2C_Years_value < 48)))
    {
        Years_correct = 12;
    }else{/*nothing*/}
}
/*
 * @brief Timer-based seven-segment display updates.
 * This function uses a timer to control the seven-segment display, ensuring 
 * proper timing for multiplexed displays.
 */
void Timer_7_Segment(void)
{
    Std_ReturnType ret = E_OK;
    
    ret = seven_segment_write_number( &seven_segment_display , correct_total_minutes%10 );
    ret = gpio_pin_write_logic(&seven_segment_4, HIGH);
    __delay_us(1);
    ret = gpio_pin_write_logic(&seven_segment_4, LOW);

    ret = seven_segment_write_number( &seven_segment_display , correct_total_minutes/10 );
    ret = gpio_pin_write_logic(&seven_segment_3, HIGH);
    __delay_us(1);
    ret = gpio_pin_write_logic(&seven_segment_3, LOW);

    ret = seven_segment_write_number( &seven_segment_display , correct_total_hours%10 );
    ret = gpio_pin_write_logic(&seven_segment_2, HIGH);
    __delay_us(1);
    ret = gpio_pin_write_logic(&seven_segment_2, LOW);

    ret = seven_segment_write_number( &seven_segment_display , correct_total_hours/10 );
    ret = gpio_pin_write_logic(&seven_segment_1, HIGH);
    __delay_us(1);
    ret = gpio_pin_write_logic(&seven_segment_1, LOW);
    
}
