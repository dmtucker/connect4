/*******************************************************************************
* File Name: row1to4.h  
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

#if !defined(CY_PINS_row1to4_H) /* Pins row1to4_H */
#define CY_PINS_row1to4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "row1to4_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 row1to4__PORT == 15 && ((row1to4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    row1to4_Write(uint8 value) ;
void    row1to4_SetDriveMode(uint8 mode) ;
uint8   row1to4_ReadDataReg(void) ;
uint8   row1to4_Read(void) ;
uint8   row1to4_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define row1to4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define row1to4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define row1to4_DM_RES_UP          PIN_DM_RES_UP
#define row1to4_DM_RES_DWN         PIN_DM_RES_DWN
#define row1to4_DM_OD_LO           PIN_DM_OD_LO
#define row1to4_DM_OD_HI           PIN_DM_OD_HI
#define row1to4_DM_STRONG          PIN_DM_STRONG
#define row1to4_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define row1to4_MASK               row1to4__MASK
#define row1to4_SHIFT              row1to4__SHIFT
#define row1to4_WIDTH              4u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define row1to4_PS                     (* (reg8 *) row1to4__PS)
/* Data Register */
#define row1to4_DR                     (* (reg8 *) row1to4__DR)
/* Port Number */
#define row1to4_PRT_NUM                (* (reg8 *) row1to4__PRT) 
/* Connect to Analog Globals */                                                  
#define row1to4_AG                     (* (reg8 *) row1to4__AG)                       
/* Analog MUX bux enable */
#define row1to4_AMUX                   (* (reg8 *) row1to4__AMUX) 
/* Bidirectional Enable */                                                        
#define row1to4_BIE                    (* (reg8 *) row1to4__BIE)
/* Bit-mask for Aliased Register Access */
#define row1to4_BIT_MASK               (* (reg8 *) row1to4__BIT_MASK)
/* Bypass Enable */
#define row1to4_BYP                    (* (reg8 *) row1to4__BYP)
/* Port wide control signals */                                                   
#define row1to4_CTL                    (* (reg8 *) row1to4__CTL)
/* Drive Modes */
#define row1to4_DM0                    (* (reg8 *) row1to4__DM0) 
#define row1to4_DM1                    (* (reg8 *) row1to4__DM1)
#define row1to4_DM2                    (* (reg8 *) row1to4__DM2) 
/* Input Buffer Disable Override */
#define row1to4_INP_DIS                (* (reg8 *) row1to4__INP_DIS)
/* LCD Common or Segment Drive */
#define row1to4_LCD_COM_SEG            (* (reg8 *) row1to4__LCD_COM_SEG)
/* Enable Segment LCD */
#define row1to4_LCD_EN                 (* (reg8 *) row1to4__LCD_EN)
/* Slew Rate Control */
#define row1to4_SLW                    (* (reg8 *) row1to4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define row1to4_PRTDSI__CAPS_SEL       (* (reg8 *) row1to4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define row1to4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) row1to4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define row1to4_PRTDSI__OE_SEL0        (* (reg8 *) row1to4__PRTDSI__OE_SEL0) 
#define row1to4_PRTDSI__OE_SEL1        (* (reg8 *) row1to4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define row1to4_PRTDSI__OUT_SEL0       (* (reg8 *) row1to4__PRTDSI__OUT_SEL0) 
#define row1to4_PRTDSI__OUT_SEL1       (* (reg8 *) row1to4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define row1to4_PRTDSI__SYNC_OUT       (* (reg8 *) row1to4__PRTDSI__SYNC_OUT) 


#if defined(row1to4__INTSTAT)  /* Interrupt Registers */

    #define row1to4_INTSTAT                (* (reg8 *) row1to4__INTSTAT)
    #define row1to4_SNAP                   (* (reg8 *) row1to4__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_row1to4_H */


/* [] END OF FILE */
