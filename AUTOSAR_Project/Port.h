 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Hazem Hisham
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H
/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* PORT Module Id */
#define PORT_MODULE_ID    (124U)

/* PORT Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for PORT Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/*******************************************************************************
 *                              Module Inclusions                              *
 *******************************************************************************/
/* Standard AUTOSAR types */
#include "Std_Types.h"
/*#include "Port_Regs.h"*/

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif
/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Dio_Cfg.h and Dio.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/*Service id for Port init*/
#define PORT_INIT_SID                           (uint8) 0x00
/*Service id for PORT set pin direction*/
#define PORT_SET_PIN_DIRECTION_SID              (uint8) 0x01
/*Service id for PORT refresh port direction*/
#define PORT_REFRESH_PORT_DIRECTION_SID         (uint8) 0X02
/*Service id for PORT get version info*/
#define PORT_GET_VERSION_INFO_SID               (uint8) 0x03
/*Service id for port set pin mode*/
#define PORT_SET_PIN_MODE_SID                   (uint8) 0x04
/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/*DET error to report invalid Port pin id requested*/
#define PORT_E_PARAM_PIN                        (uint8) 0x0A
/*DET error to report Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE           (uint8) 0x0B
/*DET error to report API Port_Init service with wrong parameters*/
#define PORT_E_PARAM_CONFIG                     (uint8) 0x0C
/*DET error to report Port Pin Mode passed not valid on calling API Port_SetPinMode service*/
#define PORT_E_PARAM_INVALID_MODE               (uint8) 0x0D
/*DET error to report API Port_SetPinMode service called when mode is unchangeable*/
#define PORT_E_MODE_UNCHANGEABLE                (uint8) 0x0E
/*DET error to report API Service Called without module Initialization*/
#define PORT_E_UNINIT                           (uint8) 0x0F
/*DET error to report APIS called with a Null Pointer*/
#define PORT_E_PARAM_POINTER                    (uint8) 0x10
 
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************

/********************************************************************************
*Name: Port_PinType                                                             *            
*Type: uint                                                                     *
*0 - <number of port pins:>                                                     *
*Range: Shall cover all available port pins.                                    *
*Description: Data type for the symbolic name of a port pin.                    *                       
*********************************************************************************/
typedef uint8 Port_PinType;

/********************************************************************************
*Name: Port_PinDirectionType 
Type: Enumeration 
Range: PORT_PIN_IN Sets port pin as input. 
PORT_PIN_OUT Sets port pin as output. 
Description: Possible directions of a port pin.                                        
*********************************************************************************/
typedef enum
{
    PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;
/********************************************************************************
*Name: Changeability
Type: Enumeration 
Range: UNCHANGEABLE Sets PIN UNCHANGEABLE MODE OR DIR. 
CHANGEABLE Sets port pin as CHANGEABLE MODE OR DIR. 
Justification for Adding this enumeration: For readability in Port_PBcfg.h file
in configuration strucutre                                       
*********************************************************************************/
typedef enum
{
  UNCHANGEABLE,CHANGEABLE
}Changeability;
/********************************************************************************
*Name: Port_PinModeType                                                         *            
*Type: uint                                                                     *
*Range:Covers Target Modes                                                      *                                        
*Description: Description: Different port pin modes.                            *                       
*********************************************************************************/
typedef uint8 Port_PinModeType;
/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/* Description: Structure to configure each individual PIN:
 *  1. the number of the pin in the PORT.
 *	2. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *  3. the direction of pin --> INPUT or OUTPUT
 *  4. the internal resistor --> Disable, Pull up or Pull down
 *  5.The initial Value 
 *  6.Pin Mode
 *  7.pin direction changeable flag
 *  8.pin mode changeable flag
 */
typedef struct 
{
    Port_PinType pin_num;
    uint8 port_num;  
    Port_PinDirectionType direction;
    Port_InternalResistor resistor;
    uint8 initial_value;
    Port_PinModeType pin_mode;
    boolean pin_direction_changeable;
    boolean pin_mode_changeable;
}Port_ConfigPin;

/* Data Structure required for initializing the Port Driver */
typedef struct Port_ConfigType
{
	Port_ConfigPin pinsConf[PORT_NUMBER_OF_PORT_PINS];
}Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
Service name: Port_Init  
Service ID[hex]: 0x00 
Sync/Async: Synchronous 
Reentrancy: Non Reentrant 
Parameters (in): ConfigPtr Pointer to configuration set. 
Parameters (inout): None 
Parameters (out): None 
Return value: None 
Description: Initializes the Port Driver module
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr );


/************************************************************************************
Service ID[hex]: 0x01 
Sync/Async: Synchronous 
Reentrancy: Reentrant 
Parameters (in): Pin       - Port Pin ID number
                Direction - Port Pin Direction
Parameters(inout): None 
Parameters (out): None 
Return value: None 
Description: Sets the port pin direction
************************************************************************************/
#if(PORT_SET_PIN_DIRECTION_API==STD_ON)
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);

#endif
/************************************************************************************
Service name: Port_RefreshPortDirection 
Service ID[hex]: 0x02 
Sync/Async: Synchronous 
Reentrancy: Non Reentrant 
Parameters (in): None 
Parameters (inout): None 
Parameters (out): None 
Return value: None 
Description: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection(void);

#if(PORT_VERSION_INFO_API==STD_ON)
/*******************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version info
* Return value: None
* Description: Returns the version information of this module
********************************************************************************/
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);

#endif

/*******************************************************************************
* Service Name: Port_SetPinMode
* Service ID[HEX]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin  - Port Pin ID number
*                  Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode
********************************************************************************/
#if(PORT_SET_PIN_MODE_API==STD_ON)
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode) ;
#endif
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;
#endif /* PORT_H */
