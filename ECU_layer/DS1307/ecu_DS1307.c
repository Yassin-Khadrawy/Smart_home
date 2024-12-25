#include "ecu_DS1307.h"
void I2C_Real_Time_Read_DS1307(const mssp_i2c_t *i2c_obj, unit8 Slave_Address, unit8 Reg ,unit8 *ret_data,unit8 *_ack)
{
    Std_ReturnType ret = E_NOT_OK;
    
    if((NULL == i2c_obj) || (NULL == _ack))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = MSSP_I2C_Master_Send_Start(i2c_obj);
        MSSP_I2C_Master_Write_Blocking(i2c_obj,Slave_Address,_ack);   
        MSSP_I2C_Master_Write_Blocking(i2c_obj,Reg,_ack);
        MSSP_I2C_Master_Send_Repeated_Start(i2c_obj);
        MSSP_I2C_Master_Write_Blocking(i2c_obj,(Slave_Address + 0x01),_ack);
        MSSP_I2C_Master_Read_Blocking(i2c_obj , I2C_NOT_ACK_MASTER_RECEIVED , ret_data);
        ret = MSSP_I2C_Master_Send_Stop(i2c_obj);
      }
        
}
