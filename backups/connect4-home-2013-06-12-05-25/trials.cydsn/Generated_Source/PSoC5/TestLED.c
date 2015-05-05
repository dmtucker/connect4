/*******************************************************************************
* File Name: TestLED.c  
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
#include "TestLED.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 TestLED__PORT == 15 && ((TestLED__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: TestLED_Write
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
void TestLED_Write(uint8 value) 
{
    uint8 staticBits = (TestLED_DR & (uint8)(~TestLED_MASK));
    TestLED_DR = staticBits | ((uint8)(value << TestLED_SHIFT) & TestLED_MASK);
}


/*******************************************************************************
* Function Name: TestLED_SetDriveMode
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
void TestLED_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(TestLED_0, mode);
}


/*******************************************************************************
* Function Name: TestLED_Read
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
*  Macro TestLED_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TestLED_Read(void) 
{
    return (TestLED_PS & TestLED_MASK) >> TestLED_SHIFT;
}


/*******************************************************************************
* Function Name: TestLED_ReadDataReg
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
uint8 TestLED_ReadDataReg(void) 
{
    return (TestLED_DR & TestLED_MASK) >> TestLED_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TestLED_INTSTAT) 

    /*******************************************************************************
    * Function Name: TestLED_ClearInterrupt
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
    uint8 TestLED_ClearInterrupt(void) 
    {
        return (TestLED_INTSTAT & TestLED_MASK) >> TestLED_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
