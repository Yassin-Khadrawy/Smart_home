#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/SMART_MASTER.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/SMART_MASTER.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_layer/24C01C/ecu_24C01C.c ECU_layer/button/ecu_button.c ECU_layer/motor_dc/ecu_motor_dc.c ECU_layer/DS1307/ecu_DS1307.c ECU_layer/keypad/ecu__keypad.c ECU_layer/LCD_NEW/ecu_lcd_new_.c ECU_layer/LED/ecu_led.c ECU_layer/relay/ecu_relay.c ECU_layer/seven_segment/ecu_seven_segment.c ECU_layer/TC74/ecu_TC74.c ECU_layer/ecu_layer_init.c MCAL_layer/ADC/hal_adc.c MCAL_layer/CCP1/hal_ccp1.c MCAL_layer/GPIO/hal_gpio.c MCAL_layer/hal_EEPROM/eeprom.c MCAL_layer/I2C/hal_i2c.c MCAL_layer/interrupts/external_interrupts.c MCAL_layer/interrupts/internal_interrupts.c MCAL_layer/interrupts/manager_interrupts.c MCAL_layer/Timer0/Mcal_timer0.c MCAL_layer/Timer1/hal_timer1.c MCAL_layer/Timer2/hal_timer2.c MCAL_layer/Timer3/hal_timer3.c MCAL_layer/USART/mcal_usart.c MCAL_layer/device_config.c MCAL_layer/mcal_layer_init.c application.c ECU_layer/LDR/ecu_ldr.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1 ${OBJECTDIR}/ECU_layer/button/ecu_button.p1 ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1 ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1 ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1 ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1 ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1 ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1 ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1 ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1 ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1 ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1 ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1 ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1 ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1 ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1 ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1 ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1 ${OBJECTDIR}/MCAL_layer/device_config.p1 ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1.d ${OBJECTDIR}/ECU_layer/button/ecu_button.p1.d ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1.d ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1.d ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1.d ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1.d ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1.d ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1.d ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1.d ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1.d ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1.d ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1.d ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1.d ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1.d ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1.d ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1.d ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1.d ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1.d ${OBJECTDIR}/application.p1.d ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1 ${OBJECTDIR}/ECU_layer/button/ecu_button.p1 ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1 ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1 ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1 ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1 ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1 ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1 ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1 ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1 ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1 ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1 ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1 ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1 ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1 ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1 ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1 ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1 ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1 ${OBJECTDIR}/MCAL_layer/device_config.p1 ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1

# Source Files
SOURCEFILES=ECU_layer/24C01C/ecu_24C01C.c ECU_layer/button/ecu_button.c ECU_layer/motor_dc/ecu_motor_dc.c ECU_layer/DS1307/ecu_DS1307.c ECU_layer/keypad/ecu__keypad.c ECU_layer/LCD_NEW/ecu_lcd_new_.c ECU_layer/LED/ecu_led.c ECU_layer/relay/ecu_relay.c ECU_layer/seven_segment/ecu_seven_segment.c ECU_layer/TC74/ecu_TC74.c ECU_layer/ecu_layer_init.c MCAL_layer/ADC/hal_adc.c MCAL_layer/CCP1/hal_ccp1.c MCAL_layer/GPIO/hal_gpio.c MCAL_layer/hal_EEPROM/eeprom.c MCAL_layer/I2C/hal_i2c.c MCAL_layer/interrupts/external_interrupts.c MCAL_layer/interrupts/internal_interrupts.c MCAL_layer/interrupts/manager_interrupts.c MCAL_layer/Timer0/Mcal_timer0.c MCAL_layer/Timer1/hal_timer1.c MCAL_layer/Timer2/hal_timer2.c MCAL_layer/Timer3/hal_timer3.c MCAL_layer/USART/mcal_usart.c MCAL_layer/device_config.c MCAL_layer/mcal_layer_init.c application.c ECU_layer/LDR/ecu_ldr.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/SMART_MASTER.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1: ECU_layer/24C01C/ecu_24C01C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/24C01C" 
	@${RM} ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1 ECU_layer/24C01C/ecu_24C01C.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.d ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/button/ecu_button.p1: ECU_layer/button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/button" 
	@${RM} ${OBJECTDIR}/ECU_layer/button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/button/ecu_button.p1 ECU_layer/button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/button/ecu_button.d ${OBJECTDIR}/ECU_layer/button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1: ECU_layer/motor_dc/ecu_motor_dc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/motor_dc" 
	@${RM} ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1 ECU_layer/motor_dc/ecu_motor_dc.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.d ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1: ECU_layer/DS1307/ecu_DS1307.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/DS1307" 
	@${RM} ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1 ECU_layer/DS1307/ecu_DS1307.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.d ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1: ECU_layer/keypad/ecu__keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/keypad" 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1 ECU_layer/keypad/ecu__keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.d ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1: ECU_layer/LCD_NEW/ecu_lcd_new_.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LCD_NEW" 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1 ECU_layer/LCD_NEW/ecu_lcd_new_.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.d ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LED/ecu_led.p1: ECU_layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ECU_layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LED/ecu_led.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1: ECU_layer/relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/relay" 
	@${RM} ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1 ECU_layer/relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/relay/ecu_relay.d ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1: ECU_layer/seven_segment/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 ECU_layer/seven_segment/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.d ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1: ECU_layer/TC74/ecu_TC74.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/TC74" 
	@${RM} ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1 ECU_layer/TC74/ecu_TC74.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.d ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/ecu_layer_init.p1: ECU_layer/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer" 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 ECU_layer/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/ecu_layer_init.d ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1: MCAL_layer/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1 MCAL_layer/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.d ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1: MCAL_layer/CCP1/hal_ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 MCAL_layer/CCP1/hal_ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.d ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1: MCAL_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 MCAL_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1: MCAL_layer/hal_EEPROM/eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/hal_EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1 MCAL_layer/hal_EEPROM/eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.d ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1: MCAL_layer/I2C/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1 MCAL_layer/I2C/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.d ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1: MCAL_layer/interrupts/external_interrupts.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1 MCAL_layer/interrupts/external_interrupts.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.d ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1: MCAL_layer/interrupts/internal_interrupts.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1 MCAL_layer/interrupts/internal_interrupts.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.d ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1: MCAL_layer/interrupts/manager_interrupts.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1 MCAL_layer/interrupts/manager_interrupts.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.d ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1: MCAL_layer/Timer0/Mcal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1 MCAL_layer/Timer0/Mcal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.d ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1: MCAL_layer/Timer1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1 MCAL_layer/Timer1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.d ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1: MCAL_layer/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1 MCAL_layer/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.d ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1: MCAL_layer/Timer3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1 MCAL_layer/Timer3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.d ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1: MCAL_layer/USART/mcal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1 MCAL_layer/USART/mcal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.d ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/device_config.p1: MCAL_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/device_config.p1 MCAL_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/device_config.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1: MCAL_layer/mcal_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1 MCAL_layer/mcal_layer_init.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/mcal_layer_init.d ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1: ECU_layer/LDR/ecu_ldr.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LDR" 
	@${RM} ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1 ECU_layer/LDR/ecu_ldr.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.d ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1: ECU_layer/24C01C/ecu_24C01C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/24C01C" 
	@${RM} ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1 ECU_layer/24C01C/ecu_24C01C.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.d ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/24C01C/ecu_24C01C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/button/ecu_button.p1: ECU_layer/button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/button" 
	@${RM} ${OBJECTDIR}/ECU_layer/button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/button/ecu_button.p1 ECU_layer/button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/button/ecu_button.d ${OBJECTDIR}/ECU_layer/button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1: ECU_layer/motor_dc/ecu_motor_dc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/motor_dc" 
	@${RM} ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1 ECU_layer/motor_dc/ecu_motor_dc.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.d ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/motor_dc/ecu_motor_dc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1: ECU_layer/DS1307/ecu_DS1307.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/DS1307" 
	@${RM} ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1 ECU_layer/DS1307/ecu_DS1307.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.d ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/DS1307/ecu_DS1307.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1: ECU_layer/keypad/ecu__keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/keypad" 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1 ECU_layer/keypad/ecu__keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.d ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/keypad/ecu__keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1: ECU_layer/LCD_NEW/ecu_lcd_new_.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LCD_NEW" 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1 ECU_layer/LCD_NEW/ecu_lcd_new_.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.d ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LCD_NEW/ecu_lcd_new_.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LED/ecu_led.p1: ECU_layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1 ECU_layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LED/ecu_led.d ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1: ECU_layer/relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/relay" 
	@${RM} ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1 ECU_layer/relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/relay/ecu_relay.d ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1: ECU_layer/seven_segment/ecu_seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1 ECU_layer/seven_segment/ecu_seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.d ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/seven_segment/ecu_seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1: ECU_layer/TC74/ecu_TC74.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/TC74" 
	@${RM} ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1 ECU_layer/TC74/ecu_TC74.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.d ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/TC74/ecu_TC74.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/ecu_layer_init.p1: ECU_layer/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer" 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1 ECU_layer/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/ecu_layer_init.d ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1: MCAL_layer/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1 MCAL_layer/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.d ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1: MCAL_layer/CCP1/hal_ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1 MCAL_layer/CCP1/hal_ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.d ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/CCP1/hal_ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1: MCAL_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1 MCAL_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1: MCAL_layer/hal_EEPROM/eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/hal_EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1 MCAL_layer/hal_EEPROM/eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.d ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/hal_EEPROM/eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1: MCAL_layer/I2C/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1 MCAL_layer/I2C/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.d ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/I2C/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1: MCAL_layer/interrupts/external_interrupts.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1 MCAL_layer/interrupts/external_interrupts.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.d ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupts/external_interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1: MCAL_layer/interrupts/internal_interrupts.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1 MCAL_layer/interrupts/internal_interrupts.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.d ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupts/internal_interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1: MCAL_layer/interrupts/manager_interrupts.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1 MCAL_layer/interrupts/manager_interrupts.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.d ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/interrupts/manager_interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1: MCAL_layer/Timer0/Mcal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1 MCAL_layer/Timer0/Mcal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.d ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer0/Mcal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1: MCAL_layer/Timer1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1 MCAL_layer/Timer1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.d ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1: MCAL_layer/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1 MCAL_layer/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.d ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1: MCAL_layer/Timer3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1 MCAL_layer/Timer3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.d ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Timer3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1: MCAL_layer/USART/mcal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/USART" 
	@${RM} ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1 MCAL_layer/USART/mcal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.d ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/USART/mcal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/device_config.p1: MCAL_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/device_config.p1 MCAL_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/device_config.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1: MCAL_layer/mcal_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1 MCAL_layer/mcal_layer_init.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/mcal_layer_init.d ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/mcal_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1: ECU_layer/LDR/ecu_ldr.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LDR" 
	@${RM} ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1 ECU_layer/LDR/ecu_ldr.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.d ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LDR/ecu_ldr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/SMART_MASTER.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/SMART_MASTER.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/SMART_MASTER.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/SMART_MASTER.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/SMART_MASTER.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/SMART_MASTER.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/SMART_MASTER.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
