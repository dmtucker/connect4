/*******************************************************************************
* File Name: C4_R.c  
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
#include "C4_R.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 C4_R__PORT == 15 && ((C4_R__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: C4_R_Write
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
void C4_R_Write(uint8 value) 
{
    uint8 staticBits = (C4_R_DR & (uint8)(~C4_R_MASK));
    C4_R_DR = staticBits | ((uint8)(value << C4_R_SHIFT) & C4_R_MASK);
}


/*******************************************************************************
* Function Name: C4_R_SetDriveMode
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
void C4_R_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(C4_R_0, mode);
}


/*******************************************************************************
* Function Name: C4_R_Read
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
*  Macro C4_R_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 C4_R_Read(void) 
{
    return (C4_R_PS & C4_R_MASK) >> C4_R_SHIFT;
}


/*******************************************************************************
* Function Name: C4_R_ReadDataReg
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
uint8 C4_R_ReadDataReg(void) 
{
    return (C4_R_DR & C4_R_MASK) >> C4_R_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(C4_R_INTSTAT) 

    /*******************************************************************************
    * Function Name: C4_R_ClearInterrupt
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
    uint8 C4_R_ClearInterrupt(void) 
    {
        return (C4_R_INTSTAT & C4_R_MASK) >> C4_R_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
