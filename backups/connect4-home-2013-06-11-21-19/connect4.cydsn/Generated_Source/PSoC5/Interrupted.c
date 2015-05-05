/*******************************************************************************
* File Name: Interrupted.c  
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
#include "Interrupted.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Interrupted__PORT == 15 && ((Interrupted__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Interrupted_Write
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
void Interrupted_Write(uint8 value) 
{
    uint8 staticBits = (Interrupted_DR & (uint8)(~Interrupted_MASK));
    Interrupted_DR = staticBits | ((uint8)(value << Interrupted_SHIFT) & Interrupted_MASK);
}


/*******************************************************************************
* Function Name: Interrupted_SetDriveMode
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
void Interrupted_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Interrupted_0, mode);
}


/*******************************************************************************
* Function Name: Interrupted_Read
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
*  Macro Interrupted_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Interrupted_Read(void) 
{
    return (Interrupted_PS & Interrupted_MASK) >> Interrupted_SHIFT;
}


/*******************************************************************************
* Function Name: Interrupted_ReadDataReg
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
uint8 Interrupted_ReadDataReg(void) 
{
    return (Interrupted_DR & Interrupted_MASK) >> Interrupted_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Interrupted_INTSTAT) 

    /*******************************************************************************
    * Function Name: Interrupted_ClearInterrupt
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
    uint8 Interrupted_ClearInterrupt(void) 
    {
        return (Interrupted_INTSTAT & Interrupted_MASK) >> Interrupted_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
