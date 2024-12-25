/* 
 * File:   hal_i2c.h
 * Author: Yassin_Khadrawy
 *
 * Created on December 6, 2024, 10:32 PM
 */
#include "hal_i2c.h"

/****************************************************/
#if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    static void (*I2C_MSSP_Interrupt_Handler)(void) = NULL;
    static void (*I2C_BUS_COLLISION_Interrupt_Handler)(void) = NULL;
    static void (*I2C_RECEIVE_OVERFLOW_Interrupt_Handler)(void) = NULL;

#endif
    
/****************************************************/    
/****************************************************/
static void MSSP_I2C_SELECT_MODE(const mssp_i2c_t *i2c_obj);
static inline void MSSP_I2C_INTERRUPT_CFG(const mssp_i2c_t *i2c_obj);
static void MSSP_I2C_GPIO_CFG(void);
/****************************************************/


Std_ReturnType MSSP_I2C_Init(const mssp_i2c_t *i2c_obj)
{
    Std_ReturnType ret = E_OK;
    if(i2c_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /*disable I2C module*/
        I2C_MODE_DISABLE_CFG();
        
        /* I2C  Select Mode */
        MSSP_I2C_SELECT_MODE(i2c_obj);
        
        /* I2C GPIO Mode*/
        MSSP_I2C_GPIO_CFG();
        
        /* I2C Slew Rate Control*/
        if(i2c_obj->i2c_config.i2c_slew_rate == I2C_SLEW_RATE_ENABLE)
        {
            I2C_SLEW_RATE_ENABLE_CFG();
        }
        else if(i2c_obj->i2c_config.i2c_slew_rate == I2C_SLEW_RATE_DISABLE)
        {
            I2C_SLEW_RATE_DISABLE_CFG();
        }else{/*nothing*/}
        
        /* I2C SMBus Control */
        if(i2c_obj->i2c_config.i2c_SMBus_control == I2C_SMBus_ENABLE)
        {
            I2C_SMBus_ENABLE_CFG();
        }
        else if(i2c_obj->i2c_config.i2c_SMBus_control == I2C_SMBus_DISABLE)
        {
            I2C_SMBus_DISABLE_CFG();
        }else{/*nothing*/}
        
        /* Interrupt Configurations */
#if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        MSSP_I2C_INTERRUPT_CFG(i2c_obj);
#endif

        /* enable I2C module */
        I2C_MODE_ENABLE_CFG(); 
    }   
    return ret;
}
Std_ReturnType MSSP_I2C_DeInit(const mssp_i2c_t *i2c_obj)
{
    Std_ReturnType ret = E_OK;
    if(i2c_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        I2C_MODE_DISABLE_CFG();
#if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        MSSP_InterruptDisable();
#endif
#if BUS_COLLISION_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        BUS_COLLISION_InterruptDisable();
#endif
    }   
    return ret;
}
Std_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t *i2c_obj)
{
    Std_ReturnType ret = E_OK;
    if(i2c_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SSPCON2bits.SEN = 1;
        while(SSPCON2bits.SEN);
        PIR1bits.SSPIF = 0;
        if(START_BIT_DETECTED == SSPSTATbits.S)
        {
            ret = E_OK;
        }
        else
        {
            ret = E_NOT_OK;
        }
    }   
    return ret;
}
Std_ReturnType MSSP_I2C_Master_Send_Repeated_Start(const mssp_i2c_t *i2c_obj)
{
    Std_ReturnType ret = E_OK;
    if(i2c_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SSPCON2bits.RSEN = 1;
        while(SSPCON2bits.RSEN);
        PIR1bits.SSPIF = 0;   
    }   
    return ret;
}
Std_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t *i2c_obj)
{
    Std_ReturnType ret = E_OK;
    if(i2c_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SSPCON2bits.PEN = 1;
        while(SSPCON2bits.PEN);
        PIR1bits.SSPIF = 0;
        if(STOP_BIT_DETECTED == SSPSTATbits.P)
        {
            ret = E_OK;
        }
        else
        {
            ret = E_NOT_OK;
        }
    }   
    return ret;
}
Std_ReturnType MSSP_I2C_Master_Write_Blocking(const mssp_i2c_t *i2c_obj , unit8 i2c_data ,unit8 *ack)
{
    Std_ReturnType ret = E_OK;
    if(i2c_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SSPBUF = i2c_data;
        while(!PIR1bits.SSPIF);
        PIR1bits.SSPIF = 0;
        if(SSPCON2bits.ACKSTAT == I2C_ACK_NOT_RECEIVED_FROM_SLAVE)
        {
            *ack = I2C_ACK_NOT_RECEIVED_FROM_SLAVE;
        }
        else if(SSPCON2bits.ACKSTAT == I2C_ACK_RECEIVED_FROM_SLAVE)
        {
            *ack = I2C_ACK_RECEIVED_FROM_SLAVE;
        }
        else{/*nothing*/}
    }   
    return ret;
}
Std_ReturnType MSSP_I2C_Master_Read_Blocking(const mssp_i2c_t *i2c_obj, unit8 ack, unit8 *i2c_data)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == i2c_obj) || (NULL == i2c_data)){
        ret = E_NOT_OK;
    }
    else{
        /* Master Mode Receive Enable */
        I2C_MASTER_REVEIVE_ENABLE_CFG();
        /* Wait for buffer full flag : A complete byte received */
        while(!SSPSTATbits.BF);
        /* Copy The data registers to buffer variable */
        *i2c_data = SSPBUF;
        /* Send ACK or NACK after read */
        if(0 == ack){
            SSPCON2bits.ACKDT = 0; /* Acknowledge */
            /* Initiates Acknowledge sequence on SDA and SCL pins and transmit ACKDT data bit. */
            SSPCON2bits.ACKEN = 1; 
            while(SSPCON2bits.ACKEN); /* Automatically cleared by hardware */
        }
        else if(1 == ack){
            SSPCON2bits.ACKDT = 1; /* Not Acknowledge */
            /* Initiates Acknowledge sequence on SDA and SCL pins and transmit ACKDT data bit. */
            SSPCON2bits.ACKEN = 1;
            while(SSPCON2bits.ACKEN); /* Automatically cleared by hardware */
        }
        else { /* Nothing */ }
        ret = E_OK;
    }
    return ret;
}
void MSSP_I2C_Master_call_slave(const mssp_i2c_t *i2c_obj, unit8 address,unit8 data, unit8 *_ack)
{
    MSSP_I2C_Master_Send_Start(i2c_obj);
    MSSP_I2C_Master_Write_Blocking(i2c_obj,address,_ack);
    MSSP_I2C_Master_Write_Blocking(i2c_obj,data,_ack);
    MSSP_I2C_Master_Send_Stop(i2c_obj);
}
static void MSSP_I2C_SELECT_MODE(const mssp_i2c_t *i2c_obj)
{
    if(i2c_obj->i2c_config.i2c_mode == I2C_MASTER_MODE)
    {
        SSPCON1bits.SSPM = i2c_obj->i2c_config.i2c_mode_cfg;
        SSPADD = (unit8)(((_XTAL_FREQ / 4.0) / i2c_obj->i2c_clock) - 1);
    }
    else if(i2c_obj->i2c_config.i2c_mode == I2C_SLAVE_MODE)
    {
        if(i2c_obj->i2c_config.i2c_general_call == I2C_GENERAL_CALL_ENABLE)
        {
            I2C_GENERAL_CALL_ENABLE_CFG();
        }
        else if(i2c_obj->i2c_config.i2c_general_call == I2C_GENERAL_CALL_DISABLE)
        {
            I2C_GENERAL_CALL_DISABLE_CFG();
        }else{/*nothing*/}
        SSPCON1bits.WCOL = 0;
        SSPCON1bits.SSPOV = 0;
        SSPCON1bits.CKP = 1; 
        SSPADD = i2c_obj->i2c_config.i2c_slave_address ;
        SSPCON1bits.SSPM = i2c_obj->i2c_config.i2c_mode_cfg;
    }
    else{/*Nothing*/}
}
static void MSSP_I2C_GPIO_CFG(void)
{   
    TRISCbits.TRISC3 = 1; // serial_clock_input
    TRISCbits.TRISC4 = 1; // serial_data_input
}
static inline void MSSP_I2C_INTERRUPT_CFG(const mssp_i2c_t *i2c_obj)
{
#if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        MSSP_InterruptEnable();
        MSSP_InterruptFlagClear();
        BUS_COLLISION_InterruptEnable();
        BUS_COLLISION_InterruptFlagClear();
        I2C_BUS_COLLISION_Interrupt_Handler = i2c_obj->I2C_Report_Write_Collision;
        I2C_RECEIVE_OVERFLOW_Interrupt_Handler = i2c_obj->I2C_Report_Receive_Overflow;
        I2C_MSSP_Interrupt_Handler = i2c_obj->I2C_Default_Interrupt_Handler;
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
        
        INTERRUPT_PriorityLevelEnable();
        if(i2c_obj->priority_MSSP == INTERRUPT_HIGH_PRIORITY)
        {
            INTERRUPT_GLOBALPriorityInterruptHighEnable();
            MSSP_HighPrioritySet();
        }
        else if(i2c_obj->priority_MSSP == INTERRUPT_LOW_PRIORITY)
        {
            INTERRUPT_GLOBALPriorityInterruptlowEnable();
            MSSP_LowPrioritySet();
        }
        else{/*nothing*/}
        if(i2c_obj->priority_BUS_COLLISION == INTERRUPT_HIGH_PRIORITY)
        {
            INTERRUPT_GLOBALPriorityInterruptHighEnable();
            BUS_COLLISION_HighPrioritySet();
        }
        else if(i2c_obj->priority_BUS_COLLISION == INTERRUPT_LOW_PRIORITY)
        {
            INTERRUPT_GLOBALPriorityInterruptlowEnable();
            BUS_COLLISION_LowPrioritySet();
        }
        else{/*nothing*/}
#else
        
        INTERRUPT_GLOBALInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        
#endif     
#endif
}
void MSSP_ISR(void)
{
    #if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    MSSP_InterruptFlagClear();
    if(I2C_MSSP_Interrupt_Handler)
    {
        I2C_MSSP_Interrupt_Handler();
    }
    #endif
}
void BUS_COLLISION_ISR(void)
{
    #if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

    BUS_COLLISION_InterruptFlagClear();
    if(I2C_BUS_COLLISION_Interrupt_Handler)
    {
        I2C_BUS_COLLISION_Interrupt_Handler();
    }
#endif
}
