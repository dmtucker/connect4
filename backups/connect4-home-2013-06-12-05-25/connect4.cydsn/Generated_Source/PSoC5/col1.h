/*******************************************************************************
* File Name: col1.h  
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

#if !defined(CY_PINS_col1_H) /* Pins col1_H */
#define CY_PINS_col1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "col1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 col1__PORT == 15 && ((col1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    col1_Write(uint8 value) ;
void    col1_SetDriveMode(uint8 mode) ;
uint8   col1_ReadDataReg(void) ;
uint8   col1_Read(void) ;
uint8   col1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define col1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define col1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define col1_DM_RES_UP          PIN_DM_RES_UP
#define col1_DM_RES_DWN         PIN_DM_RES_DWN
#define col1_DM_OD_LO           PIN_DM_OD_LO
#define col1_DM_OD_HI           PIN_DM_OD_HI
#define col1_DM_STRONG          PIN_DM_STRONG
#define col1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define col1_MASK               col1__MASK
#define col1_SHIFT              col1__SHIFT
#define col1_WIDTH              3u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define col1_PS                     (* (reg8 *) col1__PS)
/* Data Register */
#define col1_DR                     (* (reg8 *) col1__DR)
/* Port Number */
#define col1_PRT_NUM                (* (reg8 *) col1__PRT) 
/* Connect to Analog Globals */                                                  
#define col1_AG                     (* (reg8 *) col1__AG)                       
/* Analog MUX bux enable */
#define col1_AMUX                   (* (reg8 *) col1__AMUX) 
/* Bidirectional Enable */                                                        
#define col1_BIE                    (* (reg8 *) col1__BIE)
/* Bit-mask for Aliased Register Access */
#define col1_BIT_MASK               (* (reg8 *) col1__BIT_MASK)
/* Bypass Enable */
#define col1_BYP                    (* (reg8 *) col1__BYP)
/* Port wide control signals */                                                   
#define col1_CTL                    (* (reg8 *) col1__CTL)
/* Drive Modes */
#define col1_DM0                    (* (reg8 *) col1__DM0) 
#define col1_DM1                    (* (reg8 *) col1__DM1)
#define col1_DM2                    (* (reg8 *) col1__DM2) 
/* Input Buffer Disable Override */
#define col1_INP_DIS                (* (reg8 *) col1__INP_DIS)
/* LCD Common or Segment Drive */
#define col1_LCD_COM_SEG            (* (reg8 *) col1__LCD_COM_SEG)
/* Enable Segment LCD */
#define col1_LCD_EN                 (* (reg8 *) col1__LCD_EN)
/* Slew Rate Control */
#define col1_SLW                    (* (reg8 *) col1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define col1_PRTDSI__CAPS_SEL       (* (reg8 *) col1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define col1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) col1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define col1_PRTDSI__OE_SEL0        (* (reg8 *) col1__PRTDSI__OE_SEL0) 
#define col1_PRTDSI__OE_SEL1        (* (reg8 *) col1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define col1_PRTDSI__OUT_SEL0       (* (reg8 *) col1__PRTDSI__OUT_SEL0) 
#define col1_PRTDSI__OUT_SEL1       (* (reg8 *) col1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define col1_PRTDSI__SYNC_OUT       (* (reg8 *) col1__PRTDSI__SYNC_OUT) 


#if defined(col1__INTSTAT)  /* Interrupt Registers */

    #define col1_INTSTAT                (* (reg8 *) col1__INTSTAT)
    #define col1_SNAP                   (* (reg8 *) col1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_col1_H */


/* [] END OF FILE */
