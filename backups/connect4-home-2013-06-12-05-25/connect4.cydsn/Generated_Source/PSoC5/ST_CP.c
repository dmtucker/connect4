/*******************************************************************************
* File Name: ST_CP.c  
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
#include "ST_CP.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ST_CP__PORT == 15 && ((ST_CP__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ST_CP_Write
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
void ST_CP_Write(uint8 value) 
{
    uint8 staticBits = (ST_CP_DR & (uint8)(~ST_CP_MASK));
    ST_CP_DR = staticBits | ((uint8)(value << ST_CP_SHIFT) & ST_CP_MASK);
}


/*******************************************************************************
* Function Name: ST_CP_SetDriveMode
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
void ST_CP_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ST_CP_0, mode);
}


/*******************************************************************************
* Function Name: ST_CP_Read
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
*  Macro ST_CP_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ST_CP_Read(void) 
{
    return (ST_CP_PS & ST_CP_MASK) >> ST_CP_SHIFT;
}


/*******************************************************************************
* Function Name: ST_CP_ReadDataReg
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
uint8 ST_CP_ReadDataReg(void) 
{
    return (ST_CP_DR & ST_CP_MASK) >> ST_CP_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ST_CP_INTSTAT) 

    /*******************************************************************************
    * Function Name: ST_CP_ClearInterrupt
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
    uint8 ST_CP_ClearInterrupt(void) 
    {
        return (ST_CP_INTSTAT & ST_CP_MASK) >> ST_CP_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
