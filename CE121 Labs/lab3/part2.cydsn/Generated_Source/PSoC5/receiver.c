/*******************************************************************************
* File Name: receiver.c  
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
#include "receiver.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 receiver__PORT == 15 && ((receiver__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: receiver_Write
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
void receiver_Write(uint8 value) 
{
    uint8 staticBits = (receiver_DR & (uint8)(~receiver_MASK));
    receiver_DR = staticBits | ((uint8)(value << receiver_SHIFT) & receiver_MASK);
}


/*******************************************************************************
* Function Name: receiver_SetDriveMode
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
void receiver_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(receiver_0, mode);
}


/*******************************************************************************
* Function Name: receiver_Read
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
*  Macro receiver_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 receiver_Read(void) 
{
    return (receiver_PS & receiver_MASK) >> receiver_SHIFT;
}


/*******************************************************************************
* Function Name: receiver_ReadDataReg
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
uint8 receiver_ReadDataReg(void) 
{
    return (receiver_DR & receiver_MASK) >> receiver_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(receiver_INTSTAT) 

    /*******************************************************************************
    * Function Name: receiver_ClearInterrupt
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
    uint8 receiver_ClearInterrupt(void) 
    {
        return (receiver_INTSTAT & receiver_MASK) >> receiver_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
