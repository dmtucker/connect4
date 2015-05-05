/*******************************************************************************
* File Name: row5to8.c  
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
#include "row5to8.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 row5to8__PORT == 15 && ((row5to8__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: row5to8_Write
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
void row5to8_Write(uint8 value) 
{
    uint8 staticBits = (row5to8_DR & (uint8)(~row5to8_MASK));
    row5to8_DR = staticBits | ((uint8)(value << row5to8_SHIFT) & row5to8_MASK);
}


/*******************************************************************************
* Function Name: row5to8_SetDriveMode
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
void row5to8_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(row5to8_0, mode);
	CyPins_SetPinDriveMode(row5to8_1, mode);
	CyPins_SetPinDriveMode(row5to8_2, mode);
	CyPins_SetPinDriveMode(row5to8_3, mode);
}


/*******************************************************************************
* Function Name: row5to8_Read
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
*  Macro row5to8_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 row5to8_Read(void) 
{
    return (row5to8_PS & row5to8_MASK) >> row5to8_SHIFT;
}


/*******************************************************************************
* Function Name: row5to8_ReadDataReg
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
uint8 row5to8_ReadDataReg(void) 
{
    return (row5to8_DR & row5to8_MASK) >> row5to8_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(row5to8_INTSTAT) 

    /*******************************************************************************
    * Function Name: row5to8_ClearInterrupt
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
    uint8 row5to8_ClearInterrupt(void) 
    {
        return (row5to8_INTSTAT & row5to8_MASK) >> row5to8_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
