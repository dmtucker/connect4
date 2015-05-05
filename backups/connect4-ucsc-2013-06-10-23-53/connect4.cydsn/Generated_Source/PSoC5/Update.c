/*******************************************************************************
* File Name: Update.c  
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
#include "Update.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Update__PORT == 15 && ((Update__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Update_Write
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
void Update_Write(uint8 value) 
{
    uint8 staticBits = (Update_DR & (uint8)(~Update_MASK));
    Update_DR = staticBits | ((uint8)(value << Update_SHIFT) & Update_MASK);
}


/*******************************************************************************
* Function Name: Update_SetDriveMode
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
void Update_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Update_0, mode);
}


/*******************************************************************************
* Function Name: Update_Read
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
*  Macro Update_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Update_Read(void) 
{
    return (Update_PS & Update_MASK) >> Update_SHIFT;
}


/*******************************************************************************
* Function Name: Update_ReadDataReg
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
uint8 Update_ReadDataReg(void) 
{
    return (Update_DR & Update_MASK) >> Update_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Update_INTSTAT) 

    /*******************************************************************************
    * Function Name: Update_ClearInterrupt
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
    uint8 Update_ClearInterrupt(void) 
    {
        return (Update_INTSTAT & Update_MASK) >> Update_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
