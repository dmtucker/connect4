/*******************************************************************************
* File Name: RemoteLED.c  
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
#include "RemoteLED.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 RemoteLED__PORT == 15 && ((RemoteLED__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: RemoteLED_Write
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
void RemoteLED_Write(uint8 value) 
{
    uint8 staticBits = (RemoteLED_DR & (uint8)(~RemoteLED_MASK));
    RemoteLED_DR = staticBits | ((uint8)(value << RemoteLED_SHIFT) & RemoteLED_MASK);
}


/*******************************************************************************
* Function Name: RemoteLED_SetDriveMode
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
void RemoteLED_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(RemoteLED_0, mode);
}


/*******************************************************************************
* Function Name: RemoteLED_Read
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
*  Macro RemoteLED_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 RemoteLED_Read(void) 
{
    return (RemoteLED_PS & RemoteLED_MASK) >> RemoteLED_SHIFT;
}


/*******************************************************************************
* Function Name: RemoteLED_ReadDataReg
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
uint8 RemoteLED_ReadDataReg(void) 
{
    return (RemoteLED_DR & RemoteLED_MASK) >> RemoteLED_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(RemoteLED_INTSTAT) 

    /*******************************************************************************
    * Function Name: RemoteLED_ClearInterrupt
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
    uint8 RemoteLED_ClearInterrupt(void) 
    {
        return (RemoteLED_INTSTAT & RemoteLED_MASK) >> RemoteLED_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
