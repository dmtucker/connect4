/*******************************************************************************
* File Name: row5to8.h  
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

#if !defined(CY_PINS_row5to8_H) /* Pins row5to8_H */
#define CY_PINS_row5to8_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "row5to8_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 row5to8__PORT == 15 && ((row5to8__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    row5to8_Write(uint8 value) ;
void    row5to8_SetDriveMode(uint8 mode) ;
uint8   row5to8_ReadDataReg(void) ;
uint8   row5to8_Read(void) ;
uint8   row5to8_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define row5to8_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define row5to8_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define row5to8_DM_RES_UP          PIN_DM_RES_UP
#define row5to8_DM_RES_DWN         PIN_DM_RES_DWN
#define row5to8_DM_OD_LO           PIN_DM_OD_LO
#define row5to8_DM_OD_HI           PIN_DM_OD_HI
#define row5to8_DM_STRONG          PIN_DM_STRONG
#define row5to8_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define row5to8_MASK               row5to8__MASK
#define row5to8_SHIFT              row5to8__SHIFT
#define row5to8_WIDTH              4u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define row5to8_PS                     (* (reg8 *) row5to8__PS)
/* Data Register */
#define row5to8_DR                     (* (reg8 *) row5to8__DR)
/* Port Number */
#define row5to8_PRT_NUM                (* (reg8 *) row5to8__PRT) 
/* Connect to Analog Globals */                                                  
#define row5to8_AG                     (* (reg8 *) row5to8__AG)                       
/* Analog MUX bux enable */
#define row5to8_AMUX                   (* (reg8 *) row5to8__AMUX) 
/* Bidirectional Enable */                                                        
#define row5to8_BIE                    (* (reg8 *) row5to8__BIE)
/* Bit-mask for Aliased Register Access */
#define row5to8_BIT_MASK               (* (reg8 *) row5to8__BIT_MASK)
/* Bypass Enable */
#define row5to8_BYP                    (* (reg8 *) row5to8__BYP)
/* Port wide control signals */                                                   
#define row5to8_CTL                    (* (reg8 *) row5to8__CTL)
/* Drive Modes */
#define row5to8_DM0                    (* (reg8 *) row5to8__DM0) 
#define row5to8_DM1                    (* (reg8 *) row5to8__DM1)
#define row5to8_DM2                    (* (reg8 *) row5to8__DM2) 
/* Input Buffer Disable Override */
#define row5to8_INP_DIS                (* (reg8 *) row5to8__INP_DIS)
/* LCD Common or Segment Drive */
#define row5to8_LCD_COM_SEG            (* (reg8 *) row5to8__LCD_COM_SEG)
/* Enable Segment LCD */
#define row5to8_LCD_EN                 (* (reg8 *) row5to8__LCD_EN)
/* Slew Rate Control */
#define row5to8_SLW                    (* (reg8 *) row5to8__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define row5to8_PRTDSI__CAPS_SEL       (* (reg8 *) row5to8__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define row5to8_PRTDSI__DBL_SYNC_IN    (* (reg8 *) row5to8__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define row5to8_PRTDSI__OE_SEL0        (* (reg8 *) row5to8__PRTDSI__OE_SEL0) 
#define row5to8_PRTDSI__OE_SEL1        (* (reg8 *) row5to8__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define row5to8_PRTDSI__OUT_SEL0       (* (reg8 *) row5to8__PRTDSI__OUT_SEL0) 
#define row5to8_PRTDSI__OUT_SEL1       (* (reg8 *) row5to8__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define row5to8_PRTDSI__SYNC_OUT       (* (reg8 *) row5to8__PRTDSI__SYNC_OUT) 


#if defined(row5to8__INTSTAT)  /* Interrupt Registers */

    #define row5to8_INTSTAT                (* (reg8 *) row5to8__INTSTAT)
    #define row5to8_SNAP                   (* (reg8 *) row5to8__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_row5to8_H */


/* [] END OF FILE */
