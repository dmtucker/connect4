/*******************************************************************************
* File Name: Toggle.c  
* Version 1.80
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
#include "Toggle.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Toggle__PORT == 15 && ((Toggle__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Toggle_Write
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
void Toggle_Write(uint8 value) 
{
    uint8 staticBits = (Toggle_DR & (uint8)(~Toggle_MASK));
    Toggle_DR = staticBits | ((uint8)(value << Toggle_SHIFT) & Toggle_MASK);
}


/*******************************************************************************
* Function Name: Toggle_SetDriveMode
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
void Toggle_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Toggle_0, mode);
}


/*******************************************************************************
* Function Name: Toggle_Read
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
*  Macro Toggle_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Toggle_Read(void) 
{
    return (Toggle_PS & Toggle_MASK) >> Toggle_SHIFT;
}


/*******************************************************************************
* Function Name: Toggle_ReadDataReg
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
uint8 Toggle_ReadDataReg(void) 
{
    return (Toggle_DR & Toggle_MASK) >> Toggle_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Toggle_INTSTAT) 

    /*******************************************************************************
    * Function Name: Toggle_ClearInterrupt
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
    uint8 Toggle_ClearInterrupt(void) 
    {
        return (Toggle_INTSTAT & Toggle_MASK) >> Toggle_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
