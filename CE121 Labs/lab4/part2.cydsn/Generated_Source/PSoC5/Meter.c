/*******************************************************************************
* File Name: Meter.c  
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
#include "Meter.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Meter__PORT == 15 && ((Meter__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Meter_Write
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
void Meter_Write(uint8 value) 
{
    uint8 staticBits = (Meter_DR & (uint8)(~Meter_MASK));
    Meter_DR = staticBits | ((uint8)(value << Meter_SHIFT) & Meter_MASK);
}


/*******************************************************************************
* Function Name: Meter_SetDriveMode
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
void Meter_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Meter_0, mode);
}


/*******************************************************************************
* Function Name: Meter_Read
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
*  Macro Meter_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Meter_Read(void) 
{
    return (Meter_PS & Meter_MASK) >> Meter_SHIFT;
}


/*******************************************************************************
* Function Name: Meter_ReadDataReg
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
uint8 Meter_ReadDataReg(void) 
{
    return (Meter_DR & Meter_MASK) >> Meter_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Meter_INTSTAT) 

    /*******************************************************************************
    * Function Name: Meter_ClearInterrupt
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
    uint8 Meter_ClearInterrupt(void) 
    {
        return (Meter_INTSTAT & Meter_MASK) >> Meter_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
