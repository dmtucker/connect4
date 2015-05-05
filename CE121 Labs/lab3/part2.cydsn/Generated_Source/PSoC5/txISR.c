/*******************************************************************************
* File Name: txISR.c  
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
#include <txISR.H>

#if !defined(txISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START txISR_intc` */

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
* Function Name: txISR_Start
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
void txISR_Start(void)
{
    /* For all we know the interrupt is active. */
    txISR_Disable();

    /* Set the ISR to point to the txISR Interrupt. */
    txISR_SetVector(&txISR_Interrupt);

    /* Set the priority. */
    txISR_SetPriority((uint8)txISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    txISR_Enable();
}


/*******************************************************************************
* Function Name: txISR_StartEx
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
void txISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    txISR_Disable();

    /* Set the ISR to point to the txISR Interrupt. */
    txISR_SetVector(address);

    /* Set the priority. */
    txISR_SetPriority((uint8)txISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    txISR_Enable();
}


/*******************************************************************************
* Function Name: txISR_Stop
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
void txISR_Stop(void)
{
    /* Disable this interrupt. */
    txISR_Disable();

    /* Set the ISR to point to the passive one. */
    txISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: txISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for txISR.
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
CY_ISR(txISR_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START txISR_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: txISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling txISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use txISR_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void txISR_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)txISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: txISR_GetVector
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
cyisraddress txISR_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)txISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: txISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling txISR_Start
*   or txISR_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   txISR_Start or txISR_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void txISR_SetPriority(uint8 priority)
{
    *txISR_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: txISR_GetPriority
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
uint8 txISR_GetPriority(void)
{
    uint8 priority;


    priority = *txISR_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: txISR_Enable
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
void txISR_Enable(void)
{
    /* Enable the general interrupt. */
    *txISR_INTC_SET_EN = txISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: txISR_GetState
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
uint8 txISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*txISR_INTC_SET_EN & (uint32)txISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: txISR_Disable
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
void txISR_Disable(void)
{
    /* Disable the general interrupt. */
    *txISR_INTC_CLR_EN = txISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: txISR_SetPending
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
void txISR_SetPending(void)
{
    *txISR_INTC_SET_PD = txISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: txISR_ClearPending
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
void txISR_ClearPending(void)
{
    *txISR_INTC_CLR_PD = txISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
