/*******************************************************************************
* File Name: Beam.c  
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
#include <Beam.H>

#if !defined(Beam__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START Beam_intc` */

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
* Function Name: Beam_Start
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
void Beam_Start(void)
{
    /* For all we know the interrupt is active. */
    Beam_Disable();

    /* Set the ISR to point to the Beam Interrupt. */
    Beam_SetVector(&Beam_Interrupt);

    /* Set the priority. */
    Beam_SetPriority((uint8)Beam_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Beam_Enable();
}


/*******************************************************************************
* Function Name: Beam_StartEx
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
void Beam_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    Beam_Disable();

    /* Set the ISR to point to the Beam Interrupt. */
    Beam_SetVector(address);

    /* Set the priority. */
    Beam_SetPriority((uint8)Beam_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Beam_Enable();
}


/*******************************************************************************
* Function Name: Beam_Stop
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
void Beam_Stop(void)
{
    /* Disable this interrupt. */
    Beam_Disable();

    /* Set the ISR to point to the passive one. */
    Beam_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: Beam_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for Beam.
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
CY_ISR(Beam_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START Beam_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: Beam_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling Beam_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use Beam_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void Beam_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)Beam__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: Beam_GetVector
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
cyisraddress Beam_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)Beam__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: Beam_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling Beam_Start
*   or Beam_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   Beam_Start or Beam_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void Beam_SetPriority(uint8 priority)
{
    *Beam_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: Beam_GetPriority
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
uint8 Beam_GetPriority(void)
{
    uint8 priority;


    priority = *Beam_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: Beam_Enable
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
void Beam_Enable(void)
{
    /* Enable the general interrupt. */
    *Beam_INTC_SET_EN = Beam__INTC_MASK;
}


/*******************************************************************************
* Function Name: Beam_GetState
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
uint8 Beam_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*Beam_INTC_SET_EN & (uint32)Beam__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: Beam_Disable
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
void Beam_Disable(void)
{
    /* Disable the general interrupt. */
    *Beam_INTC_CLR_EN = Beam__INTC_MASK;
}


/*******************************************************************************
* Function Name: Beam_SetPending
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
void Beam_SetPending(void)
{
    *Beam_INTC_SET_PD = Beam__INTC_MASK;
}


/*******************************************************************************
* Function Name: Beam_ClearPending
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
void Beam_ClearPending(void)
{
    *Beam_INTC_CLR_PD = Beam__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
