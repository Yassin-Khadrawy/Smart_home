/* 
 * File:   hal_ccp1.h
 * Author: Yassin Khadrawy
 *
 * Created on December 15, 2024, 12:16 AM
 */
#include "hal_ccp1.h"


static void CCP1_CAPTURE_Mode(const ccp_t *ccp_obj);
static void CCP1_COMPARE_Mode(const ccp_t *ccp_obj);
static void CCP1_PWM_Mode(const ccp_t *ccp_obj);
static void CCP1_CALL(const ccp_t *ccp_obj);

static void CCP2_CAPTURE_Mode(const ccp_t *ccp_obj);
static void CCP2_COMPARE_Mode(const ccp_t *ccp_obj);
static void CCP2_PWM_Mode(const ccp_t *ccp_obj);
static void CCP2_CALL(const ccp_t *ccp_obj);

static void CCP1_CCP2_TIMER_CAPTURE(const ccp_t *ccp_obj);

#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    static void CCP1_Interrupt(const ccp_t *ccp_obj);
    static void (*CCP1_InterruptHandler)(void) = NULL;
#endif    
#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    static void CCP2_Interrupt(const ccp_t *ccp_obj);
    static void (*CCP2_InterruptHandler)(void) = NULL;
#endif
    
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

Std_ReturnType CCP_Init(const ccp_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ccp_obj->ccp_inst_1_or_2 == CCP1_INST)
        {
            CCP1_CALL(ccp_obj);
        }
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
        else if(ccp_obj->ccp_inst_1_or_2 == CCP2_INST)
        {
            CCP2_CALL(ccp_obj);
        }
        else{/*nothing*/};
    }   
    return ret;
}
Std_ReturnType CCP_DeInit(const ccp_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ccp_obj->ccp_inst_1_or_2 == CCP1_INST)
        {
            CCP1_SET_MODE(CCP_MODULE_DISABLE);
        }
        else if(ccp_obj->ccp_inst_1_or_2 == CCP2_INST)
        {
            CCP2_SET_MODE(CCP_MODULE_DISABLE);
        }else{/**/}
        
#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        CCP1_InterruptDisable();
#endif
    }   
    return ret;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

#if CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED

    Std_ReturnType CCP1_PWM_Set_Duty(unit8 duty)
    {
        Std_ReturnType ret = E_OK;
        unit16 duty_temp = 0;
        duty_temp = (unit16)(((PR2 + 1)*(duty/100.0))*4);
        CCP1CONbits.DC1B = (unit8)((duty_temp) & 0x0003);
        CCPR1L = (unit8)(duty_temp>>2);
        return ret ;
    }
    Std_ReturnType CCP1_PWM_Start(void)
    {
        Std_ReturnType ret = E_OK;
        CCP1_SET_MODE(CCP_PWM_MODE);
        return ret;
    }
    Std_ReturnType CCP1_PWM_Stop(void)
    {
        Std_ReturnType ret = E_OK;
        CCP1_SET_MODE(CCP_MODULE_DISABLE);
        return ret;
    }
#endif
#if CCP1_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED
Std_ReturnType CCP1_IsCaptureDataReady(unit8 *capture_status)
{
    Std_ReturnType ret = E_OK;
    if(capture_status == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(PIR1bits.CCP1IF == CCP_CAPTURE_NOT_READY)
        {
            *capture_status == CCP_CAPTURE_NOT_READY;
        }
        else if(PIR1bits.CCP1IF == CCP_CAPTURE_READY)
        {
            *capture_status == CCP_CAPTURE_READY;
            CCP1_InterruptFlagClear();
        }
        else{/*nothing*/}
    }   
    return ret;
}
Std_ReturnType CCP1_Capture_Mode_Read_Value(unit16 *capture_value)
{
    Std_ReturnType ret = E_OK;
    CCP_REG_T capture_temp_value = {.ccpr_low = 0, .ccpr_high = 0};
    if(capture_value == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        capture_temp_value.ccpr_low = CCPR1L;
        capture_temp_value.ccpr_high = CCPR1H;
        *capture_value = capture_temp_value.ccpr_16bit;
    }   
    return ret;
}
#endif
#if CCP1_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED 
Std_ReturnType CCP1_IsCompare_Complete(unit8 *compare_status)
{
    Std_ReturnType ret = E_OK;
    if(compare_status == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(PIR1bits.CCP1IF == CCP_COMPARE_NOT_READY)
        {
            *compare_status = CCP_COMPARE_NOT_READY;
        }
        else if(PIR1bits.CCP1IF == CCP_C0MPARE_READY)
        {
            *compare_status = CCP_C0MPARE_READY;
            CCP1_InterruptFlagClear();
        }
        else{/*nothing*/}
    }   
    return ret;
}
     Std_ReturnType CCP1_Compare_Mode_Set_Value(unit16 compare_value)
{
    Std_ReturnType ret = E_OK;
    if(compare_value == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        CCP_REG_T compare_temp_value;
        compare_temp_value.ccpr_16bit = compare_value;
        CCPR1L = compare_temp_value.ccpr_low;
        CCPR1H = compare_temp_value.ccpr_high;
    }   
    return ret;
}         
#endif
#if CCP1_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED
    
static void CCP1_CAPTURE_Mode(const ccp_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(ccp_obj->ccp_mode_variant)
        {
            case CCP_CAPTURE_MODE_1_FALLING_EDGE:
            {
                CCP1_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE);
                break;
            }
            case CCP_CAPTURE_MODE_1_RISING_EDGE:
            {
                CCP1_SET_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE);
                break;
            }
            case CCP_CAPTURE_MODE_4_RISING_EDGE:
            {
                CCP1_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);
                break;
            }
            case CCP_CAPTURE_MODE_16_RISING_EDGE:
            {
                CCP1_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE);
                break;
            }
            default : ret = E_NOT_OK;
        }
        CCP1_CCP2_TIMER_CAPTURE(ccp_obj);
    }   
}
#endif
#if CCP1_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED

static void CCP1_COMPARE_Mode(const ccp_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(ccp_obj->ccp_mode_variant)
        {
            case CCP_COMPARE_MODE_SET_PIN_LOW:
            {
                CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);
                break;
            }
            case CCP_COMPARE_MODE_SET_PIN_HIGH:
            {
                CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);
                break;
            }
            case CCP_COMPARE_MODE_TOGGLE_ON_MATCH:
            {
                CCP1_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);
                break;
            }
            case CCP_COMPARE_MODE_GEN_SW_INTERRUPT:
            {
                CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT);
                break;
            }
            case CCP_COMPARE_MODE_GEN_EVENT:
            {
                CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);
                break;
            }
            default : ret = E_NOT_OK;;
        }
    }   
} 
#endif
#if CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED

static void CCP1_PWM_Mode(const ccp_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(ccp_obj->ccp_mode_variant)
        {
            case CCP_PWM_MODE:
            {
                CCP1_SET_MODE(CCP_PWM_MODE);
                break;
            }
            default : ret = E_NOT_OK;;
        }
        PR2 = (unit8)((_XTAL_FREQ / (ccp_obj->PWM_Frequency * 4.0 
                       * ccp_obj->timer2_postscaler_value 
                       * ccp_obj->timer2_prescaler_value))-1);
    }   
} 
#endif
static void CCP1_CALL(const ccp_t *ccp_obj){
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        CCP1_SET_MODE(CCP_MODULE_DISABLE);
        if(CCP_CAPTURE_MODE_SELECTED == ccp_obj->ccp_mode)
        {
#if CCP1_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED
            CCP1_CAPTURE_Mode(ccp_obj);
#endif
        }
        else if(CCP_COMPARE_MODE_SELECTED == ccp_obj->ccp_mode)
        {
#if CCP1_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED
            CCP1_COMPARE_Mode(ccp_obj);
#endif
        }
        else if(CCP_PWM_MODE_SELECTED == ccp_obj->ccp_mode)
        {
#if CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED
            CCP1_PWM_Mode(ccp_obj);
#endif
        }
        else{/*nothing*/}
        ret = gpio_pin_intialize(&(ccp_obj->ccp_pin));
#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
            CCP1_Interrupt(ccp_obj);
#endif
    }
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

#if CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED
Std_ReturnType CCP2_PWM_Set_Duty(const unit8 duty)
{
    Std_ReturnType ret = E_OK;
    unit16 duty_temp = 0;
    duty_temp = (unit16)(((PR2 + 1)*(duty/100.0))*4);
    CCP2CONbits.DC2B = (unit8)((duty_temp) & 0x0003);
    CCPR2L = (unit8)(duty_temp>>2);
    return ret ;
}
Std_ReturnType CCP2_PWM_Start(void)
{
    Std_ReturnType ret = E_OK;
    CCP2_SET_MODE(CCP_PWM_MODE);
    return ret;
}
Std_ReturnType CCP2_PWM_Stop(void)
{
    Std_ReturnType ret = E_OK;
    CCP2_SET_MODE(CCP_MODULE_DISABLE);
    return ret;
}  
#endif
#if CCP2_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED 
Std_ReturnType CCP2_IsCaptureDataReady(unit8 *capture_status)
{
    Std_ReturnType ret = E_OK;
    if(capture_status == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(PIR2bits.CCP2IF == CCP_CAPTURE_NOT_READY)
        {
            *capture_status == CCP_CAPTURE_NOT_READY;
        }
        else if(PIR2bits.CCP2IF == CCP_CAPTURE_READY)
        {
            *capture_status == CCP_CAPTURE_READY;
            CCP1_InterruptFlagClear();
        }
        else{/*nothing*/}
    }   
    return ret;
}
Std_ReturnType CCP2_Capture_Mode_Read_Value(unit16 *capture_value)
{
    Std_ReturnType ret = E_OK;
    CCP_REG_T capture_temp_value;
    if(capture_value == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        capture_temp_value.ccpr_low = CCPR2L;
        capture_temp_value.ccpr_high = CCPR2H;
        *capture_value = capture_temp_value.ccpr_16bit;
    }   
    return ret;
}

#endif
#if CCP2_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED
Std_ReturnType CCP2_IsCompare_Complete(unit8 *compare_status)
{
    Std_ReturnType ret = E_OK;
    if(compare_status == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(PIR2bits.CCP2IF == CCP_COMPARE_NOT_READY)
        {
            *compare_status = CCP_COMPARE_NOT_READY;
        }
        else if(PIR2bits.CCP2IF == CCP_C0MPARE_READY)
        {
            *compare_status = CCP_C0MPARE_READY;
            CCP1_InterruptFlagClear();
        }
        else{/*nothing*/}
    }   
    return ret;
}
    Std_ReturnType CCP2_Compare_Mode_Set_Value(unit16 compare_value)
{
    Std_ReturnType ret = E_OK;
    if(compare_value == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        CCP_REG_T compare_temp_value;
        compare_temp_value.ccpr_16bit = compare_value;
        CCPR2L = compare_temp_value.ccpr_low;
        CCPR2H = compare_temp_value.ccpr_high;
    }   
    return ret;
}

#endif
#if CCP2_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED
static void CCP2_CAPTURE_Mode(const ccp_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(ccp_obj->ccp_mode_variant)
        {
            case CCP_CAPTURE_MODE_1_FALLING_EDGE:
            {
                CCP2_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE);
                break;
            }
            case CCP_CAPTURE_MODE_1_RISING_EDGE:
            {
                CCP2_SET_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE);
                break;
            }
            case CCP_CAPTURE_MODE_4_RISING_EDGE:
            {
                CCP2_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);
                break;
            }
            case CCP_CAPTURE_MODE_16_RISING_EDGE:
            {
                CCP2_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE);
                break;
            }
            default : ret = E_NOT_OK;;
        }
        CCP1_CCP2_TIMER_CAPTURE(ccp_obj);
    }   
}
#endif
#if CCP2_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED
static void CCP2_COMPARE_Mode(const ccp_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(ccp_obj->ccp_mode_variant)
        {
            case CCP_COMPARE_MODE_SET_PIN_LOW:
            {
                CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);
                break;
            }
            case CCP_COMPARE_MODE_SET_PIN_HIGH:
            {
                CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);
                break;
            }
            case CCP_COMPARE_MODE_TOGGLE_ON_MATCH:
            {
                CCP2_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);
                break;
            }
            case CCP_COMPARE_MODE_GEN_SW_INTERRUPT:
            {
                CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT);
                break;
            }
            case CCP_COMPARE_MODE_GEN_EVENT:
            {
                CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);
                break;
            }
            default : ret = E_NOT_OK;;
        }
    }   
} 
#endif
#if CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED
static void CCP2_PWM_Mode(const ccp_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(ccp_obj->ccp_mode_variant)
        {
            case CCP_PWM_MODE:
            {
                CCP2_SET_MODE(CCP_PWM_MODE);
                break;
            }
            default : ret = E_NOT_OK;;
        }
        PR2 = (unit8)((_XTAL_FREQ / (ccp_obj->PWM_Frequency * 4.0 
                       * ccp_obj->timer2_postscaler_value 
                       * ccp_obj->timer2_prescaler_value))-1);
    }   
} 
#endif
static void CCP2_CALL(const ccp_t *ccp_obj){
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        CCP2_SET_MODE(CCP_MODULE_DISABLE);
        if(CCP_CAPTURE_MODE_SELECTED == ccp_obj->ccp_mode)
        {
#if CCP2_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED
            CCP2_CAPTURE_Mode(ccp_obj);
#endif
        }
        else if(CCP_COMPARE_MODE_SELECTED == ccp_obj->ccp_mode)
        {
#if CCP2_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED
            CCP2_COMPARE_Mode(ccp_obj);
#endif
        }
        else if(CCP_PWM_MODE_SELECTED == ccp_obj->ccp_mode)
        {
#if CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED
            CCP2_PWM_Mode(ccp_obj);
#endif
        }
        else{/*nothing*/}
        ret = gpio_pin_intialize(&(ccp_obj->ccp_pin));
#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        CCP2_Interrupt(ccp_obj);
#endif
    }
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

static void CCP1_CCP2_TIMER_CAPTURE(const ccp_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(ccp_obj->ccp_capture_timer)
        {
            case CCP1_CCP2_TIMER3:
            {
                /*Timer3 is the capture/compare clock source for the CCP modules*/
                T3CONbits.T3CCP1 = 0;
                T3CONbits.T3CCP2 = 1;
                break;
            }
            case CCP1_TIMER1_CCP2_TIMER3:
            {
                /*Timer3 is the capture/compare clock source for CCP2;
                  Timer1 is the capture/compare clock source for CCP1*/
                T3CONbits.T3CCP1 = 1;
                T3CONbits.T3CCP2 = 0;
                break;
            }
            case CCP1_CCP2_TIMER1:
            {
                /*Timer1 is the capture/compare clock source for the CCP modules*/
                T3CONbits.T3CCP1 = 0;
                T3CONbits.T3CCP2 = 0;
                break;
            }
            default:{break;}
        }
    }
}

static void CCP1_Interrupt(const ccp_t *ccp_obj)
{
#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        CCP1_InterruptEnable();
        CCP1_InterruptFlagClear();
        CCP1_InterruptHandler = ccp_obj->CCP1_Interrupt_Handler;
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PriorityLevelEnable();
        if(ccp_obj->priority_1 == INTERRUPT_HIGH_PRIORITY)
        {
            INTERRUPT_GLOBALPriorityInterruptHighEnable();
            CCP1_HighPrioritySet();
        }
        else if(ccp_obj->priority_1 == INTERRUPT_LOW_PRIORITY)
        {
            INTERRUPT_GLOBALPriorityInterruptlowEnable();
            CCP1_LowPrioritySet();
        }
#else
        INTERRUPT_GLOBALInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable(); 
#endif
#endif
}
static void CCP2_Interrupt(const ccp_t *ccp_obj)
{
#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        CCP2_InterruptEnable();
        CCP2_InterruptFlagClear();
        CCP2_InterruptHandler = ccp_obj->CCP2_Interrupt_Handler;
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PriorityLevelEnable();
        if(ccp_obj->priority_2 == INTERRUPT_HIGH_PRIORITY)
        {
            INTERRUPT_GLOBALPriorityInterruptHighEnable();
            CCP2_HighPrioritySet();
        }
        else if(ccp_obj->priority_2 == INTERRUPT_LOW_PRIORITY)
        {
            INTERRUPT_GLOBALPriorityInterruptlowEnable();
            CCP2_LowPrioritySet();
        }
#else
        INTERRUPT_GLOBALInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable(); 
#endif
#endif
}
void CCP1_ISR(void)
{
    CCP1_InterruptFlagClear();
    if(CCP1_InterruptHandler)
    {
        CCP1_InterruptHandler();
    }
}
void CCP2_ISR(void)
{
    CCP2_InterruptFlagClear();
    if(CCP2_InterruptHandler)
    {
        CCP2_InterruptHandler();
    }
}