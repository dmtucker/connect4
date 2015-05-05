/*******************************************************************************
* File Name: rxISR.c  
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
#include <rxISR.H>

#if !defined(rxISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START rxISR_intc` */

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
* Function Name: rxISR_Start
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
void rxISR_Start(void)
{
    /* For all we know the interrupt is active. */
    rxISR_Disable();

    /* Set the ISR to point to the rxISR Interrupt. */
    rxISR_SetVector(&rxISR_Interrupt);

    /* Set the priority. */
    rxISR_SetPriority((uint8)rxISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    rxISR_Enable();
}


/*******************************************************************************
* Function Name: rxISR_StartEx
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
void rxISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    rxISR_Disable();

    /* Set the ISR to point to the rxISR Interrupt. */
    rxISR_SetVector(address);

    /* Set the priority. */
    rxISR_SetPriority((uint8)rxISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    rxISR_Enable();
}


/*******************************************************************************
* Function Name: rxISR_Stop
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
void rxISR_Stop(void)
{
    /* Disable this interrupt. */
    rxISR_Disable();

    /* Set the ISR to point to the passive one. */
    rxISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: rxISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for rxISR.
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
CY_ISR(rxISR_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START rxISR_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: rxISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling rxISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use rxISR_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void rxISR_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)rxISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: rxISR_GetVector
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
cyisraddress rxISR_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)rxISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: rxISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling rxISR_Start
*   or rxISR_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   rxISR_Start or rxISR_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void rxISR_SetPriority(uint8 priority)
{
    *rxISR_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: rxISR_GetPriority
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
uint8 rxISR_GetPriority(void)
{
    uint8 priority;


    priority = *rxISR_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: rxISR_Enable
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
void rxISR_Enable(void)
{
    /* Enable the general interrupt. */
    *rxISR_INTC_SET_EN = rxISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: rxISR_GetState
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
uint8 rxISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*rxISR_INTC_SET_EN & (uint32)rxISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: rxISR_Disable
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
void rxISR_Disable(void)
{
    /* Disable the general interrupt. */
    *rxISR_INTC_CLR_EN = rxISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: rxISR_SetPending
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
void rxISR_SetPending(void)
{
    *rxISR_INTC_SET_PD = rxISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: rxISR_ClearPending
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
void rxISR_ClearPending(void)
{
    *rxISR_INTC_CLR_PD = rxISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
