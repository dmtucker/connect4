/*******************************************************************************
* File Name: C3_G.h  
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

#if !defined(CY_PINS_C3_G_H) /* Pins C3_G_H */
#define CY_PINS_C3_G_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "C3_G_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 C3_G__PORT == 15 && ((C3_G__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    C3_G_Write(uint8 value) ;
void    C3_G_SetDriveMode(uint8 mode) ;
uint8   C3_G_ReadDataReg(void) ;
uint8   C3_G_Read(void) ;
uint8   C3_G_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define C3_G_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define C3_G_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define C3_G_DM_RES_UP          PIN_DM_RES_UP
#define C3_G_DM_RES_DWN         PIN_DM_RES_DWN
#define C3_G_DM_OD_LO           PIN_DM_OD_LO
#define C3_G_DM_OD_HI           PIN_DM_OD_HI
#define C3_G_DM_STRONG          PIN_DM_STRONG
#define C3_G_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define C3_G_MASK               C3_G__MASK
#define C3_G_SHIFT              C3_G__SHIFT
#define C3_G_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define C3_G_PS                     (* (reg8 *) C3_G__PS)
/* Data Register */
#define C3_G_DR                     (* (reg8 *) C3_G__DR)
/* Port Number */
#define C3_G_PRT_NUM                (* (reg8 *) C3_G__PRT) 
/* Connect to Analog Globals */                                                  
#define C3_G_AG                     (* (reg8 *) C3_G__AG)                       
/* Analog MUX bux enable */
#define C3_G_AMUX                   (* (reg8 *) C3_G__AMUX) 
/* Bidirectional Enable */                                                        
#define C3_G_BIE                    (* (reg8 *) C3_G__BIE)
/* Bit-mask for Aliased Register Access */
#define C3_G_BIT_MASK               (* (reg8 *) C3_G__BIT_MASK)
/* Bypass Enable */
#define C3_G_BYP                    (* (reg8 *) C3_G__BYP)
/* Port wide control signals */                                                   
#define C3_G_CTL                    (* (reg8 *) C3_G__CTL)
/* Drive Modes */
#define C3_G_DM0                    (* (reg8 *) C3_G__DM0) 
#define C3_G_DM1                    (* (reg8 *) C3_G__DM1)
#define C3_G_DM2                    (* (reg8 *) C3_G__DM2) 
/* Input Buffer Disable Override */
#define C3_G_INP_DIS                (* (reg8 *) C3_G__INP_DIS)
/* LCD Common or Segment Drive */
#define C3_G_LCD_COM_SEG            (* (reg8 *) C3_G__LCD_COM_SEG)
/* Enable Segment LCD */
#define C3_G_LCD_EN                 (* (reg8 *) C3_G__LCD_EN)
/* Slew Rate Control */
#define C3_G_SLW                    (* (reg8 *) C3_G__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define C3_G_PRTDSI__CAPS_SEL       (* (reg8 *) C3_G__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define C3_G_PRTDSI__DBL_SYNC_IN    (* (reg8 *) C3_G__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define C3_G_PRTDSI__OE_SEL0        (* (reg8 *) C3_G__PRTDSI__OE_SEL0) 
#define C3_G_PRTDSI__OE_SEL1        (* (reg8 *) C3_G__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define C3_G_PRTDSI__OUT_SEL0       (* (reg8 *) C3_G__PRTDSI__OUT_SEL0) 
#define C3_G_PRTDSI__OUT_SEL1       (* (reg8 *) C3_G__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define C3_G_PRTDSI__SYNC_OUT       (* (reg8 *) C3_G__PRTDSI__SYNC_OUT) 


#if defined(C3_G__INTSTAT)  /* Interrupt Registers */

    #define C3_G_INTSTAT                (* (reg8 *) C3_G__INTSTAT)
    #define C3_G_SNAP                   (* (reg8 *) C3_G__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_C3_G_H */


/* [] END OF FILE */
