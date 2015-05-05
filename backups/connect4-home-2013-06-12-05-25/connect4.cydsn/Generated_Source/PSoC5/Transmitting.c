/*******************************************************************************
* File Name: Transmitting.c  
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
#include "Transmitting.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Transmitting__PORT == 15 && ((Transmitting__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Transmitting_Write
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
void Transmitting_Write(uint8 value) 
{
    uint8 staticBits = (Transmitting_DR & (uint8)(~Transmitting_MASK));
    Transmitting_DR = staticBits | ((uint8)(value << Transmitting_SHIFT) & Transmitting_MASK);
}


/*******************************************************************************
* Function Name: Transmitting_SetDriveMode
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
void Transmitting_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Transmitting_0, mode);
}


/*******************************************************************************
* Function Name: Transmitting_Read
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
*  Macro Transmitting_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Transmitting_Read(void) 
{
    return (Transmitting_PS & Transmitting_MASK) >> Transmitting_SHIFT;
}


/*******************************************************************************
* Function Name: Transmitting_ReadDataReg
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
uint8 Transmitting_ReadDataReg(void) 
{
    return (Transmitting_DR & Transmitting_MASK) >> Transmitting_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Transmitting_INTSTAT) 

    /*******************************************************************************
    * Function Name: Transmitting_ClearInterrupt
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
    uint8 Transmitting_ClearInterrupt(void) 
    {
        return (Transmitting_INTSTAT & Transmitting_MASK) >> Transmitting_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
