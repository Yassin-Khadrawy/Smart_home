/* 
 * File:   mcal_internal_interrupt.h
 * Author: KimoStore
 *
 * Created on October 10, 2024, 9:40 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

// section : includes

#include "config_interrupts.h"
// macros declarations


// macros functions declarations
#if ADC_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine clears the interrupt enable for the ADC module*/
#define ADC_InterruptEnable()             (PIE1bits.ADIE = 1)
/* this routine sets the interrupt enable for the ADC module*/
#define ADC_InterruptDisable()            (PIE1bits.ADIE = 0)
/* this routine clear the interrupt flag for the ADC module*/
#define ADC_InterruptFlagClear()          (PIR1bits.ADIF = 0)

#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine sets the edge detect of the ADC module to HIGH priority*/
#define ADC_HighPrioritySet()             (IPR1bits.ADIP = 1)
/* this routine sets the edge detect of the ADC module to LOW priority*/
#define ADC_LowPrioritySet()              (IPR1bits.ADIP = 0)
#endif
#endif


#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine clears the interrupt enable for the TIMER0 module*/
#define TIMER0_InterruptEnable()             (INTCONbits.TMR0IE = 1)
/* this routine sets the interrupt enable for the TIMER0 module*/
#define TIMER0_InterruptDisable()            (INTCONbits.TMR0IE = 0)
/* this routine clear the interrupt flag for the TIMER0 module*/
#define TIMER0_InterruptFlagClear()          (INTCONbits.TMR0IF = 0)

#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine sets the edge detect of the TIMER0 module to HIGH priority*/
#define TIMER0_HighPrioritySet()             (INTCON2bits.TMR0IP = 1)
/* this routine sets the edge detect of the TIMER0 module to LOW priority*/
#define TIMER0_LowPrioritySet()              (INTCON2bits.TMR0IP = 0)

#endif
#endif


#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine clears the interrupt enable for the TIMER1 module*/
#define TIMER1_InterruptEnable()             (PIE1bits.TMR1IE = 1)
/* this routine sets the interrupt enable for the TIMER1 module*/
#define TIMER1_InterruptDisable()            (PIE1bits.TMR1IE = 0)
/* this routine clear the interrupt flag for the TIMER1 module*/
#define TIMER1_InterruptFlagClear()          (PIR1bits.TMR1IF = 0)

#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine sets the edge detect of the TIMER1 module to HIGH priority*/
#define TIMER1_HighPrioritySet()             (IPR1bits.TMR1IP = 1)
/* this routine sets the edge detect of the TIMER1 module to LOW priority*/
#define TIMER1_LowPrioritySet()              (IPR1bits.TMR1IP = 0)

#endif
#endif



#if TIMER2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine clears the interrupt enable for the TIMER2 module*/
#define TIMER2_InterruptEnable()             (PIE1bits.TMR2IE = 1)
/* this routine sets the interrupt enable for the TIMER2 module*/
#define TIMER2_InterruptDisable()            (PIE1bits.TMR2IE = 0)
/* this routine clear the interrupt flag for the TIMER2 module*/
#define TIMER2_InterruptFlagClear()          (PIR1bits.TMR2IF = 0)

#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine sets the edge detect of the TIMER2 module to HIGH priority*/
#define TIMER2_HighPrioritySet()             (IPR1bits.TMR2IP = 1)
/* this routine sets the edge detect of the TIMER2 module to LOW priority*/
#define TIMER2_LowPrioritySet()              (IPR1bits.TMR2IP = 0)

#endif
#endif

#if TIMER3_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine clears the interrupt enable for the TIMER3 module*/
#define TIMER3_InterruptEnable()             (PIE2bits.TMR3IE = 1)
/* this routine sets the interrupt enable for the TIMER3 module*/
#define TIMER3_InterruptDisable()            (PIE2bits.TMR3IE = 0)
/* this routine clear the interrupt flag for the TIMER3 module*/
#define TIMER3_InterruptFlagClear()          (PIR2bits.TMR3IF = 0)

#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine sets the edge detect of the TIMER3 module to HIGH priority*/
#define TIMER3_HighPrioritySet()             (IPR2bits.TMR3IP = 1)
/* this routine sets the edge detect of the TIMER3 module to LOW priority*/
#define TIMER3_LowPrioritySet()              (IPR2bits.TMR3IP = 0)

#endif
#endif



#if EUSART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine clears the interrupt enable for the ADC module*/
#define EUSART_TX_InterruptEnable()             (PIE1bits.TXIE = 1)
/* this routine sets the interrupt enable for the ADC module*/
#define EUSART_TX_InterruptDisable()            (PIE1bits.TXIE = 0)

#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine sets the edge detect of the ADC module to HIGH priority*/
#define EUSART_TX_HighPrioritySet()             (IPR1bits.TXIP = 1)
/* this routine sets the edge detect of the ADC module to LOW priority*/
#define EUSART_TX_LowPrioritySet()              (IPR1bits.TXIP = 0)
#endif
#endif

#if EUSART_RX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine clears the interrupt enable for the ADC module*/
#define EUSART_RX_InterruptEnable()             (PIE1bits.RCIE = 1)
/* this routine sets the interrupt enable for the ADC module*/
#define EUSART_RX_InterruptDisable()            (PIE1bits.RCIE = 0)
  
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine sets the edge detect of the ADC module to HIGH priority*/
#define EUSART_RX_HighPrioritySet()             (IPR1bits.RCIP = 1)
/* this routine sets the edge detect of the ADC module to LOW priority*/
#define EUSART_RX_LowPrioritySet()              (IPR1bits.ADIP = 0)
#endif
#endif

#if MSSP_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine clears the interrupt enable for the MSSP module*/
#define MSSP_InterruptEnable()             (PIE1bits.SSPIE = 1)
/* this routine sets the interrupt enable for the MSSP module*/
#define MSSP_InterruptDisable()            (PIE1bits.SSPIE = 0)
/* this routine clear the interrupt flag for the MSSP module*/
#define MSSP_InterruptFlagClear()          (PIR1bits.SSPIF = 0)
/* this routine clears the interrupt enable for the BUS_COLLISION module*/
#define BUS_COLLISION_InterruptEnable()    (PIE2bits.BCLIE = 1)
/* this routine sets the interrupt enable for the BUS_COLLISION module*/
#define BUS_COLLISION_InterruptDisable()   (PIE2bits.BCLIE = 0)
/* this routine clear the interrupt flag for the BUS_COLLISION module*/
#define BUS_COLLISION_InterruptFlagClear() (PIR2bits.BCLIF = 0)
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine sets the edge detect of the TIMER3 module to HIGH priority*/
#define MSSP_HighPrioritySet()             (IPR1bits.SSPIP = 1)
/* this routine sets the edge detect of the TIMER3 module to LOW priority*/
#define MSSP_LowPrioritySet()              (IPR1bits.SSPIP = 0)
/* this routine sets the edge detect of the BUS_COLLISION module to HIGH priority*/
#define BUS_COLLISION_HighPrioritySet()     (IPR2bits.BCLIP = 1)
/* this routine sets the edge detect of the BUS_COLLISION module to LOW priority*/
#define BUS_COLLISION_LowPrioritySet()      (IPR2bits.BCLIP = 0)

#endif
#endif


#if SPI_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine clears the interrupt enable for the SPI module*/
#define SPI_InterruptEnable()             (PIE1bits.SSPIE = 1)
/* this routine sets the interrupt enable for the SPI module*/
#define SPI_InterruptDisable()            (PIE1bits.SSPIE = 0)
/* this routine clear the interrupt flag for the SPI module*/
#define SPI_InterruptFlagClear()          (PIR1bits.SSPIF = 0)
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine sets the edge detect of the SPI module to HIGH priority*/
#define SPI_HighPrioritySet()             (IPR1bits.SSPIP = 1)
/* this routine sets the edge detect of the SPI module to LOW priority*/
#define SPI_LowPrioritySet()              (IPR1bits.SSPIP = 0)

#endif
#endif

#if CCP1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine clears the interrupt enable for the CCP1 module*/
#define CCP1_InterruptEnable()             (PIE1bits.CCP1IE = 1)
/* this routine sets the interrupt enable for the CCP1 module*/
#define CCP1_InterruptDisable()            (PIE1bits.CCP1IE = 0)
/* this routine clear the interrupt flag for the CCP1 module*/
#define CCP1_InterruptFlagClear()          (PIR1bits.CCP1IF = 0)
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine sets the edge detect of the CCP1 module to HIGH priority*/
#define CCP1_HighPrioritySet()             (IPR1bits.CCP1IP = 1)
/* this routine sets the edge detect of the CCP1 module to LOW priority*/
#define CCP1_LowPrioritySet()              (IPR1bits.CCP1IP = 0)

#endif
#endif

#if CCP2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine clears the interrupt enable for the CCP2 module*/
#define CCP2_InterruptEnable()             (PIE2bits.CCP2IE = 1)
/* this routine sets the interrupt enable for the CCP2 module*/
#define CCP2_InterruptDisable()            (PIE2bits.CCP2IE = 0)
/* this routine clear the interrupt flag for the CCP2 module*/
#define CCP2_InterruptFlagClear()          (PIR2bits.CCP2IF = 0)
#if INTERRUPT_PRIORITY_LEVEL_ENABLE == INTERRUPT_FEATURE_ENABLE

/* this routine sets the edge detect of the CCP2 module to HIGH priority*/
#define CCP2_HighPrioritySet()             (IPR2bits.CCP2IP = 1)
/* this routine sets the edge detect of the CCP2 module to LOW priority*/
#define CCP2_LowPrioritySet()              (IPR2bits.CCP2IP = 0)

#endif
#endif
// data type declarations

typedef void(*InterruptHandler)(void);
// function declarations

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

