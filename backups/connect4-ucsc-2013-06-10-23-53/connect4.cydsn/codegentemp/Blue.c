/*******************************************************************************
* File Name: Blue.c  
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
#include "Blue.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Blue__PORT == 15 && ((Blue__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Blue_Write
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
void Blue_Write(uint8 value) 
{
    uint8 staticBits = (Blue_DR & (uint8)(~Blue_MASK));
    Blue_DR = staticBits | ((uint8)(value << Blue_SHIFT) & Blue_MASK);
}


/*******************************************************************************
* Function Name: Blue_SetDriveMode
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
void Blue_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Blue_0, mode);
}


/*******************************************************************************
* Function Name: Blue_Read
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
*  Macro Blue_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Blue_Read(void) 
{
    return (Blue_PS & Blue_MASK) >> Blue_SHIFT;
}


/*******************************************************************************
* Function Name: Blue_ReadDataReg
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
uint8 Blue_ReadDataReg(void) 
{
    return (Blue_DR & Blue_MASK) >> Blue_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Blue_INTSTAT) 

    /*******************************************************************************
    * Function Name: Blue_ClearInterrupt
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
    uint8 Blue_ClearInterrupt(void) 
    {
        return (Blue_INTSTAT & Blue_MASK) >> Blue_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
