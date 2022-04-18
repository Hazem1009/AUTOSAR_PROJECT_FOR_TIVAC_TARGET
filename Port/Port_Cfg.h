/******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Dio_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - PORT Driver
 *
 * Author: Hazem Hisham
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)
/*Pre-processor switch to enable / disable the use of the function Port_SetPinDirection()*/
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)
/*Pre-processor switch to enable / disable the use of the function Port_SetPinMode()*/
#define PORT_SET_PIN_MODE_API                (STD_ON)
/*Pre-processor switch to enable / disable the API to read out the modules version information*/
#define PORT_VERSION_INFO_API                (STD_ON)
/*Number of Target MC pins*/
#define PORT_NUMBER_OF_PORT_PINS             (43U)
/*Number of Modes for Target MC*/
#define PORT_NUMBER_OF_PINS_MODES
/****************************Port IDS************************/
#define PORTA_ID                             (0U)
#define PORTB_ID                             (1U)
#define PORTC_ID                             (2U)
#define PORTD_ID                             (3U)
#define PORTE_ID                             (4U)
#define PORTF_ID                             (5U)
/******************************General Pin numbers************/
#define PORT_PIN0_ID                              (0U)
#define PORT_PIN1_ID                              (1U)
#define PORT_PIN2_ID                              (2U)
#define PORT_PIN3_ID                              (3U)
#define PORT_PIN4_ID                              (4U)
#define PORT_PIN5_ID                              (5U)
#define PORT_PIN6_ID                              (6U)
#define PORT_PIN7_ID                               (7U)
 
/*************************MODES FOR EACH PIN****** ************/
 
/*************************START OF PORTA PINS MODES**************/
#define PORT_PIN_MODE_DIO                          (0U)
#define PORT_PIN_MODE_ANALOG                       (15U)
/*PA0 modes*/ 
#define PORT_PA0_MODE_U0Rx                         (1U)
#define PORT_PA0_MODE_CAN1Rx                       (8U)
/*PA1 modes*/ 
#define PORT_PA1_MODE_U0Tx                         (1U)
#define PORT_PA1_MODE_CAN1Tx                       (8U)
/*PA2 modes*/ 
#define PORT_PA2_MODE_SSI0Clk                      (2U)
/*PA3 modes*/ 
#define PORT_PA3_MODE_SSI0Fss                      (2U)
/*PA4 modes*/ 
#define PORT_PA4_MODE_SSI0Rx                       (2U)
/*PA5 modes*/ 
#define PORT_PA5_MODE_SSI0Tx                       (2U)
/*PA6 modes*/ 
#define PORT_PA6_MODE_I2C1SCL                      (3U)
#define PORT_PA6_MODE_M1PWM2                       (5U)
/*PA7 modes*/ 
#define PORT_PA7_MODE_I2C1SDA                      (3U)
#define PORT_PA7_MODE_M1PWM3                       (5U)
/**************************END OF PORT A PINS MODE S************************/
/**************************Start of PORT B PINS MO DES**********************/
/*PB0 modes*/
//#define PORT_PB0_MODE_USB0ID() /*To be removed*/
#define PORT_PB0_MODE_U1RX                          (1U)
#define PORT_PB0_MODE_T2CCP0                        (7U)                            
/*PB1 modes*/
#define PORT_PB1_MODE_U1TX                          (1U)
#define PORT_PB1_MODE_T2CCP1                        (7U)   
/*PB2 modes*/
#define PORT_PB2_MODE_I2C0SCL                       (3U)
#define PORT_PB2_MODE_T3CCP0                        (7U)  
/*PB3 modes*/
#define PORT_PB3_MODE_I2C0SDA                       (3U)
#define PORT_PB3_MODE_T3CCP1                        (7U)
/*PB4 modes*/
#define PORT_PB4_MODE_SSI2Clk                       (2U)
#define PORT_PB4_MODE_M0PWM2                        (4U)
#define PORT_PB4_MODE_T1CCP0                        (7U)
#define PORT_PB4_MODE_CAN0RX                        (8U)
/*PB5 modes*/
#define PORT_PB5_MODE_SSI2Fss                       (2U)
#define PORT_PB5_MODE_M0PWM3                        (4U)
#define PORT_PB5_MODE_T1CCP0                        (7U)
#define PORT_PB5_MODE_CAN0TX                        (8U)
/*PB6 modes*/
#define PORT_PB6_MODE_SSI2RX                        (2U)
#define PORT_PB6_MODE_M0PWM0                        (4U)
#define PORT_PB6_MODE_T0CCP0                        (7U)
/*PB7 modes*/
#define PORT_PB7_MODE_SSI2TX                        (2U)
#define PORT_PB7_MODE_M0PWM1                        (4U)
#define PORT_PB7_MODE_T0CCP1                        (7U)
/********************End of PORT B PIN MODES*****************/
/********************Start of PORT C PIN MODES***************/
/*PC4 modes*/
#define PORT_PC4_MODE_U4Rx                   (1U)
#define PORT_PC4_MODE_U1Rx                   (2U)
#define PORT_PC4_MODE_M0PWM6                 (4U)
#define PORT_PC4_MODE_IDX1                   (6U)
#define PORT_PC4_MODE_WT0CCP0                (7U)
#define PORT_PC4_MODE_U1RTS                  (8U)
/*PC5 modes*/
#define PORT_PC5_MODE_U4Tx                   (1U)
#define PORT_PC5_MODE_U1Tx                   (2U)
#define PORT_PC5_MODE_M0PWM7                 (4U)
#define PORT_PC5_MODE_PhA1                   (6U)
#define PORT_PC5_MODE_WT0CCP1                (7U)
#define PORT_PC5_MODE_U1CTS                  (8U)
/*PC6 modes*/
#define PORT_PC6_MODE_U3Rx                   (1U)
#define PORT_PC6_MODE_PhB1                   (6U)
#define PORT_PC6_MODE_WT1CCP0                (7U)
#define PORT_PC6_MODE_USB0epen               (8U)
/*PC7 modes*/
#define PORT_PC7_MODE_U3Tx                   (1U)
#define PORT_PC7_MODE_WT1CCP1                (7U)
#define PORT_PC7_MODE_USB0pflt               (8U)
/***************End of PORT C PIN MODES*******************/
/***************Start of PORT D PING MODES****************/
/* PD0 Modes */
#define PORT_PD0_MODE_SSI3Clk                (1U)
#define PORT_PD0_MODE_SSI1Clk                (2U)
#define PORT_PD0_MODE_I2C3SCL                (3U)
#define PORT_PD0_MODE_M0PWM6                 (4U)
#define PORT_PD0_MODE_M1PWM0                 (5U)
#define PORT_PD0_MODE_WT2CCP0                (7U)
/* PD1 Modes */
#define PORT_PD1_MODE_SSI3Fss                (1U)
#define PORT_PD1_MODE_SSI1Fss                (2U)
#define PORT_PD1_MODE_I2C3SDA                (3U)
#define PORT_PD1_MODE_M0PWM7                 (4U)
#define PORT_PD1_MODE_M1PWM1                 (5U)
#define PORT_PD1_MODE_WT2CCP1                (7U)
/* PD2 Modes */
#define PORT_PD2_MODE_SSI3Rx                 (1U)
#define PORT_PD2_MODE_SSI1Rx                 (2U)
#define PORT_PD2_MODE_M0FAULT0               (4U)
#define PORT_PD2_MODE_WT3CCP0                (7U)
#define PORT_PD2_MODE_USB0EPEN               (8U)
/* PD3 Modes */
#define PORT_PD3_MODE_SSI3Tx                 (1U)
#define PORT_PD3_MODE_SSI1Tx                 (2U)
#define PORT_PD3_MODE_IDX0                   (6U)
#define PORT_PD3_MODE_WT3CCP1                (7U)
#define PORT_PD3_MODE_USB0PFLT               (8U)
/* PD4 Modes */
#define PORT_PD4_MODE_U6Rx                   (1U)
#define PORT_PD4_MODE_WT4CCP0                (7U)
/* PD5 Modes */
#define PORT_PD5_MODE_U6Tx                   (1U)
#define PORT_PD5_MODE_WT4CCP1                (7U)
/* PD6 Modes */
#define PORT_PD6_MODE_U2Rx                   (1U)
#define PORT_PD6_MODE_M0FAULT0               (4U)
#define PORT_PD6_MODE_PhA0                   (6U)
#define PORT_PD6_MODE_WT5CCP0                (7U)
/* PD7 Modes */
#define PORT_PD7_MODE_U2Tx                   (1U)
#define PORT_PD7_MODE_PhB0                   (6U)
#define PORT_PD7_MODE_WT5CCP1                (7U)
#define PORT_PD7_MODE_NMI                    (8U)
/***********************End of PORTD PIN MODES****************************/
/***********************Start of PORT E PIN MODES*************************/
/* PE0 Modes */
#define PORT_PE0_MODE_U7Rx                   (1U)
/* PE1 Modes */
#define PORT_PE1_MODE_U7Tx                   (1U)
/* PE4 Modes */
#define PORT_PE4_MODE_U5Rx                   (1U)
#define PORT_PE4_MODE_I2C2SCL                (3U)
#define PORT_PE4_MODE_M0PWM4                 (4U)
#define PORT_PE4_MODE_M1PWM2                 (5U)
#define PORT_PE4_MODE_CAN0Rx                 (8U)
/* PE5 Modes */
#define PORT_PE5_MODE_U5Tx                   (1U)
#define PORT_PE5_MODE_I2C2SDA                (3U)
#define PORT_PE5_MODE_M0PWM5                 (4U)
#define PORT_PE5_MODE_M1PWM3                 (5U)
#define PORT_PE5_MODE_CAN0Tx                 (8U)
/***********************END of PORT E PIN MODES*************************/
/***********************Start of PORT F PIN MODES*************************/
/* PF0 Modes */
#define PORT_PF0_MODE_U1RTS                  (1U)
#define PORT_PF0_MODE_SSI1Rx                 (2U)
#define PORT_PF0_MODE_CAN0Rx                 (3U)
#define PORT_PF0_MODE_M1PWM4                 (5U)
#define PORT_PF0_MODE_PhA0                   (6U)
#define PORT_PF0_MODE_T0CCP0                 (7U)
#define PORT_PF0_MODE_NMI                    (8U)
#define PORT_PF0_MODE_C0o                    (9U)
/* PF1 Modes */
#define PORT_PF1_MODE_U1CTS                  (1U)
#define PORT_PF1_MODE_SSI1Tx                 (2U)
#define PORT_PF1_MODE_M1PWM5                 (5U)
#define PORT_PF1_MODE_PhB0                   (6U)
#define PORT_PF1_MODE_T0CCP1                 (7U)
#define PORT_PF1_MODE_C1o                    (9U)
#define PORT_PF1_MODE_TRD1                   (14U)
/* PF2 Modes */
#define PORT_PF2_MODE_SSI1Clk                (2U)
#define PORT_PF2_MODE_M0FAULT0               (4U)
#define PORT_PF2_MODE_M1PWM6                 (5U)
#define PORT_PF2_MODE_T1CCP0                 (7U)
#define PORT_PF2_MODE_TRD0                   (14U)
/* PF3 Modes */
#define PORT_PF3_MODE_SSI1Fss                (2U)
#define PORT_PF3_MODE_CAN0Tx                 (3U)
#define PORT_PF3_MODE_M1PWM7                 (5U)
#define PORT_PF3_MODE_T1CCP1                 (7U)
#define PORT_PF3_MODE_TRCLK                  (14U)
/* PF4 Modes */
#define PORT_PF4_MODE_M1FAULT0               (5U)
#define PORT_PF4_MODE_IDX0                   (6U)
#define PORT_PF4_MODE_T2CCP0                 (7U)
#define PORT_PF4_MODE_USB0EPEN               (8U)
/*************************End of ALL PORT PIN MODES*************************/
#endif