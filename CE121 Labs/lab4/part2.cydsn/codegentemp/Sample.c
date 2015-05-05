/*******************************************************************************
* File Name: Sample.c  
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
#include <Sample.H>

#if !defined(Sample__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START Sample_intc` */

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
* Function Name: Sample_Start
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
void Sample_Start(void)
{
    /* For all we know the interrupt is active. */
    Sample_Disable();

    /* Set the ISR to point to the Sample Interrupt. */
    Sample_SetVector(&Sample_Interrupt);

    /* Set the priority. */
    Sample_SetPriority((uint8)Sample_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Sample_Enable();
}


/*******************************************************************************
* Function Name: Sample_StartEx
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
void Sample_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    Sample_Disable();

    /* Set the ISR to point to the Sample Interrupt. */
    Sample_SetVector(address);

    /* Set the priority. */
    Sample_SetPriority((uint8)Sample_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Sample_Enable();
}


/*******************************************************************************
* Function Name: Sample_Stop
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
void Sample_Stop(void)
{
    /* Disable this interrupt. */
    Sample_Disable();

    /* Set the ISR to point to the passive one. */
    Sample_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: Sample_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for Sample.
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
CY_ISR(Sample_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START Sample_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: Sample_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling Sample_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use Sample_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void Sample_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)Sample__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: Sample_GetVector
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
cyisraddress Sample_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)Sample__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: Sample_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling Sample_Start
*   or Sample_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   Sample_Start or Sample_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void Sample_SetPriority(uint8 priority)
{
    *Sample_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: Sample_GetPriority
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
uint8 Sample_GetPriority(void)
{
    uint8 priority;


    priority = *Sample_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: Sample_Enable
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
void Sample_Enable(void)
{
    /* Enable the general interrupt. */
    *Sample_INTC_SET_EN = Sample__INTC_MASK;
}


/*******************************************************************************
* Function Name: Sample_GetState
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
uint8 Sample_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*Sample_INTC_SET_EN & (uint32)Sample__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: Sample_Disable
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
void Sample_Disable(void)
{
    /* Disable the general interrupt. */
    *Sample_INTC_CLR_EN = Sample__INTC_MASK;
}


/*******************************************************************************
* Function Name: Sample_SetPending
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
void Sample_SetPending(void)
{
    *Sample_INTC_SET_PD = Sample__INTC_MASK;
}


/*******************************************************************************
* Function Name: Sample_ClearPending
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
void Sample_ClearPending(void)
{
    *Sample_INTC_CLR_PD = Sample__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
