/*******************************************************************************
* File Name: Remote_Toggle.c  
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
#include "Remote_Toggle.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Remote_Toggle__PORT == 15 && ((Remote_Toggle__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Remote_Toggle_Write
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
void Remote_Toggle_Write(uint8 value) 
{
    uint8 staticBits = (Remote_Toggle_DR & (uint8)(~Remote_Toggle_MASK));
    Remote_Toggle_DR = staticBits | ((uint8)(value << Remote_Toggle_SHIFT) & Remote_Toggle_MASK);
}


/*******************************************************************************
* Function Name: Remote_Toggle_SetDriveMode
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
void Remote_Toggle_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Remote_Toggle_0, mode);
}


/*******************************************************************************
* Function Name: Remote_Toggle_Read
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
*  Macro Remote_Toggle_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Remote_Toggle_Read(void) 
{
    return (Remote_Toggle_PS & Remote_Toggle_MASK) >> Remote_Toggle_SHIFT;
}


/*******************************************************************************
* Function Name: Remote_Toggle_ReadDataReg
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
uint8 Remote_Toggle_ReadDataReg(void) 
{
    return (Remote_Toggle_DR & Remote_Toggle_MASK) >> Remote_Toggle_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Remote_Toggle_INTSTAT) 

    /*******************************************************************************
    * Function Name: Remote_Toggle_ClearInterrupt
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
    uint8 Remote_Toggle_ClearInterrupt(void) 
    {
        return (Remote_Toggle_INTSTAT & Remote_Toggle_MASK) >> Remote_Toggle_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
