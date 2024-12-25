/* 
 * File:   ecu_24C01C.h
 * Author: KimoStore
 *
 * Created on December 10, 2024, 11:42 PM
 */

#ifndef ECU_24C01C_H
#define	ECU_24C01C_H

#include "../../MCAL_layer/I2C/hal_i2c.h"

void I2C_Real_EEPROM_Write_24C01C(const mssp_i2c_t *i2c_obj, unit8 Slave_Address, unit8 Reg ,unit8 ret_data,unit8 *_ack);


#endif	/* ECU_24C01C_H */

