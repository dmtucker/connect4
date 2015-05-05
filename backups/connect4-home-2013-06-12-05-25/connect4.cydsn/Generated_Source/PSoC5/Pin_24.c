/*******************************************************************************
* File Name: Pin_24.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Pin_24.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Pin_24__PORT == 15 && ((Pin_24__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Pin_24_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void Pin_24_Write(uint8 value) 
{
    uint8 staticBits = (Pin_24_DR & (uint8)(~Pin_24_MASK));
    Pin_24_DR = staticBits | ((uint8)(value << Pin_24_SHIFT) & Pin_24_MASK);
}


/*******************************************************************************
* Function Name: Pin_24_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void Pin_24_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Pin_24_0, mode);
}


/*******************************************************************************
* Function Name: Pin_24_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Pin_24_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Pin_24_Read(void) 
{
    return (Pin_24_PS & Pin_24_MASK) >> Pin_24_SHIFT;
}


/*******************************************************************************
* Function Name: Pin_24_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Pin_24_ReadDataReg(void) 
{
    return (Pin_24_DR & Pin_24_MASK) >> Pin_24_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Pin_24_INTSTAT) 

    /*******************************************************************************
    * Function Name: Pin_24_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Pin_24_ClearInterrupt(void) 
    {
        return (Pin_24_INTSTAT & Pin_24_MASK) >> Pin_24_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
