 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "Port.h"
#include "tm4c123gh6pm_registers.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"

/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Port_ConfigPin * Port_Pin_Config = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;
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
void Port_Init(const Port_ConfigType * ConfigPtr )
{
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_CONFIG);
	}
	else
    #endif 
	{
		Port_Pin_Config = ConfigPtr->pinsConf; /*Pointer to array of Structures */
	}
    Port_PinType pin_index=0;
    volatile uint32 * Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    volatile uint32 delay = 0;
    for(pin_index=0;pin_index<PORT_NUMBER_OF_PORT_PINS;pin_index++)
    {
        switch(Port_Pin_Config[pin_index].port_num)
        {
            case  PORTA_ID: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
            break;
            case  PORTB_ID: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
            break;
            case  PORTC_ID: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
            break;
            case  PORTD_ID: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
            break;
            case  PORTE_ID: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
            break;
            case  PORTF_ID: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
            break;
        }
    
    /* Enable clock for PORT and allow time for clock to start*/
        SYSCTL_REGCGC2_REG |= (1<<(Port_Pin_Config[pin_index].port_num));
        delay = SYSCTL_REGCGC2_REG;
    
        if( ((Port_Pin_Config[pin_index].port_num == PORTD_ID) &&(Port_Pin_Config[pin_index].port_num == PORTF_ID) && (Port_Pin_Config[pin_index].pin_num== PORT_PIN7_ID)) || ((Port_Pin_Config[pin_index].port_num == PORTF_ID) && (Port_Pin_Config[pin_index].pin_num == 0)) ) /* PD7 or PF0 */
        {
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */   
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET) , Port_Pin_Config[pin_index].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
        }
        else if( (Port_Pin_Config[pin_index].port_num== PORTC_ID) && (Port_Pin_Config[pin_index].pin_num<= PORT_PIN3_ID) ) /* PC0 to PC3 */
        {
            /* Do Nothing ...  this is the JTAG pins */
        }
        else
        {
            /* Do Nothing ... No need to unlock the commit register for this pin */
        }
        /*Checking for Direction*/
        /*Case we have an output pin*/
        if(PORT_PIN_OUT==Port_Pin_Config[pin_index].direction)
        {
               /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
            SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_DIR_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
        }
        /*case we have an input pin*/
        else 
        {
               /* clear the corresponding bit in the GPIODIR register to configure it as input pin */
            CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_DIR_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
        }
        /*Setting Initial value for output pins*/
        if(PORT_PIN_OUT==Port_Pin_Config[pin_index].direction)
        {

            if(STD_HIGH==Port_Pin_Config[pin_index].initial_value)
            {
                /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_DATA_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            }
            else
            {
                /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_DATA_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            }
        }
        else
        {
            /*Do nothing*/
        }
        /*Settings for internal resistance*/
        if(PORT_PIN_IN==Port_Pin_Config[pin_index].direction)
        {
            /*Case we have internal pull up resistance*/
            if(PULL_UP==Port_Pin_Config[pin_index].resistor)
            {
                /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_PULL_UP_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            }
            /*Case we have internal pull down resistance*/
            else if(PULL_DOWN==Port_Pin_Config[pin_index].resistor)
            {
                /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_PULL_DOWN_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            }
            /*Case we have Resistance network to be off*/
            else
            {
                /* clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_PULL_UP_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
                /* clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_PULL_DOWN_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            }
        }
        else 
        {
            /*DO Nothing*/
        }
        /*Case we have Pin mode for DIO*/
        if(PORT_PIN_MODE_DIO==Port_Pin_Config[pin_index].pin_mode)
        {
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_ANALOG_MODE_SEL_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_DIGITAL_ENABLE_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_ALT_FUNC_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            /* Clear the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pin_Config[pin_index].pin_num * 4));     /* Clear the PMCx bits for this pin */
        }
        else if(PORT_PIN_MODE_ANALOG==Port_Pin_Config[pin_index].pin_mode)
        {
            /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
            SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_ANALOG_MODE_SEL_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            /* clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
            CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_DIGITAL_ENABLE_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_ALT_FUNC_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            /* Clear the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pin_Config[pin_index].pin_num * 4));     /* Clear the PMCx bits for this pin */
        }
        /*Any other MODE (NOT ANALOG OR DIO)*/
        else
        {
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_ANALOG_MODE_SEL_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_DIGITAL_ENABLE_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            /* Enable Alternative function for this pin by Setting the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32*)((volatile uint8*)Port_Ptr+PORT_ALT_FUNC_REG_OFFSET),Port_Pin_Config[pin_index].pin_num);
            /* Clear the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pin_Config[pin_index].pin_num * 4));    
            /*SETs the PMCx Bits for the specific mode*/ 
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (Port_Pin_Config[pin_index].pin_mode << (Port_Pin_Config[pin_index].pin_num * 4));     
        }
            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
    }
     /*Set the module state to initialized*/
    Port_Status= PORT_INITIALIZED;
}