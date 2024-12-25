/* 
 * File:   hal_i2c.h
 * Author: Yassin_Khadrawy
 *
 * Created on December 6, 2024, 10:32 PM
 */

#ifndef HAL_I2C_H
#define	HAL_I2C_H


// section : includes
#include "../GPIO/hal_gpio.h"
#include <pic18f4620.h>
#include "../../MCAL_layer/mcal_std_types.h"
#include "../interrupts/internal_interrupts.h"

// macros declarations

////////////////////////////////////////////////////////////////////
/*I2C Mode Enable/Disable*/
#define I2C_MODE_DISABLE      0
#define I2C_MODE_ENABLE       1
/* I2C Slew Rate Enable/Disable */
#define I2C_SLEW_RATE_DISABLE      1
#define I2C_SLEW_RATE_ENABLE       0
/* I2C SMBus Enable/Disable */
#define I2C_SMBus_ENABLE           1
#define I2C_SMBus_DISABLE          0
/* I2C Slave Mode Data/Address Indication */
#define I2C_LAST_BYTE_DISABLE      1
#define I2C_LAST_BYTE_ENABLE       0
/* I2C Start Condition Indication*/
#define START_BIT_DETECTED         1
#define START_BIT_NOT_DETECTED     0
/* I2C Stop Condition Indication*/
#define STOP_BIT_DETECTED          1
#define STOP_BIT_NOT_DETECTED      0
/* I2C Repeated Condition Indication*/
#define REPEATED_START_BIT_DETECTED         1
#define REPEATED_START_BIT_NOT_DETECTED     0
/* I2C Master Slave Mode */
#define I2C_MASTER_MODE            1
#define I2C_SLAVE_MODE             0
/* Master Synchronous Serial Port Mode Select */
#define I2C_SLAVE_MODE_7BIT_ADDRESS                    0x06U
#define I2C_SLAVE_MODE_10BIT_ADDRESS                   0x07U
#define I2C_SLAVE_MODE_7BIT_ADDRESS_SS_INT_ENABLE      0x0EU
#define I2C_SLAVE_MODE_10BIT_ADDRESS_SS_INT_ENABLE     0x0FU
#define I2C_MASTER_MODE_DEFINED_CLOCK                  0x08U
#define I2C_MASTER_MODE_FIRMWARE_CONTROLLED            0x0BU
/* General Call Enable */
#define I2C_GENERAL_CALL_ENABLE                1
#define I2C_GENERAL_CALL_DISABLE               0
/* Master Mode Receive Enable */
#define I2C_MASTER_RECEIVE_ENABLE              1
#define I2C_MASTER_RECEIVE_DISABLE             0
/* Start Bit Initiates or Not */
#define I2C_START_BIT_ON_INITIATES             1
#define I2C_START_BIT_OFF_IDLE                 0
/* Stop Bit Initiates or Not */
#define I2C_STOP_BIT_ON_INITIATES             1
#define I2C_STOP_BIT_OFF_IDLE                 0
/* Repeated Start Bit Initiates or Not */
#define I2C_REPEATED_START_BIT_ON_INITIATES             1
#define I2C_REPEATED_START_BIT_OFF_IDLE                 0
/* ACK Master Receive from slave Mode */
#define I2C_ACK_NOT_RECEIVED_FROM_SLAVE             1
#define I2C_ACK_RECEIVED_FROM_SLAVE                 0
/* ACK Master Receive Mode */
#define I2C_NOT_ACK_MASTER_RECEIVED            1
#define I2C_ACK_MASTER_RECEIVED                0
////////////////////////////////////////////////////////////////////


// macros functions declarations

////////////////////////////////////////////////////////////////////
#define I2C_MODE_ENABLE_CFG()            (SSPCON1bits.SSPEN = 1)
#define I2C_MODE_DISABLE_CFG()            (SSPCON1bits.SSPEN = 0)

#define I2C__MASTER_SLAVE_MODE_CFG(I2C)             (SSPCON1bits.SSPM = I2C)

#define I2C_SLEW_RATE_ENABLE_CFG()        (SSPSTATbits.SMP = 0)
#define I2C_SLEW_RATE_DISABLE_CFG()       (SSPSTATbits.SMP = 1)

#define I2C_SMBus_ENABLE_CFG()            (SSPSTATbits.CKE = 1)
#define I2C_SMBus_DISABLE_CFG()           (SSPSTATbits.CKE = 0)

#define I2C_GENERAL_CALL_ENABLE_CFG()     (SSPCON2bits.GCEN = 1)
#define I2C_GENERAL_CALL_DISABLE_CFG()    (SSPCON2bits.GCEN = 0)

#define I2C_MASTER_REVEIVE_ENABLE_CFG()    (SSPCON2bits.RCEN = 1)
#define I2C_MASTER_REVEIVE_DISABLE_CFG()   (SSPCON2bits.RCEN = 0)

#define I2C_START_BIT_INITIATES(I2C)                (SSPCON2bits.SEN = I2C)
#define I2C_STOP_BIT_INITIATES(I2C)                 (SSPCON2bits.PEN = I2C)
#define I2C_REPEATED_START_BIT_INITIATES(I2C)       (SSPCON2bits.RSEN = I2C)
#define I2C_InterruptFlagClear()                    (PIR1bits.SSPIF = 0)
#define I2C_NO_COLLISION_SLAVE()                    (SSPCON1bits.WCOL = 0)
#define I2C_NO_OVERFLOW_SLAVE()                     (SSPCON1bits.SSPOV = 0)
#define I2C_RELEASE_CLOCK_ENABLE()                  (SSPCON1bits.CKP = 1)
#define I2C_CLOCK_STREATCH_ENABLE()                 (SSPCON1bits.CKP = 0)
////////////////////////////////////////////////////////////////////

// data type declarations
typedef struct
{
    unit8 i2c_mode_cfg ;
    unit8 i2c_slave_address;
    unit8 i2c_mode : 1 ;
    unit8 i2c_slew_rate : 1 ;
    unit8 i2c_SMBus_control : 1 ;
    unit8 i2c_general_call : 1 ;
    unit8 i2c_master_rec_mode : 1 ;
    unit8 i2c_reserved : 3 ;
    
}i2c_configs_t;
typedef struct
{
    unit32 i2c_clock;
    i2c_configs_t i2c_config;
#if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (*I2C_Default_Interrupt_Handler)(void);
    void (*I2C_Report_Write_Collision)(void);
    void (*I2C_Report_Receive_Overflow)(void);
#endif
    
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE
    interrupt_priority_cfg priority_MSSP;
    interrupt_priority_cfg priority_BUS_COLLISION;
#endif
}mssp_i2c_t;

// function declarations
Std_ReturnType MSSP_I2C_Init(const mssp_i2c_t *i2c_obj);
Std_ReturnType MSSP_I2C_DeInit(const mssp_i2c_t *i2c_obj);
Std_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t *i2c_obj);
Std_ReturnType MSSP_I2C_Master_Send_Repeated_Start(const mssp_i2c_t *i2c_obj);
Std_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t *i2c_obj);
Std_ReturnType MSSP_I2C_Master_Write_Blocking(const mssp_i2c_t *i2c_obj , unit8 i2c_data ,unit8 *ack);
Std_ReturnType MSSP_I2C_Master_Read_Blocking(const mssp_i2c_t *i2c_obj , unit8 ack , unit8 *i2c_data );
void MSSP_I2C_Master_call_slave(const mssp_i2c_t *i2c_obj, unit8 address,unit8 data, unit8 *_ack);
#endif	/* HAL_I2C_H */

