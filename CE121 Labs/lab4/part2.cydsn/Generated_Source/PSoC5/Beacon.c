/*******************************************************************************
* File Name: Beacon.c  
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
#include "Beacon.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Beacon__PORT == 15 && ((Beacon__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Beacon_Write
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
void Beacon_Write(uint8 value) 
{
    uint8 staticBits = (Beacon_DR & (uint8)(~Beacon_MASK));
    Beacon_DR = staticBits | ((uint8)(value << Beacon_SHIFT) & Beacon_MASK);
}


/*******************************************************************************
* Function Name: Beacon_SetDriveMode
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
void Beacon_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Beacon_0, mode);
}


/*******************************************************************************
* Function Name: Beacon_Read
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
*  Macro Beacon_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Beacon_Read(void) 
{
    return (Beacon_PS & Beacon_MASK) >> Beacon_SHIFT;
}


/*******************************************************************************
* Function Name: Beacon_ReadDataReg
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
uint8 Beacon_ReadDataReg(void) 
{
    return (Beacon_DR & Beacon_MASK) >> Beacon_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Beacon_INTSTAT) 

    /*******************************************************************************
    * Function Name: Beacon_ClearInterrupt
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
    uint8 Beacon_ClearInterrupt(void) 
    {
        return (Beacon_INTSTAT & Beacon_MASK) >> Beacon_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
