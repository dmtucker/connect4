/*******************************************************************************
* File Name: Motor.c  
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
#include "Motor.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Motor__PORT == 15 && ((Motor__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Motor_Write
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
void Motor_Write(uint8 value) 
{
    uint8 staticBits = (Motor_DR & (uint8)(~Motor_MASK));
    Motor_DR = staticBits | ((uint8)(value << Motor_SHIFT) & Motor_MASK);
}


/*******************************************************************************
* Function Name: Motor_SetDriveMode
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
void Motor_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Motor_0, mode);
	CyPins_SetPinDriveMode(Motor_1, mode);
	CyPins_SetPinDriveMode(Motor_2, mode);
	CyPins_SetPinDriveMode(Motor_3, mode);
}


/*******************************************************************************
* Function Name: Motor_Read
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
*  Macro Motor_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Motor_Read(void) 
{
    return (Motor_PS & Motor_MASK) >> Motor_SHIFT;
}


/*******************************************************************************
* Function Name: Motor_ReadDataReg
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
uint8 Motor_ReadDataReg(void) 
{
    return (Motor_DR & Motor_MASK) >> Motor_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Motor_INTSTAT) 

    /*******************************************************************************
    * Function Name: Motor_ClearInterrupt
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
    uint8 Motor_ClearInterrupt(void) 
    {
        return (Motor_INTSTAT & Motor_MASK) >> Motor_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
