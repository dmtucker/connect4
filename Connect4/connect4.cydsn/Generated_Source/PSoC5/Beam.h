/*******************************************************************************
* File Name: Beam.h
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
#if !defined(CY_ISR_Beam_H)
#define CY_ISR_Beam_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Beam_Start(void);
void Beam_StartEx(cyisraddress address);
void Beam_Stop(void);

CY_ISR_PROTO(Beam_Interrupt);

void Beam_SetVector(cyisraddress address);
cyisraddress Beam_GetVector(void);

void Beam_SetPriority(uint8 priority);
uint8 Beam_GetPriority(void);

void Beam_Enable(void);
uint8 Beam_GetState(void);
void Beam_Disable(void);

void Beam_SetPending(void);
void Beam_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Beam ISR. */
#define Beam_INTC_VECTOR            ((reg32 *) Beam__INTC_VECT)

/* Address of the Beam ISR priority. */
#define Beam_INTC_PRIOR             ((reg8 *) Beam__INTC_PRIOR_REG)

/* Priority of the Beam interrupt. */
#define Beam_INTC_PRIOR_NUMBER      Beam__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Beam interrupt. */
#define Beam_INTC_SET_EN            ((reg32 *) Beam__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Beam interrupt. */
#define Beam_INTC_CLR_EN            ((reg32 *) Beam__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Beam interrupt state to pending. */
#define Beam_INTC_SET_PD            ((reg32 *) Beam__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Beam interrupt. */
#define Beam_INTC_CLR_PD            ((reg32 *) Beam__INTC_CLR_PD_REG)


#endif /* CY_ISR_Beam_H */


/* [] END OF FILE */
