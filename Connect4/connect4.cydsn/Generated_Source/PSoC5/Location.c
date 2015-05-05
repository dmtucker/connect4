/*******************************************************************************
* File Name: Location.c  
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
#include <Location.H>

#if !defined(Location__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START Location_intc` */

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
* Function Name: Location_Start
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
void Location_Start(void)
{
    /* For all we know the interrupt is active. */
    Location_Disable();

    /* Set the ISR to point to the Location Interrupt. */
    Location_SetVector(&Location_Interrupt);

    /* Set the priority. */
    Location_SetPriority((uint8)Location_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Location_Enable();
}


/*******************************************************************************
* Function Name: Location_StartEx
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
void Location_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    Location_Disable();

    /* Set the ISR to point to the Location Interrupt. */
    Location_SetVector(address);

    /* Set the priority. */
    Location_SetPriority((uint8)Location_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Location_Enable();
}


/*******************************************************************************
* Function Name: Location_Stop
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
void Location_Stop(void)
{
    /* Disable this interrupt. */
    Location_Disable();

    /* Set the ISR to point to the passive one. */
    Location_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: Location_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for Location.
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
CY_ISR(Location_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START Location_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: Location_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling Location_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use Location_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void Location_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)Location__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: Location_GetVector
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
cyisraddress Location_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)Location__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: Location_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling Location_Start
*   or Location_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   Location_Start or Location_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void Location_SetPriority(uint8 priority)
{
    *Location_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: Location_GetPriority
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
uint8 Location_GetPriority(void)
{
    uint8 priority;


    priority = *Location_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: Location_Enable
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
void Location_Enable(void)
{
    /* Enable the general interrupt. */
    *Location_INTC_SET_EN = Location__INTC_MASK;
}


/*******************************************************************************
* Function Name: Location_GetState
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
uint8 Location_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*Location_INTC_SET_EN & (uint32)Location__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: Location_Disable
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
void Location_Disable(void)
{
    /* Disable the general interrupt. */
    *Location_INTC_CLR_EN = Location__INTC_MASK;
}


/*******************************************************************************
* Function Name: Location_SetPending
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
void Location_SetPending(void)
{
    *Location_INTC_SET_PD = Location__INTC_MASK;
}


/*******************************************************************************
* Function Name: Location_ClearPending
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
void Location_ClearPending(void)
{
    *Location_INTC_CLR_PD = Location__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
