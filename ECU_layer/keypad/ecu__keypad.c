#include "ecu_keypad.h"

/**
 * 
 * @param keypad_obj
 * @return 
 */
// Define the required password
static const char PASSWORD[] = "4251";

// User input buffer
#define PASSWORD_LENGTH 4
char user_input[PASSWORD_LENGTH + 1] = {0}; // Buffer for 4 characters + null terminator

// Rows and columns configuration
#define ECU_KEYPAD_ROW 4
#define ECU_KEYPAD_COL 4
#define MAX_ATTEMPTS 3

// Button values for the keypad
static const unit8 btn_values[ECU_KEYPAD_ROW][ECU_KEYPAD_COL] = 
{
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'T', '0', '=', '+'}
};
Std_ReturnType keypad_initialize(const keypad_t *keypad_obj)
{
    Std_ReturnType ret = E_OK;
    if(NULL == keypad_obj )
    {
        ret = E_NOT_OK;
    }
    else
    {
        unit8 count_row = 0;
        unit8 count_col = 0;
        for(count_row = 0 ; count_row < ECU_KEYPAD_ROW ; ++count_row)
        {
            ret = gpio_pin_intialize(&(keypad_obj->keypad_row_pins[count_row]));

        }
        for(count_col = 0 ; count_col < ECU_KEYPAD_COL ; ++count_col)
        {
            ret = gpio_pin_direction_intialize(&(keypad_obj->keypad_col_pins[count_col]));
        }
    }
    return ret ;
}

/**
 * 
 * @param keypad_obj
 * @param value
 * @return 
 */

Std_ReturnType keypad_get_value(const keypad_t *keypad_obj , unit8 *value)
{
    Std_ReturnType ret = E_OK;
    unit8 count_row = 0;
    unit8 count_row_cpy = 0;
    unit8 count_col = 0;
    unit8 col_logic = 0;
    
    if(NULL == keypad_obj )
    {
        ret = E_NOT_OK;
    }
    else
    {
        
         for(count_row = 0 ; count_row < ECU_KEYPAD_ROW ; ++count_row)
        {
             
              for(count_row_cpy = 0 ; count_row_cpy < ECU_KEYPAD_ROW ; ++count_row_cpy)
              {
                  ret = gpio_pin_write_logic(&(keypad_obj->keypad_row_pins[count_row_cpy]) , LOW);

              }
               gpio_pin_write_logic(&(keypad_obj->keypad_row_pins[count_row]) , HIGH);
               for(count_col = 0 ; count_col < ECU_KEYPAD_COL ; ++count_col)
              {
                  ret = gpio_pin_read_logic(&(keypad_obj->keypad_col_pins[count_col]) , &col_logic);
                  if(HIGH == col_logic)
                  {
                      *value = btn_values[count_row][count_col];
                  }
              }
        }
         
   
        
    }
    return ret ;
}

/**
 * Function to allow user to enter the password
 */
Std_ReturnType enter_password(const keypad_t *keypad_obj) {
    Std_ReturnType ret = E_OK;
    unit8 value = 0;
    unit8 index = 0;
    unit8 attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        index = 0; // Reset index for a new attempt
        // Prompt user to enter password (can be skipped if not displayed)
        while (index < PASSWORD_LENGTH) {
            ret = keypad_get_value(keypad_obj, &value);
            if (ret == E_OK && value != 0) { // Key detected
                if (value >= '0' && value <= '9') { // Check if it's a digit
                    user_input[index++] = value; // Store value
                }
                __delay_ms(300); // Small delay to avoid multiple detections
            }
        }
        user_input[index] = '\0'; // Null-terminate the input

        // Check the entered password
        if (strcmp(user_input, PASSWORD) == 0) {
            // Password is correct
            gpio_pin_write_logic(&(keypad_obj->keypad_row_pins[0]), HIGH); // Unlock signal
            return E_OK;
        } else {
            attempts++;
            // Optional: Provide feedback (like blinking an LED for incorrect attempts)
        }
    }

    // If reached here, all attempts failed
    gpio_pin_write_logic(&(keypad_obj->keypad_row_pins[1]), HIGH); // Error signal
    return E_NOT_OK;
}
