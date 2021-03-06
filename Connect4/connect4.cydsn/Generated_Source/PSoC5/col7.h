/*******************************************************************************
* File Name: col7.h  
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

#if !defined(CY_PINS_col7_H) /* Pins col7_H */
#define CY_PINS_col7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "col7_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 col7__PORT == 15 && ((col7__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    col7_Write(uint8 value) ;
void    col7_SetDriveMode(uint8 mode) ;
uint8   col7_ReadDataReg(void) ;
uint8   col7_Read(void) ;
uint8   col7_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define col7_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define col7_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define col7_DM_RES_UP          PIN_DM_RES_UP
#define col7_DM_RES_DWN         PIN_DM_RES_DWN
#define col7_DM_OD_LO           PIN_DM_OD_LO
#define col7_DM_OD_HI           PIN_DM_OD_HI
#define col7_DM_STRONG          PIN_DM_STRONG
#define col7_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define col7_MASK               col7__MASK
#define col7_SHIFT              col7__SHIFT
#define col7_WIDTH              3u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define col7_PS                     (* (reg8 *) col7__PS)
/* Data Register */
#define col7_DR                     (* (reg8 *) col7__DR)
/* Port Number */
#define col7_PRT_NUM                (* (reg8 *) col7__PRT) 
/* Connect to Analog Globals */                                                  
#define col7_AG                     (* (reg8 *) col7__AG)                       
/* Analog MUX bux enable */
#define col7_AMUX                   (* (reg8 *) col7__AMUX) 
/* Bidirectional Enable */                                                        
#define col7_BIE                    (* (reg8 *) col7__BIE)
/* Bit-mask for Aliased Register Access */
#define col7_BIT_MASK               (* (reg8 *) col7__BIT_MASK)
/* Bypass Enable */
#define col7_BYP                    (* (reg8 *) col7__BYP)
/* Port wide control signals */                                                   
#define col7_CTL                    (* (reg8 *) col7__CTL)
/* Drive Modes */
#define col7_DM0                    (* (reg8 *) col7__DM0) 
#define col7_DM1                    (* (reg8 *) col7__DM1)
#define col7_DM2                    (* (reg8 *) col7__DM2) 
/* Input Buffer Disable Override */
#define col7_INP_DIS                (* (reg8 *) col7__INP_DIS)
/* LCD Common or Segment Drive */
#define col7_LCD_COM_SEG            (* (reg8 *) col7__LCD_COM_SEG)
/* Enable Segment LCD */
#define col7_LCD_EN                 (* (reg8 *) col7__LCD_EN)
/* Slew Rate Control */
#define col7_SLW                    (* (reg8 *) col7__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define col7_PRTDSI__CAPS_SEL       (* (reg8 *) col7__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define col7_PRTDSI__DBL_SYNC_IN    (* (reg8 *) col7__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define col7_PRTDSI__OE_SEL0        (* (reg8 *) col7__PRTDSI__OE_SEL0) 
#define col7_PRTDSI__OE_SEL1        (* (reg8 *) col7__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define col7_PRTDSI__OUT_SEL0       (* (reg8 *) col7__PRTDSI__OUT_SEL0) 
#define col7_PRTDSI__OUT_SEL1       (* (reg8 *) col7__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define col7_PRTDSI__SYNC_OUT       (* (reg8 *) col7__PRTDSI__SYNC_OUT) 


#if defined(col7__INTSTAT)  /* Interrupt Registers */

    #define col7_INTSTAT                (* (reg8 *) col7__INTSTAT)
    #define col7_SNAP                   (* (reg8 *) col7__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_col7_H */


/* [] END OF FILE */
