/*******************************************************************************
* File Name: Mode.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <CYDEVICE_TRM.H>
#include <CYLIB.H>
#include <Mode.H>

#if !defined(Mode__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START Mode_intc` */

/* `#END` */

#ifndef CYINT_IRQ_BASE
#define CYINT_IRQ_BASE      16
#endif /* CYINT_IRQ_BASE */
#ifndef CYINT_VECT_TABLE
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#endif /* CYINT_VECT_TABLE */

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: Mode_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Mode_Start(void)
{
    /* For all we know the interrupt is active. */
    Mode_Disable();

    /* Set the ISR to point to the Mode Interrupt. */
    Mode_SetVector(&Mode_Interrupt);

    /* Set the priority. */
    Mode_SetPriority((uint8)Mode_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Mode_Enable();
}


/*******************************************************************************
* Function Name: Mode_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void Mode_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    Mode_Disable();

    /* Set the ISR to point to the Mode Interrupt. */
    Mode_SetVector(address);

    /* Set the priority. */
    Mode_SetPriority((uint8)Mode_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Mode_Enable();
}


/*******************************************************************************
* Function Name: Mode_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void Mode_Stop(void)
{
    /* Disable this interrupt. */
    Mode_Disable();

    /* Set the ISR to point to the passive one. */
    Mode_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: Mode_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for Mode.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(Mode_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START Mode_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: Mode_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling Mode_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use Mode_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void Mode_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)Mode__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: Mode_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress Mode_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)Mode__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: Mode_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling Mode_Start
*   or Mode_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   Mode_Start or Mode_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void Mode_SetPriority(uint8 priority)
{
    *Mode_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: Mode_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*******************************************************************************/
uint8 Mode_GetPriority(void)
{
    uint8 priority;


    priority = *Mode_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: Mode_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Mode_Enable(void)
{
    /* Enable the general interrupt. */
    *Mode_INTC_SET_EN = Mode__INTC_MASK;
}


/*******************************************************************************
* Function Name: Mode_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 Mode_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*Mode_INTC_SET_EN & (uint32)Mode__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: Mode_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Mode_Disable(void)
{
    /* Disable the general interrupt. */
    *Mode_INTC_CLR_EN = Mode__INTC_MASK;
}


/*******************************************************************************
* Function Name: Mode_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Mode_SetPending(void)
{
    *Mode_INTC_SET_PD = Mode__INTC_MASK;
}


/*******************************************************************************
* Function Name: Mode_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void Mode_ClearPending(void)
{
    *Mode_INTC_CLR_PD = Mode__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
