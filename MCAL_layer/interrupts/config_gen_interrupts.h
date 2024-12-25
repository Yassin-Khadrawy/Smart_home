/* 
 * File:   mcal_interrupt_gen_config.h
 * Author: KimoStore
 *
 * Created on October 10, 2024, 10:20 PM
 */

#ifndef MCAL_INTERRUPT_GEN_CONFIG_H
#define	MCAL_INTERRUPT_GEN_CONFIG_H



#define INTERRUPT_FEATURE_ENABLE           1U                    
//#define INTERRUPT_PRIORITY_LEVEL_ENABLE                            INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE                     INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_Onchange_FEATURE_ENABLE                 INTERRUPT_FEATURE_ENABLE
#define ADC_INTERRUPT_FEATURE_ENABLE                               INTERRUPT_FEATURE_ENABLE
#define TIMER0_INTERRUPT_FEATURE_ENABLE                            INTERRUPT_FEATURE_ENABLE
#define TIMER1_INTERRUPT_FEATURE_ENABLE                            INTERRUPT_FEATURE_ENABLE
#define TIMER2_INTERRUPT_FEATURE_ENABLE                            INTERRUPT_FEATURE_ENABLE
#define TIMER3_INTERRUPT_FEATURE_ENABLE                            INTERRUPT_FEATURE_ENABLE
#define EUSART_TX_INTERRUPT_FEATURE_ENABLE                         INTERRUPT_FEATURE_ENABLE
#define EUSART_RX_INTERRUPT_FEATURE_ENABLE                         INTERRUPT_FEATURE_ENABLE
//#define MSSP_INTERRUPT_FEATURE_ENABLE                              INTERRUPT_FEATURE_ENABLE
#define SPI_INTERRUPT_FEATURE_ENABLE                               INTERRUPT_FEATURE_ENABLE
#define CCP1_INTERRUPT_FEATURE_ENABLE                               INTERRUPT_FEATURE_ENABLE
#define CCP2_INTERRUPT_FEATURE_ENABLE                               INTERRUPT_FEATURE_ENABLE

#endif /*MCAL_INTERRUPT_GEN_CONFIG_H*/