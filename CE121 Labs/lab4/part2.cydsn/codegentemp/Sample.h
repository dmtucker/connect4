/*******************************************************************************
* File Name: Sample.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Sample_H)
#define CY_ISR_Sample_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Sample_Start(void);
void Sample_StartEx(cyisraddress address);
void Sample_Stop(void);

CY_ISR_PROTO(Sample_Interrupt);

void Sample_SetVector(cyisraddress address);
cyisraddress Sample_GetVector(void);

void Sample_SetPriority(uint8 priority);
uint8 Sample_GetPriority(void);

void Sample_Enable(void);
uint8 Sample_GetState(void);
void Sample_Disable(void);

void Sample_SetPending(void);
void Sample_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Sample ISR. */
#define Sample_INTC_VECTOR            ((reg32 *) Sample__INTC_VECT)

/* Address of the Sample ISR priority. */
#define Sample_INTC_PRIOR             ((reg8 *) Sample__INTC_PRIOR_REG)

/* Priority of the Sample interrupt. */
#define Sample_INTC_PRIOR_NUMBER      Sample__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Sample interrupt. */
#define Sample_INTC_SET_EN            ((reg32 *) Sample__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Sample interrupt. */
#define Sample_INTC_CLR_EN            ((reg32 *) Sample__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Sample interrupt state to pending. */
#define Sample_INTC_SET_PD            ((reg32 *) Sample__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Sample interrupt. */
#define Sample_INTC_CLR_PD            ((reg32 *) Sample__INTC_CLR_PD_REG)


#endif /* CY_ISR_Sample_H */


/* [] END OF FILE */
