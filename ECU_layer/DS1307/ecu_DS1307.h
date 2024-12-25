/* 
 * File:   ecu_DS1307.h
 * Author: KimoStore
 *
 * Created on December 10, 2024, 11:06 PM
 */

#ifndef ECU_DS1307_H
#define	ECU_DS1307_H

#include "../../MCAL_layer/I2C/hal_i2c.h"

#define DS1307_ADDRESS  0XD0

void I2C_Real_Time_Read_DS1307(const mssp_i2c_t *i2c_obj, unit8 Slave_Address, unit8 Reg ,unit8 *ret_data,unit8 *_ack);

#endif	/* ECU_DS1307_H */

