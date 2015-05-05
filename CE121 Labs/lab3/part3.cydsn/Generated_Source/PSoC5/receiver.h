/*******************************************************************************
* File Name: receiver.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_receiver_H) /* Pins receiver_H */
#define CY_PINS_receiver_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "receiver_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 receiver__PORT == 15 && ((receiver__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    receiver_Write(uint8 value) ;
void    receiver_SetDriveMode(uint8 mode) ;
uint8   receiver_ReadDataReg(void) ;
uint8   receiver_Read(void) ;
uint8   receiver_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define receiver_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define receiver_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define receiver_DM_RES_UP          PIN_DM_RES_UP
#define receiver_DM_RES_DWN         PIN_DM_RES_DWN
#define receiver_DM_OD_LO           PIN_DM_OD_LO
#define receiver_DM_OD_HI           PIN_DM_OD_HI
#define receiver_DM_STRONG          PIN_DM_STRONG
#define receiver_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define receiver_MASK               receiver__MASK
#define receiver_SHIFT              receiver__SHIFT
#define receiver_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define receiver_PS                     (* (reg8 *) receiver__PS)
/* Data Register */
#define receiver_DR                     (* (reg8 *) receiver__DR)
/* Port Number */
#define receiver_PRT_NUM                (* (reg8 *) receiver__PRT) 
/* Connect to Analog Globals */                                                  
#define receiver_AG                     (* (reg8 *) receiver__AG)                       
/* Analog MUX bux enable */
#define receiver_AMUX                   (* (reg8 *) receiver__AMUX) 
/* Bidirectional Enable */                                                        
#define receiver_BIE                    (* (reg8 *) receiver__BIE)
/* Bit-mask for Aliased Register Access */
#define receiver_BIT_MASK               (* (reg8 *) receiver__BIT_MASK)
/* Bypass Enable */
#define receiver_BYP                    (* (reg8 *) receiver__BYP)
/* Port wide control signals */                                                   
#define receiver_CTL                    (* (reg8 *) receiver__CTL)
/* Drive Modes */
#define receiver_DM0                    (* (reg8 *) receiver__DM0) 
#define receiver_DM1                    (* (reg8 *) receiver__DM1)
#define receiver_DM2                    (* (reg8 *) receiver__DM2) 
/* Input Buffer Disable Override */
#define receiver_INP_DIS                (* (reg8 *) receiver__INP_DIS)
/* LCD Common or Segment Drive */
#define receiver_LCD_COM_SEG            (* (reg8 *) receiver__LCD_COM_SEG)
/* Enable Segment LCD */
#define receiver_LCD_EN                 (* (reg8 *) receiver__LCD_EN)
/* Slew Rate Control */
#define receiver_SLW                    (* (reg8 *) receiver__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define receiver_PRTDSI__CAPS_SEL       (* (reg8 *) receiver__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define receiver_PRTDSI__DBL_SYNC_IN    (* (reg8 *) receiver__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define receiver_PRTDSI__OE_SEL0        (* (reg8 *) receiver__PRTDSI__OE_SEL0) 
#define receiver_PRTDSI__OE_SEL1        (* (reg8 *) receiver__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define receiver_PRTDSI__OUT_SEL0       (* (reg8 *) receiver__PRTDSI__OUT_SEL0) 
#define receiver_PRTDSI__OUT_SEL1       (* (reg8 *) receiver__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define receiver_PRTDSI__SYNC_OUT       (* (reg8 *) receiver__PRTDSI__SYNC_OUT) 


#if defined(receiver__INTSTAT)  /* Interrupt Registers */

    #define receiver_INTSTAT                (* (reg8 *) receiver__INTSTAT)
    #define receiver_SNAP                   (* (reg8 *) receiver__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_receiver_H */


/* [] END OF FILE */
