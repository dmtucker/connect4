/*******************************************************************************
* File Name: Accelerator.c  
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
#include "Accelerator.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Accelerator__PORT == 15 && ((Accelerator__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Accelerator_Write
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
void Accelerator_Write(uint8 value) 
{
    uint8 staticBits = (Accelerator_DR & (uint8)(~Accelerator_MASK));
    Accelerator_DR = staticBits | ((uint8)(value << Accelerator_SHIFT) & Accelerator_MASK);
}


/*******************************************************************************
* Function Name: Accelerator_SetDriveMode
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
void Accelerator_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Accelerator_0, mode);
}


/*******************************************************************************
* Function Name: Accelerator_Read
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
*  Macro Accelerator_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Accelerator_Read(void) 
{
    return (Accelerator_PS & Accelerator_MASK) >> Accelerator_SHIFT;
}


/*******************************************************************************
* Function Name: Accelerator_ReadDataReg
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
uint8 Accelerator_ReadDataReg(void) 
{
    return (Accelerator_DR & Accelerator_MASK) >> Accelerator_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Accelerator_INTSTAT) 

    /*******************************************************************************
    * Function Name: Accelerator_ClearInterrupt
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
    uint8 Accelerator_ClearInterrupt(void) 
    {
        return (Accelerator_INTSTAT & Accelerator_MASK) >> Accelerator_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
