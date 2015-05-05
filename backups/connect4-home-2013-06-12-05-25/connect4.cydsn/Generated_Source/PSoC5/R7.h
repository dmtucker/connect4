/*******************************************************************************
* File Name: R7.h  
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

#if !defined(CY_PINS_R7_H) /* Pins R7_H */
#define CY_PINS_R7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "R7_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 R7__PORT == 15 && ((R7__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    R7_Write(uint8 value) ;
void    R7_SetDriveMode(uint8 mode) ;
uint8   R7_ReadDataReg(void) ;
uint8   R7_Read(void) ;
uint8   R7_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define R7_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define R7_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define R7_DM_RES_UP          PIN_DM_RES_UP
#define R7_DM_RES_DWN         PIN_DM_RES_DWN
#define R7_DM_OD_LO           PIN_DM_OD_LO
#define R7_DM_OD_HI           PIN_DM_OD_HI
#define R7_DM_STRONG          PIN_DM_STRONG
#define R7_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define R7_MASK               R7__MASK
#define R7_SHIFT              R7__SHIFT
#define R7_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R7_PS                     (* (reg8 *) R7__PS)
/* Data Register */
#define R7_DR                     (* (reg8 *) R7__DR)
/* Port Number */
#define R7_PRT_NUM                (* (reg8 *) R7__PRT) 
/* Connect to Analog Globals */                                                  
#define R7_AG                     (* (reg8 *) R7__AG)                       
/* Analog MUX bux enable */
#define R7_AMUX                   (* (reg8 *) R7__AMUX) 
/* Bidirectional Enable */                                                        
#define R7_BIE                    (* (reg8 *) R7__BIE)
/* Bit-mask for Aliased Register Access */
#define R7_BIT_MASK               (* (reg8 *) R7__BIT_MASK)
/* Bypass Enable */
#define R7_BYP                    (* (reg8 *) R7__BYP)
/* Port wide control signals */                                                   
#define R7_CTL                    (* (reg8 *) R7__CTL)
/* Drive Modes */
#define R7_DM0                    (* (reg8 *) R7__DM0) 
#define R7_DM1                    (* (reg8 *) R7__DM1)
#define R7_DM2                    (* (reg8 *) R7__DM2) 
/* Input Buffer Disable Override */
#define R7_INP_DIS                (* (reg8 *) R7__INP_DIS)
/* LCD Common or Segment Drive */
#define R7_LCD_COM_SEG            (* (reg8 *) R7__LCD_COM_SEG)
/* Enable Segment LCD */
#define R7_LCD_EN                 (* (reg8 *) R7__LCD_EN)
/* Slew Rate Control */
#define R7_SLW                    (* (reg8 *) R7__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define R7_PRTDSI__CAPS_SEL       (* (reg8 *) R7__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define R7_PRTDSI__DBL_SYNC_IN    (* (reg8 *) R7__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define R7_PRTDSI__OE_SEL0        (* (reg8 *) R7__PRTDSI__OE_SEL0) 
#define R7_PRTDSI__OE_SEL1        (* (reg8 *) R7__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define R7_PRTDSI__OUT_SEL0       (* (reg8 *) R7__PRTDSI__OUT_SEL0) 
#define R7_PRTDSI__OUT_SEL1       (* (reg8 *) R7__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define R7_PRTDSI__SYNC_OUT       (* (reg8 *) R7__PRTDSI__SYNC_OUT) 


#if defined(R7__INTSTAT)  /* Interrupt Registers */

    #define R7_INTSTAT                (* (reg8 *) R7__INTSTAT)
    #define R7_SNAP                   (* (reg8 *) R7__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_R7_H */


/* [] END OF FILE */
