/*******************************************************************************
* File Name: col3.h  
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

#if !defined(CY_PINS_col3_H) /* Pins col3_H */
#define CY_PINS_col3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "col3_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 col3__PORT == 15 && ((col3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    col3_Write(uint8 value) ;
void    col3_SetDriveMode(uint8 mode) ;
uint8   col3_ReadDataReg(void) ;
uint8   col3_Read(void) ;
uint8   col3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define col3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define col3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define col3_DM_RES_UP          PIN_DM_RES_UP
#define col3_DM_RES_DWN         PIN_DM_RES_DWN
#define col3_DM_OD_LO           PIN_DM_OD_LO
#define col3_DM_OD_HI           PIN_DM_OD_HI
#define col3_DM_STRONG          PIN_DM_STRONG
#define col3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define col3_MASK               col3__MASK
#define col3_SHIFT              col3__SHIFT
#define col3_WIDTH              3u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define col3_PS                     (* (reg8 *) col3__PS)
/* Data Register */
#define col3_DR                     (* (reg8 *) col3__DR)
/* Port Number */
#define col3_PRT_NUM                (* (reg8 *) col3__PRT) 
/* Connect to Analog Globals */                                                  
#define col3_AG                     (* (reg8 *) col3__AG)                       
/* Analog MUX bux enable */
#define col3_AMUX                   (* (reg8 *) col3__AMUX) 
/* Bidirectional Enable */                                                        
#define col3_BIE                    (* (reg8 *) col3__BIE)
/* Bit-mask for Aliased Register Access */
#define col3_BIT_MASK               (* (reg8 *) col3__BIT_MASK)
/* Bypass Enable */
#define col3_BYP                    (* (reg8 *) col3__BYP)
/* Port wide control signals */                                                   
#define col3_CTL                    (* (reg8 *) col3__CTL)
/* Drive Modes */
#define col3_DM0                    (* (reg8 *) col3__DM0) 
#define col3_DM1                    (* (reg8 *) col3__DM1)
#define col3_DM2                    (* (reg8 *) col3__DM2) 
/* Input Buffer Disable Override */
#define col3_INP_DIS                (* (reg8 *) col3__INP_DIS)
/* LCD Common or Segment Drive */
#define col3_LCD_COM_SEG            (* (reg8 *) col3__LCD_COM_SEG)
/* Enable Segment LCD */
#define col3_LCD_EN                 (* (reg8 *) col3__LCD_EN)
/* Slew Rate Control */
#define col3_SLW                    (* (reg8 *) col3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define col3_PRTDSI__CAPS_SEL       (* (reg8 *) col3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define col3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) col3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define col3_PRTDSI__OE_SEL0        (* (reg8 *) col3__PRTDSI__OE_SEL0) 
#define col3_PRTDSI__OE_SEL1        (* (reg8 *) col3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define col3_PRTDSI__OUT_SEL0       (* (reg8 *) col3__PRTDSI__OUT_SEL0) 
#define col3_PRTDSI__OUT_SEL1       (* (reg8 *) col3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define col3_PRTDSI__SYNC_OUT       (* (reg8 *) col3__PRTDSI__SYNC_OUT) 


#if defined(col3__INTSTAT)  /* Interrupt Registers */

    #define col3_INTSTAT                (* (reg8 *) col3__INTSTAT)
    #define col3_SNAP                   (* (reg8 *) col3__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_col3_H */


/* [] END OF FILE */
