/*******************************************************************************
* File Name: C1_R.c  
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
#include "C1_R.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 C1_R__PORT == 15 && ((C1_R__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: C1_R_Write
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
void C1_R_Write(uint8 value) 
{
    uint8 staticBits = (C1_R_DR & (uint8)(~C1_R_MASK));
    C1_R_DR = staticBits | ((uint8)(value << C1_R_SHIFT) & C1_R_MASK);
}


/*******************************************************************************
* Function Name: C1_R_SetDriveMode
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
void C1_R_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(C1_R_0, mode);
}


/*******************************************************************************
* Function Name: C1_R_Read
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
*  Macro C1_R_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 C1_R_Read(void) 
{
    return (C1_R_PS & C1_R_MASK) >> C1_R_SHIFT;
}


/*******************************************************************************
* Function Name: C1_R_ReadDataReg
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
uint8 C1_R_ReadDataReg(void) 
{
    return (C1_R_DR & C1_R_MASK) >> C1_R_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(C1_R_INTSTAT) 

    /*******************************************************************************
    * Function Name: C1_R_ClearInterrupt
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
    uint8 C1_R_ClearInterrupt(void) 
    {
        return (C1_R_INTSTAT & C1_R_MASK) >> C1_R_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
