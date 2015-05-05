/*******************************************************************************
* File Name: col5.c  
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
#include "col5.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 col5__PORT == 15 && ((col5__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: col5_Write
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
void col5_Write(uint8 value) 
{
    uint8 staticBits = (col5_DR & (uint8)(~col5_MASK));
    col5_DR = staticBits | ((uint8)(value << col5_SHIFT) & col5_MASK);
}


/*******************************************************************************
* Function Name: col5_SetDriveMode
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
void col5_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(col5_0, mode);
	CyPins_SetPinDriveMode(col5_1, mode);
	CyPins_SetPinDriveMode(col5_2, mode);
}


/*******************************************************************************
* Function Name: col5_Read
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
*  Macro col5_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 col5_Read(void) 
{
    return (col5_PS & col5_MASK) >> col5_SHIFT;
}


/*******************************************************************************
* Function Name: col5_ReadDataReg
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
uint8 col5_ReadDataReg(void) 
{
    return (col5_DR & col5_MASK) >> col5_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(col5_INTSTAT) 

    /*******************************************************************************
    * Function Name: col5_ClearInterrupt
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
    uint8 col5_ClearInterrupt(void) 
    {
        return (col5_INTSTAT & col5_MASK) >> col5_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
