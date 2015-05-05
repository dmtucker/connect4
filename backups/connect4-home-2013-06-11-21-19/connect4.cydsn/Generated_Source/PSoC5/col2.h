/*******************************************************************************
* File Name: col2.h  
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

#if !defined(CY_PINS_col2_H) /* Pins col2_H */
#define CY_PINS_col2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "col2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 col2__PORT == 15 && ((col2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    col2_Write(uint8 value) ;
void    col2_SetDriveMode(uint8 mode) ;
uint8   col2_ReadDataReg(void) ;
uint8   col2_Read(void) ;
uint8   col2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define col2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define col2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define col2_DM_RES_UP          PIN_DM_RES_UP
#define col2_DM_RES_DWN         PIN_DM_RES_DWN
#define col2_DM_OD_LO           PIN_DM_OD_LO
#define col2_DM_OD_HI           PIN_DM_OD_HI
#define col2_DM_STRONG          PIN_DM_STRONG
#define col2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define col2_MASK               col2__MASK
#define col2_SHIFT              col2__SHIFT
#define col2_WIDTH              3u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define col2_PS                     (* (reg8 *) col2__PS)
/* Data Register */
#define col2_DR                     (* (reg8 *) col2__DR)
/* Port Number */
#define col2_PRT_NUM                (* (reg8 *) col2__PRT) 
/* Connect to Analog Globals */                                                  
#define col2_AG                     (* (reg8 *) col2__AG)                       
/* Analog MUX bux enable */
#define col2_AMUX                   (* (reg8 *) col2__AMUX) 
/* Bidirectional Enable */                                                        
#define col2_BIE                    (* (reg8 *) col2__BIE)
/* Bit-mask for Aliased Register Access */
#define col2_BIT_MASK               (* (reg8 *) col2__BIT_MASK)
/* Bypass Enable */
#define col2_BYP                    (* (reg8 *) col2__BYP)
/* Port wide control signals */                                                   
#define col2_CTL                    (* (reg8 *) col2__CTL)
/* Drive Modes */
#define col2_DM0                    (* (reg8 *) col2__DM0) 
#define col2_DM1                    (* (reg8 *) col2__DM1)
#define col2_DM2                    (* (reg8 *) col2__DM2) 
/* Input Buffer Disable Override */
#define col2_INP_DIS                (* (reg8 *) col2__INP_DIS)
/* LCD Common or Segment Drive */
#define col2_LCD_COM_SEG            (* (reg8 *) col2__LCD_COM_SEG)
/* Enable Segment LCD */
#define col2_LCD_EN                 (* (reg8 *) col2__LCD_EN)
/* Slew Rate Control */
#define col2_SLW                    (* (reg8 *) col2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define col2_PRTDSI__CAPS_SEL       (* (reg8 *) col2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define col2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) col2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define col2_PRTDSI__OE_SEL0        (* (reg8 *) col2__PRTDSI__OE_SEL0) 
#define col2_PRTDSI__OE_SEL1        (* (reg8 *) col2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define col2_PRTDSI__OUT_SEL0       (* (reg8 *) col2__PRTDSI__OUT_SEL0) 
#define col2_PRTDSI__OUT_SEL1       (* (reg8 *) col2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define col2_PRTDSI__SYNC_OUT       (* (reg8 *) col2__PRTDSI__SYNC_OUT) 


#if defined(col2__INTSTAT)  /* Interrupt Registers */

    #define col2_INTSTAT                (* (reg8 *) col2__INTSTAT)
    #define col2_SNAP                   (* (reg8 *) col2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_col2_H */


/* [] END OF FILE */
