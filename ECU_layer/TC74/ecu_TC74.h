/* 
 * File:   ecu_TC74.h
 * Author: KimoStore
 *
 * Created on December 10, 2024, 11:24 PM
 */

#ifndef ECU_TC74_H
#define	ECU_TC74_H

#define TC74_ADDRESS  0X9E
#define TC74_REGISTER 0x00
#include "../../MCAL_layer/I2C/hal_i2c.h"
void I2C_Real_Temperature_Read_TC74(const mssp_i2c_t *i2c_obj, unit8 Slave_Address, unit8 Reg ,unit8 *ret_data,unit8 *_ack);

#endif	/* ECU_TC74_H */

