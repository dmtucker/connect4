/*******************************************************************************
* File Name: R7.c  
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
#include "R7.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 R7__PORT == 15 && ((R7__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: R7_Write
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
void R7_Write(uint8 value) 
{
    uint8 staticBits = (R7_DR & (uint8)(~R7_MASK));
    R7_DR = staticBits | ((uint8)(value << R7_SHIFT) & R7_MASK);
}


/*******************************************************************************
* Function Name: R7_SetDriveMode
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
void R7_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(R7_0, mode);
}


/*******************************************************************************
* Function Name: R7_Read
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
*  Macro R7_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 R7_Read(void) 
{
    return (R7_PS & R7_MASK) >> R7_SHIFT;
}


/*******************************************************************************
* Function Name: R7_ReadDataReg
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
uint8 R7_ReadDataReg(void) 
{
    return (R7_DR & R7_MASK) >> R7_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(R7_INTSTAT) 

    /*******************************************************************************
    * Function Name: R7_ClearInterrupt
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
    uint8 R7_ClearInterrupt(void) 
    {
        return (R7_INTSTAT & R7_MASK) >> R7_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
