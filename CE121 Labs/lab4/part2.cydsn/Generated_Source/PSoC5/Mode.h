/*******************************************************************************
* File Name: Mode.h
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
#if !defined(CY_ISR_Mode_H)
#define CY_ISR_Mode_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Mode_Start(void);
void Mode_StartEx(cyisraddress address);
void Mode_Stop(void);

CY_ISR_PROTO(Mode_Interrupt);

void Mode_SetVector(cyisraddress address);
cyisraddress Mode_GetVector(void);

void Mode_SetPriority(uint8 priority);
uint8 Mode_GetPriority(void);

void Mode_Enable(void);
uint8 Mode_GetState(void);
void Mode_Disable(void);

void Mode_SetPending(void);
void Mode_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Mode ISR. */
#define Mode_INTC_VECTOR            ((reg32 *) Mode__INTC_VECT)

/* Address of the Mode ISR priority. */
#define Mode_INTC_PRIOR             ((reg8 *) Mode__INTC_PRIOR_REG)

/* Priority of the Mode interrupt. */
#define Mode_INTC_PRIOR_NUMBER      Mode__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Mode interrupt. */
#define Mode_INTC_SET_EN            ((reg32 *) Mode__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Mode interrupt. */
#define Mode_INTC_CLR_EN            ((reg32 *) Mode__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Mode interrupt state to pending. */
#define Mode_INTC_SET_PD            ((reg32 *) Mode__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Mode interrupt. */
#define Mode_INTC_CLR_PD            ((reg32 *) Mode__INTC_CLR_PD_REG)


#endif /* CY_ISR_Mode_H */


/* [] END OF FILE */
