/*******************************************************************************
* File Name: Taillight.c  
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
#include "Taillight.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Taillight__PORT == 15 && ((Taillight__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Taillight_Write
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
void Taillight_Write(uint8 value) 
{
    uint8 staticBits = (Taillight_DR & (uint8)(~Taillight_MASK));
    Taillight_DR = staticBits | ((uint8)(value << Taillight_SHIFT) & Taillight_MASK);
}


/*******************************************************************************
* Function Name: Taillight_SetDriveMode
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
void Taillight_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Taillight_0, mode);
}


/*******************************************************************************
* Function Name: Taillight_Read
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
*  Macro Taillight_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Taillight_Read(void) 
{
    return (Taillight_PS & Taillight_MASK) >> Taillight_SHIFT;
}


/*******************************************************************************
* Function Name: Taillight_ReadDataReg
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
uint8 Taillight_ReadDataReg(void) 
{
    return (Taillight_DR & Taillight_MASK) >> Taillight_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Taillight_INTSTAT) 

    /*******************************************************************************
    * Function Name: Taillight_ClearInterrupt
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
    uint8 Taillight_ClearInterrupt(void) 
    {
        return (Taillight_INTSTAT & Taillight_MASK) >> Taillight_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
