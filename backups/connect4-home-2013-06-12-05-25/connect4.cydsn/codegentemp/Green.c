/*******************************************************************************
* File Name: Green.c  
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
#include "Green.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Green__PORT == 15 && ((Green__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Green_Write
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
void Green_Write(uint8 value) 
{
    uint8 staticBits = (Green_DR & (uint8)(~Green_MASK));
    Green_DR = staticBits | ((uint8)(value << Green_SHIFT) & Green_MASK);
}


/*******************************************************************************
* Function Name: Green_SetDriveMode
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
void Green_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Green_0, mode);
}


/*******************************************************************************
* Function Name: Green_Read
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
*  Macro Green_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Green_Read(void) 
{
    return (Green_PS & Green_MASK) >> Green_SHIFT;
}


/*******************************************************************************
* Function Name: Green_ReadDataReg
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
uint8 Green_ReadDataReg(void) 
{
    return (Green_DR & Green_MASK) >> Green_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Green_INTSTAT) 

    /*******************************************************************************
    * Function Name: Green_ClearInterrupt
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
    uint8 Green_ClearInterrupt(void) 
    {
        return (Green_INTSTAT & Green_MASK) >> Green_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
