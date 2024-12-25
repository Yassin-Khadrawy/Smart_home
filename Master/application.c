/*
 * File:   MAIN_MICRO.c
 * Author: Yassin_Khadrawy
 *
 * Created on September 7, 2024, 7:29 PM
 */
#include "application.h"

/*
 * The main() function initializes the application and enters an infinite loop, performing various tasks such as:
 * 1. Initializing system peripherals via the `application()` function (ADC, LCD, keypad, LED, motors, I2C).
 * 2. Continuously reading the password using `password_read()` and validating it.
 * 3. Reading data from I2C slave devices: DS1307 RTC and TC74 temperature sensor.
 * 4. Configuring Timer2 for PWM functionality to control LED brightness.
 * 5. Performing ADC conversion and processing sensor data with `ADC_application()`.
 * 6. Adjusting PWM output for LED control using `PWM_LED_OUT()`.
 * 7. Deinitializing Timer2 after PWM operation.
 * 8. Transferring data over I2C with `I2C_transfer_data()`.
 * 9. Checking the PIR sensor for motion and controlling the PIR LED using `PIR_sensor_s()`.
 * 
 * This loop ensures continuous monitoring of sensors, user input, and control outputs.
 */
int main()
{
    
    Std_ReturnType ret = E_OK;
    application();
    while(1)
    {
        password_read();
        I2C_DS1307_read();
        I2C_TC74_read();
        ret = Timer2_Init(&timer_pwm);
        ADC_application();
        PWM_LED_OUT();
        ret = Timer2_DeInit(&timer_pwm);
        PIR_sensor_s();
        I2C_transfer_data();
    }
    return (EXIT_SUCCESS);
}
/*
 * it use for initialize the modules and devices 
 * It is the entry point for the systems behavior and manages the flow of operations.
 */
void application(void)
{
    Std_ReturnType ret = E_OK;
    ADC_ANALOG_DIGITAL_PORT_CONFIG(0x0E);
    ret = lcd_8bit_initialized(&lcd_1);
    ret = keypad_initialize(&password_keypad);
    ret = led_initialize(&led_outdoor);
    ret = dc_motor_initialized(&locker);
    ret = gpio_pin_intialize(&speaker);
    ret = gpio_pin_intialize(&PIR);
    ret = led_initialize(&PIR_led);
    ret = MSSP_I2C_Init(&i2c_obj);
    ret = button_intialized(&on_keypad);
    ret = ADC_Init(&adc);
    ret = CCP_Init(&PWM_LED);
    ret = Timer0_Init(&timer0);
    ret = Timer1_Init(&timer1);
}

/*
 * This interrupt handler generates a 1000ms delay using TIMER0. 
 * It increments the `overflow_count` and sets `delay_flag_timer0` to 1 
 * after reaching the threshold, then resets the counter.
 */
void Timer0_DefaultInterruptHandler_1000ms(void) 
{
    static uint16_t overflow_count = 0;
    overflow_count++;
    if (overflow_count >= 1) { // Adjust based on clock and prescaler
        delay_flag_timer0 = 1;       // Set delay flag
        overflow_count = 0;   // Reset the counter
    }
}

/*
 * This function generates a delay of 1000 milliseconds (1 second) by using TIMER0.
 * It is useful for providing debouncing, controlling timing for sensors, or introducing a pause between operations.
 */
void Delay_1000ms(void) 
{
    delay_flag_timer0 = 0;            // Reset the delay flag
    while (delay_flag_timer0 == 0);   // Wait until the flag is set in the ISR
}

/*
 * The `Timer1_DefaultInterruptHandler_100ms function serves as the interrupt handler for TIMER1. 
 * It sets the `delay_flag_timer1` flag when triggered, indicating a 100-millisecond delay has elapsed.
 */
void Timer1_DefaultInterruptHandler_100ms(void) 
{
    delay_flag_timer1 =  1;
}

/*
 * This function generates a delay of 100 milliseconds (0.1 second) by using TIMER1.
 * It is useful for providing debouncing, controlling timing for sensors, or introducing a pause between operations.
 */
void Delay_100ms(void) 
{
    delay_flag_timer1 = 0;            // Reset the delay flag
    while (!delay_flag_timer1);   // Wait until the flag is set in the ISR
}

/*
 * This function reads the input from the user through the keypad and stores it for further processing.
 * It is responsible for capturing user input, typically a password, by detecting key presses.
 */
void password_read(void)
{
    Std_ReturnType ret = E_OK;
    //counter_pass++;
    ret = button_read_intialized( &on_keypad , &password_logic_b );
    ret = button_read_intialized( &on_keypad_indoor , &password_logic_indoor_b );
    if((password_logic_b == BUTTON_PRESSED) &&(password_logic_indoor_b == BUTTON_RELEASED))
    {
        if(transfer == 0)
        {
            transfer = 1;
            ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR );
            passowrd_counter_indoor = 0;
            password_match_indoor = 0;
            passowrd_counter = 0;
            password_match = 0;
        }else{/*nothing*/}
        ret = keypad_get_value(&password_keypad , &password__keypad_read);
        __delay_ms(100);
        if(password__keypad_read == 'T')
        {
            correct_incorrect_password();
        }
        else
        {
            detect_the_password();
        }
    }
    else if((password_logic_b == BUTTON_PRESSED) &&(password_logic_indoor_b == BUTTON_PRESSED))
    {
        if(transfer == 1)
        {
            transfer = 0;
            ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR );
            passowrd_counter_indoor = 0;
            password_match_indoor = 0;
            passowrd_counter = 0;
            password_match = 0;
        }else{/*nothing*/}
        ret = keypad_get_value(&password_keypad , &password__keypad_read_indoor);
        __delay_ms(100);
        if(password__keypad_read_indoor == 'T')
        {
            correct_incorrect_password_indoor();
        }
        else
        {
            detect_the_password_indoor();
        }
    }
    else
    {
       
    }
    
}

/*
 * This function checks if the password entered by the user matches the predefined password.
 * It compares the stored input with the expected password and returns the result of the comparison.
 */
void detect_the_password(void)
{
    Std_ReturnType ret = E_OK;
    if(password_try < 3)
    {
        if(password_clear_counter == 1)
        {
            ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR );
            password_clear_counter = 0;
        }
        else{/*nothing*/}
        ret = lcd_8bit_send_string_pos(&lcd_1 , 1 , 1 , "enter the password:");
        ret = convert_string_to_byte(&password__keypad_read, &password);
        if(passowrd_counter < 4 )
        {
            ret = lcd_8bit_send_string_pos(&lcd_1 , 2 , passowrd_counter+9 , &password__keypad_read);
        }
        else{/*nothing*/}
        if((password >= 1) && (password <= 9))
        {
            Delay_1000ms();
            if(passowrd_counter < 4)
            {
                password_match = (password_match*10) + password;
                passowrd_counter++;
            }
            else if(passowrd_counter == 4)
            {
                password_match = password_match;
            }
        }
    }
    else
    {
        gpio_pin_write_logic(&speaker , HIGH);
        ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR );
        ret = lcd_8bit_send_string_pos(&lcd_1 , 1 , 1 , "you may be a thief");
        __delay_ms(10000);
        gpio_pin_write_logic(&speaker , LOW);
        password_try = 0;
    }
}

/*
 * This function handles the outcome when the user inputs a correct or incorrect password.
 * If the password is correct, it proceeds with the authorized action (e.g., opening the locker).
 * If incorrect, it may prompt for re-entry or trigger an error.
 */
void correct_incorrect_password(void)
{
    Std_ReturnType ret = E_OK;
    if(password_clear_counter == 0)
    {
        ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR );
        password_clear_counter = 1;
    }
    else{/*nothing*/}
    if((password_match == 4321) && (passowrd_counter == 4))
    {
        ret = lcd_8bit_send_string_pos(&lcd_1 , 1 , 1 , "correct password");
        ret = lcd_8bit_send_string_pos(&lcd_1 , 2 , 2 , "the lock will open");
        MSSP_I2C_Master_call_slave(&i2c_obj, SLAVE_MCU , 'a' , &ACK_Slave);
        if(password_locker == 1)
        {
            locker_on();
            password_locker = 0;
            password_locker_indoor = 1;
            dc_motor_stop(&locker);
        }
        else{/*nothing*/}
        
    }
    else if((password_match != 4321) || (passowrd_counter != 4))
    {
        
        ret = lcd_8bit_send_string_pos(&lcd_1 , 1 , 1 , "incorrect password");
        ret = lcd_8bit_send_string_pos(&lcd_1 , 2 , 5 , "try one more");
        Delay_1000ms();
        
        ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR );
        ret = lcd_8bit_send_string_pos(&lcd_1 , 1 , 1 , "enter the password:");
        Delay_1000ms();
        
        password_try++;
        passowrd_counter = 0;
        password_match = 0;
    }
    else{/*nothing*/}
}

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
Std_ReturnType convert_string_to_byte(unit8 *str, unit8 *value) 
{
    Std_ReturnType ret = E_OK;
    if (str == NULL || value == NULL) {
        ret = E_NOT_OK;
    } else {
        int temp_value = atoi((char *)str); 
        if (temp_value < 0 || temp_value > 255) {
            ret = E_NOT_OK; 
        } else {
            *value = (unit8)temp_value;
        }
    }

    return ret;
}

/*
 * This function handles the initialization and reading of analog-to-digital converter (ADC) values.
 * It is responsible for processing sensor data (e.g., light intensity) that requires analog input.
 */
void ADC_application(void)
{
    Std_ReturnType ret = E_OK;
    ret = ADC_StartConversion_Interrupt(&adc  , ADC_CHANNEL_AN0);
    ret = ADC_GetConversionResult(&adc  , &adc_A0);
}


/*
 * This function activates the DC motor connected to the locker mechanism, allowing it to unlock or lock.
 * It is used when the user successfully enters the correct password, for example, to unlock the locker.
 */
void locker_on(void)
{
    dc_motor_move_right(&locker);
    Delay_1000ms();
}
/*
 * This function activates the DC motor connected to the locker mechanism, allowing it to unlock or lock.
 * It is used when the user successfully enters the correct password, for example, to lock the locker.
 */
void locker_reverse(void)
{
    dc_motor_move_left(&locker);
    Delay_1000ms();
}
/*
 * This function controls the brightness of an LED by adjusting the pulse width modulation (PWM) signal.
 * It can be used to dim or brighten the LED, or create visual effects such as blinking or fading.
 */
void PWM_LED_OUT(void)
{
    Std_ReturnType ret = E_OK;
    PWM_LDR = (adc_A0/1023.0)*100;
    ret = CCP1_PWM_Set_Duty(100 - PWM_LDR);
    ret = CCP1_PWM_Start();
}

/*
 * This function communicates with the TC74 temperature sensor over the I2C interface to read temperature data.
 * It requests and processes the temperature reading from the TC74 device, which is typically an 8-bit output.
 */
void I2C_TC74_read(void)
{
    I2C_Real_Temperature_Read_TC74(&i2c_obj, 0x98, 0x00 ,&TC74_read_value,&TC74_ACK_read_value);
    Delay_100ms();
}

/*
 * This function reads the current date and time from the DS1307 Real-Time Clock (RTC) via the I2C interface.
 * It retrieves the date, time, and possibly other information such as alarms or status flags from the DS1307 chip.
 */
void I2C_DS1307_read(void)
{
    I2C_Real_Time_Read_DS1307(&i2c_obj, DS1307_ADDRESS , 0x00 , &DS1307_read_value_0x00 , &DS1307_ACK_read_value_0x00);
    I2C_Real_Time_Read_DS1307(&i2c_obj, DS1307_ADDRESS , 0x01 , &DS1307_read_value_0x01 , &DS1307_ACK_read_value_0x01);
    I2C_Real_Time_Read_DS1307(&i2c_obj, DS1307_ADDRESS , 0x02 , &DS1307_read_value_0x02 , &DS1307_ACK_read_value_0x02);
    I2C_Real_Time_Read_DS1307(&i2c_obj, DS1307_ADDRESS , 0x04 , &DS1307_read_value_0x04 , &DS1307_ACK_read_value_0x04);
    I2C_Real_Time_Read_DS1307(&i2c_obj, DS1307_ADDRESS , 0x05 , &DS1307_read_value_0x05 , &DS1307_ACK_read_value_0x05);
    I2C_Real_Time_Read_DS1307(&i2c_obj, DS1307_ADDRESS , 0x06 , &DS1307_read_value_0x06 , &DS1307_ACK_read_value_0x06);
}

/*
 * This function handles the transfer of data over the I2C bus.
 * It can be used to send data to or receive data from I2C devices (e.g., sensors, displays).
 * The function may handle addressing, sending data, and ensuring proper communication protocols.
 */
void I2C_transfer_data(void)
{
    MSSP_I2C_Master_call_slave(&i2c_obj, SLAVE_MCU , TC74_read_value , &ACK_Slave);
    MSSP_I2C_Master_call_slave(&i2c_obj, SLAVE_MCU , 1 , &ACK_Slave);
    MSSP_I2C_Master_call_slave(&i2c_obj, SLAVE_MCU , DS1307_read_value_0x00 , &ACK_Slave);
    MSSP_I2C_Master_call_slave(&i2c_obj, SLAVE_MCU , DS1307_read_value_0x01 , &ACK_Slave);
    MSSP_I2C_Master_call_slave(&i2c_obj, SLAVE_MCU , DS1307_read_value_0x02 , &ACK_Slave);
    MSSP_I2C_Master_call_slave(&i2c_obj, SLAVE_MCU , DS1307_read_value_0x04 , &ACK_Slave);
    MSSP_I2C_Master_call_slave(&i2c_obj, SLAVE_MCU , DS1307_read_value_0x05 , &ACK_Slave);
    MSSP_I2C_Master_call_slave(&i2c_obj, SLAVE_MCU , DS1307_read_value_0x06 , &ACK_Slave);
}

/*
 * This function monitors the status of a Passive Infrared (PIR) sensor to detect motion.
 * If motion is detected, it could trigger an event, such as turning on a light.
 */
void PIR_sensor_s(void)
{
    Std_ReturnType ret = E_OK;
    ret = gpio_pin_read_logic(&PIR , &PIR_read);
    if(PIR_read == there_is_someone_out)
    {
        ret = led_turn_on_initialize(&PIR_led);
    }
    else if(PIR_read == there_is_no_someone_out)
    {
        ret = led_turn_off_initialize(&PIR_led);
    }else{/*nothing*/}
}

/*
 * This function checks if the password entered by the user matches the predefined password.
 * It compares the stored input with the expected password and returns the result of the comparison.
 */
void detect_the_password_indoor(void)
{
    Std_ReturnType ret = E_OK;
    if(password_try < 3)
    {
        if(password_clear_counter_indoor == 1)
        {
            ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR );
            password_clear_counter_indoor = 0;
        }
        else{/*nothing*/}
        ret = lcd_8bit_send_string_pos(&lcd_1 , 1 , 1 , "enter the password:");
        ret = convert_string_to_byte(&password__keypad_read_indoor, &password_indoor);
        if(passowrd_counter_indoor < 4 )
        {
            ret = lcd_8bit_send_string_pos(&lcd_1 , 2 , passowrd_counter_indoor+9 , &password__keypad_read_indoor);
            ret = lcd_8bit_send_char_data_pos(&lcd_1 , 2 , passowrd_counter_indoor+12 , ' ');
        }
        else{/*nothing*/}
        if((password_indoor >= 1) && (password_indoor <= 9))
        {
            Delay_1000ms();
            if(passowrd_counter_indoor < 4)
            {
                password_match_indoor = (password_match_indoor*10) + password_indoor;
                passowrd_counter_indoor++;
            }
            else if(passowrd_counter_indoor == 4)
            {
                password_match_indoor = password_match_indoor;
            }
        }
    }
    else
    {
        gpio_pin_write_logic(&speaker , HIGH);
        ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR );
        ret = lcd_8bit_send_string_pos(&lcd_1 , 1 , 1 , "you may be a thief");
        __delay_ms(10000);
        gpio_pin_write_logic(&speaker , LOW);
        password_try = 0;
    }
}

/*
 * This function handles the outcome when the user inputs a correct or incorrect password.
 * If the password is correct, it proceeds with the authorized action (e.g., closing the locker).
 * If incorrect, it may prompt for re-entry or trigger an error.
 */
void correct_incorrect_password_indoor(void)
{
    Std_ReturnType ret = E_OK;
    if(password_clear_counter_indoor == 0)
    {
        ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR );
        password_clear_counter_indoor = 1;
    }
    else{/*nothing*/}
    if((password_match_indoor == 8765) && (passowrd_counter_indoor == 4))
    {
        ret = lcd_8bit_send_string_pos(&lcd_1 , 1 , 1 , "correct password");
        ret = lcd_8bit_send_string_pos(&lcd_1 , 2 , 2 , "the lock will close");
        MSSP_I2C_Master_call_slave(&i2c_obj, SLAVE_MCU , 'b' , &ACK_Slave);
        if(password_locker_indoor == 1)
        {
            locker_reverse();
            password_locker = 1;
            password_locker_indoor = 0;
            dc_motor_stop(&locker);
        }
        else{/*nothing*/}
        
    }
    else if((password_match_indoor != 8765) || (passowrd_counter_indoor != 4))
    {
        
        ret = lcd_8bit_send_string_pos(&lcd_1 , 1 , 1 , "incorrect password");
        ret = lcd_8bit_send_string_pos(&lcd_1 , 2 , 5 , "try one more");
        Delay_1000ms();
        
        ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR );
        ret = lcd_8bit_send_string_pos(&lcd_1 , 1 , 1 , "enter the password:");
        Delay_1000ms();
        
        password_try_indoor++;
        passowrd_counter_indoor = 0;
        password_match_indoor = 0;
    }
    else{/*nothing*/}
}