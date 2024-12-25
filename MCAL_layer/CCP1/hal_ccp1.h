/* 
 * File:   ccp1_cfg.h
 * Author: KimoStore
 *
 * Created on December 15, 2024, 12:21 AM
 */

#ifndef CCP1_CFG_H
#define	CCP1_CFG_H

// section : includes
#include "../interrupts/internal_interrupts.h"
#include "../GPIO/hal_gpio.h"
#include <pic18f4620.h>
#include "../../MCAL_layer/mcal_std_types.h"
#include "ccp1_cfg.h"

// macros declarations
#define CCP_MODULE_DISABLE                      ((unit8)0x00)
#define CCP_CAPTURE_MODE_1_FALLING_EDGE         ((unit8)0x04)
#define CCP_CAPTURE_MODE_1_RISING_EDGE          ((unit8)0x05)
#define CCP_CAPTURE_MODE_4_RISING_EDGE          ((unit8)0x06)
#define CCP_CAPTURE_MODE_16_RISING_EDGE         ((unit8)0x07)
#define CCP_COMPARE_MODE_SET_PIN_LOW            ((unit8)0x08)
#define CCP_COMPARE_MODE_SET_PIN_HIGH           ((unit8)0x09)
#define CCP_COMPARE_MODE_TOGGLE_ON_MATCH        ((unit8)0x02)
#define CCP_COMPARE_MODE_GEN_SW_INTERRUPT       ((unit8)0x0A)
#define CCP_COMPARE_MODE_GEN_EVENT              ((unit8)0x0B)
#define CCP_PWM_MODE                            ((unit8)0x0C)

#define CCP_CAPTURE_NOT_READY                   0X00
#define CCP_CAPTURE_READY                       0X01

#define CCP_COMPARE_NOT_READY                   0X00
#define CCP_C0MPARE_READY                       0X01


/* Timer2 Input Clock Post-scaler */
#define CCP_TIMER2_POSTSCALER_DIV_BY_1       1
#define CCP_TIMER2_POSTSCALER_DIV_BY_2       2
#define CCP_TIMER2_POSTSCALER_DIV_BY_3       3
#define CCP_TIMER2_POSTSCALER_DIV_BY_4       4
#define CCP_TIMER2_POSTSCALER_DIV_BY_5       5
#define CCP_TIMER2_POSTSCALER_DIV_BY_6       6
#define CCP_TIMER2_POSTSCALER_DIV_BY_7       7
#define CCP_TIMER2_POSTSCALER_DIV_BY_8       8
#define CCP_TIMER2_POSTSCALER_DIV_BY_9       9
#define CCP_TIMER2_POSTSCALER_DIV_BY_10      10
#define CCP_TIMER2_POSTSCALER_DIV_BY_11      11
#define CCP_TIMER2_POSTSCALER_DIV_BY_12      12
#define CCP_TIMER2_POSTSCALER_DIV_BY_13      13
#define CCP_TIMER2_POSTSCALER_DIV_BY_14      14
#define CCP_TIMER2_POSTSCALER_DIV_BY_15      15
#define CCP_TIMER2_POSTSCALER_DIV_BY_16      16

/* Timer2 Input Clock Pre-scaler */
#define CCP_TIMER2_PRESCALER_DIV_BY_1        1
#define CCP_TIMER2_PRESCALER_DIV_BY_4        4
#define CCP_TIMER2_PRESCALER_DIV_BY_16       16


// macros functions declarations
#define CCP1_SET_MODE(CCP1)  (CCP1CONbits.CCP1M = CCP1)
#define CCP2_SET_MODE(CCP2)  (CCP2CONbits.CCP2M = CCP2)
// data type declarations

typedef enum
{
    CCP1_INST,
    CCP2_INST,
}ccp_inst_t;

typedef enum
{
    CCP1_CCP2_TIMER3 = 0,
    CCP1_TIMER1_CCP2_TIMER3,
    CCP1_CCP2_TIMER1,
}ccp_capture_timer_t;

typedef enum
{
    CCP_CAPTURE_MODE_SELECTED = 0,
    CCP_COMPARE_MODE_SELECTED,
    CCP_PWM_MODE_SELECTED,
}ccp_mode_t;


typedef union
{
    struct{
        unit8 ccpr_low;
        unit8 ccpr_high;
    };
    struct
    {
        unit16 ccpr_16bit;
    };
}CCP_REG_T;


typedef struct
{
    ccp_inst_t ccp_inst_1_or_2;
    ccp_mode_t ccp_mode;
    unit8 ccp_mode_variant;
    pin_config_t ccp_pin;
    ccp_capture_timer_t ccp_capture_timer;
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED)|| (CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED)
    unit32 PWM_Frequency;
    unit8 timer2_postscaler_value : 4 ;
    unit8 timer2_prescaler_value  : 2 ;
#endif 
#if CCP1_INTERRUPT_FEATURE_ENABLE ==INTERRUPT_FEATURE_ENABLE
    void (*CCP1_Interrupt_Handler)(void);
    interrupt_priority_cfg priority_1;
#endif
#if CCP2_INTERRUPT_FEATURE_ENABLE ==INTERRUPT_FEATURE_ENABLE
    void (*CCP2_Interrupt_Handler)(void);
    interrupt_priority_cfg priority_2;
#endif
}ccp_t;


// function declarations
Std_ReturnType CCP_Init(const ccp_t *ccp_obj);
Std_ReturnType CCP_DeInit(const ccp_t *ccp_obj);
#if CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED
    Std_ReturnType CCP1_PWM_Set_Duty(unit8 duty);
    Std_ReturnType CCP1_PWM_Start(void);
    Std_ReturnType CCP1_PWM_Stop(void);
#endif
    
#if CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED
    Std_ReturnType CCP2_PWM_Set_Duty(const unit8 duty);
    Std_ReturnType CCP2_PWM_Start(void);
    Std_ReturnType CCP2_PWM_Stop(void);
#endif

#if CCP1_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED 
    Std_ReturnType CCP1_IsCaptureDataReady(unit8 *capture_status);
    Std_ReturnType CCP1_Capture_Mode_Read_Value(unit16 *capture_value);
#endif

#if CCP2_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED 
    Std_ReturnType CCP2_IsCaptureDataReady(unit8 *capture_status);
    Std_ReturnType CCP2_Capture_Mode_Read_Value(unit16 *capture_value);
#endif
    
#if CCP1_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED 
    Std_ReturnType CCP1_IsCompare_Complete(unit8 *compare_status);
    Std_ReturnType CCP1_Compare_Mode_Set_Value(unit16 compare_value);
#endif

#if CCP2_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED 
    Std_ReturnType CCP2_IsCompare_Complete(unit8 *compare_status);
    Std_ReturnType CCP2_Compare_Mode_Set_Value(unit16 compare_value);
#endif    
    

#endif	/* CCP1_CFG_H */
