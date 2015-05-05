/*******************************************************************************
* File Name: col6.h  
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

#if !defined(CY_PINS_col6_H) /* Pins col6_H */
#define CY_PINS_col6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "col6_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 col6__PORT == 15 && ((col6__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    col6_Write(uint8 value) ;
void    col6_SetDriveMode(uint8 mode) ;
uint8   col6_ReadDataReg(void) ;
uint8   col6_Read(void) ;
uint8   col6_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define col6_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define col6_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define col6_DM_RES_UP          PIN_DM_RES_UP
#define col6_DM_RES_DWN         PIN_DM_RES_DWN
#define col6_DM_OD_LO           PIN_DM_OD_LO
#define col6_DM_OD_HI           PIN_DM_OD_HI
#define col6_DM_STRONG          PIN_DM_STRONG
#define col6_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define col6_MASK               col6__MASK
#define col6_SHIFT              col6__SHIFT
#define col6_WIDTH              3u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define col6_PS                     (* (reg8 *) col6__PS)
/* Data Register */
#define col6_DR                     (* (reg8 *) col6__DR)
/* Port Number */
#define col6_PRT_NUM                (* (reg8 *) col6__PRT) 
/* Connect to Analog Globals */                                                  
#define col6_AG                     (* (reg8 *) col6__AG)                       
/* Analog MUX bux enable */
#define col6_AMUX                   (* (reg8 *) col6__AMUX) 
/* Bidirectional Enable */                                                        
#define col6_BIE                    (* (reg8 *) col6__BIE)
/* Bit-mask for Aliased Register Access */
#define col6_BIT_MASK               (* (reg8 *) col6__BIT_MASK)
/* Bypass Enable */
#define col6_BYP                    (* (reg8 *) col6__BYP)
/* Port wide control signals */                                                   
#define col6_CTL                    (* (reg8 *) col6__CTL)
/* Drive Modes */
#define col6_DM0                    (* (reg8 *) col6__DM0) 
#define col6_DM1                    (* (reg8 *) col6__DM1)
#define col6_DM2                    (* (reg8 *) col6__DM2) 
/* Input Buffer Disable Override */
#define col6_INP_DIS                (* (reg8 *) col6__INP_DIS)
/* LCD Common or Segment Drive */
#define col6_LCD_COM_SEG            (* (reg8 *) col6__LCD_COM_SEG)
/* Enable Segment LCD */
#define col6_LCD_EN                 (* (reg8 *) col6__LCD_EN)
/* Slew Rate Control */
#define col6_SLW                    (* (reg8 *) col6__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define col6_PRTDSI__CAPS_SEL       (* (reg8 *) col6__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define col6_PRTDSI__DBL_SYNC_IN    (* (reg8 *) col6__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define col6_PRTDSI__OE_SEL0        (* (reg8 *) col6__PRTDSI__OE_SEL0) 
#define col6_PRTDSI__OE_SEL1        (* (reg8 *) col6__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define col6_PRTDSI__OUT_SEL0       (* (reg8 *) col6__PRTDSI__OUT_SEL0) 
#define col6_PRTDSI__OUT_SEL1       (* (reg8 *) col6__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define col6_PRTDSI__SYNC_OUT       (* (reg8 *) col6__PRTDSI__SYNC_OUT) 


#if defined(col6__INTSTAT)  /* Interrupt Registers */

    #define col6_INTSTAT                (* (reg8 *) col6__INTSTAT)
    #define col6_SNAP                   (* (reg8 *) col6__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_col6_H */


/* [] END OF FILE */
