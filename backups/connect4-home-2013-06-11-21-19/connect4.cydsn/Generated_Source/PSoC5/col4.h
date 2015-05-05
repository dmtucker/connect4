/*******************************************************************************
* File Name: col4.h  
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

#if !defined(CY_PINS_col4_H) /* Pins col4_H */
#define CY_PINS_col4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "col4_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 col4__PORT == 15 && ((col4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    col4_Write(uint8 value) ;
void    col4_SetDriveMode(uint8 mode) ;
uint8   col4_ReadDataReg(void) ;
uint8   col4_Read(void) ;
uint8   col4_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define col4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define col4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define col4_DM_RES_UP          PIN_DM_RES_UP
#define col4_DM_RES_DWN         PIN_DM_RES_DWN
#define col4_DM_OD_LO           PIN_DM_OD_LO
#define col4_DM_OD_HI           PIN_DM_OD_HI
#define col4_DM_STRONG          PIN_DM_STRONG
#define col4_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define col4_MASK               col4__MASK
#define col4_SHIFT              col4__SHIFT
#define col4_WIDTH              3u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define col4_PS                     (* (reg8 *) col4__PS)
/* Data Register */
#define col4_DR                     (* (reg8 *) col4__DR)
/* Port Number */
#define col4_PRT_NUM                (* (reg8 *) col4__PRT) 
/* Connect to Analog Globals */                                                  
#define col4_AG                     (* (reg8 *) col4__AG)                       
/* Analog MUX bux enable */
#define col4_AMUX                   (* (reg8 *) col4__AMUX) 
/* Bidirectional Enable */                                                        
#define col4_BIE                    (* (reg8 *) col4__BIE)
/* Bit-mask for Aliased Register Access */
#define col4_BIT_MASK               (* (reg8 *) col4__BIT_MASK)
/* Bypass Enable */
#define col4_BYP                    (* (reg8 *) col4__BYP)
/* Port wide control signals */                                                   
#define col4_CTL                    (* (reg8 *) col4__CTL)
/* Drive Modes */
#define col4_DM0                    (* (reg8 *) col4__DM0) 
#define col4_DM1                    (* (reg8 *) col4__DM1)
#define col4_DM2                    (* (reg8 *) col4__DM2) 
/* Input Buffer Disable Override */
#define col4_INP_DIS                (* (reg8 *) col4__INP_DIS)
/* LCD Common or Segment Drive */
#define col4_LCD_COM_SEG            (* (reg8 *) col4__LCD_COM_SEG)
/* Enable Segment LCD */
#define col4_LCD_EN                 (* (reg8 *) col4__LCD_EN)
/* Slew Rate Control */
#define col4_SLW                    (* (reg8 *) col4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define col4_PRTDSI__CAPS_SEL       (* (reg8 *) col4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define col4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) col4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define col4_PRTDSI__OE_SEL0        (* (reg8 *) col4__PRTDSI__OE_SEL0) 
#define col4_PRTDSI__OE_SEL1        (* (reg8 *) col4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define col4_PRTDSI__OUT_SEL0       (* (reg8 *) col4__PRTDSI__OUT_SEL0) 
#define col4_PRTDSI__OUT_SEL1       (* (reg8 *) col4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define col4_PRTDSI__SYNC_OUT       (* (reg8 *) col4__PRTDSI__SYNC_OUT) 


#if defined(col4__INTSTAT)  /* Interrupt Registers */

    #define col4_INTSTAT                (* (reg8 *) col4__INTSTAT)
    #define col4_SNAP                   (* (reg8 *) col4__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_col4_H */


/* [] END OF FILE */
