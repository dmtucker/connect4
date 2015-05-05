/*******************************************************************************
* File Name: R6.h  
* Version 1.90
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

#if !defined(CY_PINS_R6_H) /* Pins R6_H */
#define CY_PINS_R6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "R6_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 R6__PORT == 15 && ((R6__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    R6_Write(uint8 value) ;
void    R6_SetDriveMode(uint8 mode) ;
uint8   R6_ReadDataReg(void) ;
uint8   R6_Read(void) ;
uint8   R6_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define R6_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define R6_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define R6_DM_RES_UP          PIN_DM_RES_UP
#define R6_DM_RES_DWN         PIN_DM_RES_DWN
#define R6_DM_OD_LO           PIN_DM_OD_LO
#define R6_DM_OD_HI           PIN_DM_OD_HI
#define R6_DM_STRONG          PIN_DM_STRONG
#define R6_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define R6_MASK               R6__MASK
#define R6_SHIFT              R6__SHIFT
#define R6_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R6_PS                     (* (reg8 *) R6__PS)
/* Data Register */
#define R6_DR                     (* (reg8 *) R6__DR)
/* Port Number */
#define R6_PRT_NUM                (* (reg8 *) R6__PRT) 
/* Connect to Analog Globals */                                                  
#define R6_AG                     (* (reg8 *) R6__AG)                       
/* Analog MUX bux enable */
#define R6_AMUX                   (* (reg8 *) R6__AMUX) 
/* Bidirectional Enable */                                                        
#define R6_BIE                    (* (reg8 *) R6__BIE)
/* Bit-mask for Aliased Register Access */
#define R6_BIT_MASK               (* (reg8 *) R6__BIT_MASK)
/* Bypass Enable */
#define R6_BYP                    (* (reg8 *) R6__BYP)
/* Port wide control signals */                                                   
#define R6_CTL                    (* (reg8 *) R6__CTL)
/* Drive Modes */
#define R6_DM0                    (* (reg8 *) R6__DM0) 
#define R6_DM1                    (* (reg8 *) R6__DM1)
#define R6_DM2                    (* (reg8 *) R6__DM2) 
/* Input Buffer Disable Override */
#define R6_INP_DIS                (* (reg8 *) R6__INP_DIS)
/* LCD Common or Segment Drive */
#define R6_LCD_COM_SEG            (* (reg8 *) R6__LCD_COM_SEG)
/* Enable Segment LCD */
#define R6_LCD_EN                 (* (reg8 *) R6__LCD_EN)
/* Slew Rate Control */
#define R6_SLW                    (* (reg8 *) R6__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define R6_PRTDSI__CAPS_SEL       (* (reg8 *) R6__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define R6_PRTDSI__DBL_SYNC_IN    (* (reg8 *) R6__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define R6_PRTDSI__OE_SEL0        (* (reg8 *) R6__PRTDSI__OE_SEL0) 
#define R6_PRTDSI__OE_SEL1        (* (reg8 *) R6__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define R6_PRTDSI__OUT_SEL0       (* (reg8 *) R6__PRTDSI__OUT_SEL0) 
#define R6_PRTDSI__OUT_SEL1       (* (reg8 *) R6__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define R6_PRTDSI__SYNC_OUT       (* (reg8 *) R6__PRTDSI__SYNC_OUT) 


#if defined(R6__INTSTAT)  /* Interrupt Registers */

    #define R6_INTSTAT                (* (reg8 *) R6__INTSTAT)
    #define R6_SNAP                   (* (reg8 *) R6__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_R6_H */


/* [] END OF FILE */
