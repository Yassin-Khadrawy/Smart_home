#include "mcal_layer_init.h"
mssp_i2c_t i2c_obj=
{
    .i2c_config.i2c_mode = I2C_MASTER_MODE,
    .i2c_config.i2c_mode_cfg = I2C_MASTER_MODE_DEFINED_CLOCK,
    .i2c_clock = 100000,
    .i2c_config.i2c_SMBus_control = I2C_SMBus_DISABLE,
    .i2c_config.i2c_slew_rate = I2C_SLEW_RATE_DISABLE,
    //.I2C_Default_Interrupt_Handler = NULL,
    //.I2C_Report_Receive_Overflow = NULL,
    //.I2C_Report_Write_Collision = NULL,
};
pin_config_t speaker =
{
    .dirction = OUTPUT,
    .logic = LOW,
    .pin = pin0,
    .port = PORTC_INDEX,
};
pin_config_t PIR =
{
    .dirction = INPUT,
    .logic = LOW,
    .pin = pin1,
    .port = PORTC_INDEX,
};
ccp_t PWM_LED =
{
    .PWM_Frequency = 5000,
    .timer2_postscaler_value = CCP_TIMER2_POSTSCALER_DIV_BY_1 ,
    .timer2_prescaler_value = CCP_TIMER2_PRESCALER_DIV_BY_1 ,
    .ccp_inst_1_or_2 = CCP1_INST ,
    .ccp_mode = CCP_PWM_MODE_SELECTED ,
    .ccp_mode_variant = CCP_PWM_MODE,
    .ccp_pin.dirction = OUTPUT,
    .ccp_pin.logic = LOW,
    .ccp_pin.port = PORTC_INDEX,
    .ccp_pin.pin = pin2,
};
timer2_t timer_pwm =
{
    .postscaler_enum = TIMER2_POSTSCALER_DIV_BY_1,
    .prescaler_enum = TIMER2_PRESCALER_DIV_BY_1,
    .timer1_preload_value = 0 ,
};
timer0_t timer0= 
{
    .TIMER0_InterruptHandler = Timer0_DefaultInterruptHandler_1000ms,
    .timer0_mode = TIMER0_TIMER_MODE,
    .timer_register_size = TIMER0_16_BIT_MODE,
    .prescaler = TIMER0_PRESCALER_ENABLE_CFG,
    .prescaler_value = TIMER0_PRESCALER_DIV_BY_32,
    .timer0_pteload_value = 3036
};
timer1_t timer1 =
{
    .clock_status = TIMER1_CLOCK_ANOTHER,
    .timer1_oscillator_mode = TIMER1_OSC_DISABLE,
    .timer1_No_bits_RW = TIMER1_RW_16,
    .timer1_timer_counter = TIMER1_TIMER_MODE,
    .timer1_syncro_non_syncro = TIMER1_NON_SYNCHRONIZE,
    .timer1_preload_value = 55536,
    .prescalaer_value = TIMER1_PRESCALER_DIV_BY_8,
    .timer1_interrupt_handler = Timer1_DefaultInterruptHandler_100ms,
};
adc_conf_t adc = 
{
    .ADC_InterruptHandler = NULL,
    .acquisition_time = ADC_4_TAD,
    .adc_channel = ADC_CHANNEL_AN0,
    .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_8,
    .result_format = ADC_RESULT_RIGHT,
    .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED,
};
