/*******************************************************************************
* File Name: R3.h  
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

#if !defined(CY_PINS_R3_H) /* Pins R3_H */
#define CY_PINS_R3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "R3_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 R3__PORT == 15 && ((R3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    R3_Write(uint8 value) ;
void    R3_SetDriveMode(uint8 mode) ;
uint8   R3_ReadDataReg(void) ;
uint8   R3_Read(void) ;
uint8   R3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define R3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define R3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define R3_DM_RES_UP          PIN_DM_RES_UP
#define R3_DM_RES_DWN         PIN_DM_RES_DWN
#define R3_DM_OD_LO           PIN_DM_OD_LO
#define R3_DM_OD_HI           PIN_DM_OD_HI
#define R3_DM_STRONG          PIN_DM_STRONG
#define R3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define R3_MASK               R3__MASK
#define R3_SHIFT              R3__SHIFT
#define R3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R3_PS                     (* (reg8 *) R3__PS)
/* Data Register */
#define R3_DR                     (* (reg8 *) R3__DR)
/* Port Number */
#define R3_PRT_NUM                (* (reg8 *) R3__PRT) 
/* Connect to Analog Globals */                                                  
#define R3_AG                     (* (reg8 *) R3__AG)                       
/* Analog MUX bux enable */
#define R3_AMUX                   (* (reg8 *) R3__AMUX) 
/* Bidirectional Enable */                                                        
#define R3_BIE                    (* (reg8 *) R3__BIE)
/* Bit-mask for Aliased Register Access */
#define R3_BIT_MASK               (* (reg8 *) R3__BIT_MASK)
/* Bypass Enable */
#define R3_BYP                    (* (reg8 *) R3__BYP)
/* Port wide control signals */                                                   
#define R3_CTL                    (* (reg8 *) R3__CTL)
/* Drive Modes */
#define R3_DM0                    (* (reg8 *) R3__DM0) 
#define R3_DM1                    (* (reg8 *) R3__DM1)
#define R3_DM2                    (* (reg8 *) R3__DM2) 
/* Input Buffer Disable Override */
#define R3_INP_DIS                (* (reg8 *) R3__INP_DIS)
/* LCD Common or Segment Drive */
#define R3_LCD_COM_SEG            (* (reg8 *) R3__LCD_COM_SEG)
/* Enable Segment LCD */
#define R3_LCD_EN                 (* (reg8 *) R3__LCD_EN)
/* Slew Rate Control */
#define R3_SLW                    (* (reg8 *) R3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define R3_PRTDSI__CAPS_SEL       (* (reg8 *) R3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define R3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) R3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define R3_PRTDSI__OE_SEL0        (* (reg8 *) R3__PRTDSI__OE_SEL0) 
#define R3_PRTDSI__OE_SEL1        (* (reg8 *) R3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define R3_PRTDSI__OUT_SEL0       (* (reg8 *) R3__PRTDSI__OUT_SEL0) 
#define R3_PRTDSI__OUT_SEL1       (* (reg8 *) R3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define R3_PRTDSI__SYNC_OUT       (* (reg8 *) R3__PRTDSI__SYNC_OUT) 


#if defined(R3__INTSTAT)  /* Interrupt Registers */

    #define R3_INTSTAT                (* (reg8 *) R3__INTSTAT)
    #define R3_SNAP                   (* (reg8 *) R3__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_R3_H */


/* [] END OF FILE */
