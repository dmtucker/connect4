/*******************************************************************************
* File Name: R6.c  
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
#include "R6.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 R6__PORT == 15 && ((R6__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: R6_Write
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
void R6_Write(uint8 value) 
{
    uint8 staticBits = (R6_DR & (uint8)(~R6_MASK));
    R6_DR = staticBits | ((uint8)(value << R6_SHIFT) & R6_MASK);
}


/*******************************************************************************
* Function Name: R6_SetDriveMode
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
void R6_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(R6_0, mode);
}


/*******************************************************************************
* Function Name: R6_Read
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
*  Macro R6_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 R6_Read(void) 
{
    return (R6_PS & R6_MASK) >> R6_SHIFT;
}


/*******************************************************************************
* Function Name: R6_ReadDataReg
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
uint8 R6_ReadDataReg(void) 
{
    return (R6_DR & R6_MASK) >> R6_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(R6_INTSTAT) 

    /*******************************************************************************
    * Function Name: R6_ClearInterrupt
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
    uint8 R6_ClearInterrupt(void) 
    {
        return (R6_INTSTAT & R6_MASK) >> R6_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
