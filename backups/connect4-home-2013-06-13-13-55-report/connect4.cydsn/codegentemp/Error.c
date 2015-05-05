/*******************************************************************************
* File Name: Error.c  
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
#include "Error.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Error__PORT == 15 && ((Error__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Error_Write
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
void Error_Write(uint8 value) 
{
    uint8 staticBits = (Error_DR & (uint8)(~Error_MASK));
    Error_DR = staticBits | ((uint8)(value << Error_SHIFT) & Error_MASK);
}


/*******************************************************************************
* Function Name: Error_SetDriveMode
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
void Error_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Error_0, mode);
}


/*******************************************************************************
* Function Name: Error_Read
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
*  Macro Error_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Error_Read(void) 
{
    return (Error_PS & Error_MASK) >> Error_SHIFT;
}


/*******************************************************************************
* Function Name: Error_ReadDataReg
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
uint8 Error_ReadDataReg(void) 
{
    return (Error_DR & Error_MASK) >> Error_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Error_INTSTAT) 

    /*******************************************************************************
    * Function Name: Error_ClearInterrupt
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
    uint8 Error_ClearInterrupt(void) 
    {
        return (Error_INTSTAT & Error_MASK) >> Error_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
