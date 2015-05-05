/*******************************************************************************
* File Name: Location.h
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
#if !defined(CY_ISR_Location_H)
#define CY_ISR_Location_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Location_Start(void);
void Location_StartEx(cyisraddress address);
void Location_Stop(void);

CY_ISR_PROTO(Location_Interrupt);

void Location_SetVector(cyisraddress address);
cyisraddress Location_GetVector(void);

void Location_SetPriority(uint8 priority);
uint8 Location_GetPriority(void);

void Location_Enable(void);
uint8 Location_GetState(void);
void Location_Disable(void);

void Location_SetPending(void);
void Location_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Location ISR. */
#define Location_INTC_VECTOR            ((reg32 *) Location__INTC_VECT)

/* Address of the Location ISR priority. */
#define Location_INTC_PRIOR             ((reg8 *) Location__INTC_PRIOR_REG)

/* Priority of the Location interrupt. */
#define Location_INTC_PRIOR_NUMBER      Location__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Location interrupt. */
#define Location_INTC_SET_EN            ((reg32 *) Location__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Location interrupt. */
#define Location_INTC_CLR_EN            ((reg32 *) Location__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Location interrupt state to pending. */
#define Location_INTC_SET_PD            ((reg32 *) Location__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Location interrupt. */
#define Location_INTC_CLR_PD            ((reg32 *) Location__INTC_CLR_PD_REG)


#endif /* CY_ISR_Location_H */


/* [] END OF FILE */
