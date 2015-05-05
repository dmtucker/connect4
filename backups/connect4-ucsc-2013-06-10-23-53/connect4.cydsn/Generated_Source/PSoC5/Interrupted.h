/*******************************************************************************
* File Name: Interrupted.h  
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

#if !defined(CY_PINS_Interrupted_H) /* Pins Interrupted_H */
#define CY_PINS_Interrupted_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Interrupted_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Interrupted__PORT == 15 && ((Interrupted__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Interrupted_Write(uint8 value) ;
void    Interrupted_SetDriveMode(uint8 mode) ;
uint8   Interrupted_ReadDataReg(void) ;
uint8   Interrupted_Read(void) ;
uint8   Interrupted_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Interrupted_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Interrupted_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Interrupted_DM_RES_UP          PIN_DM_RES_UP
#define Interrupted_DM_RES_DWN         PIN_DM_RES_DWN
#define Interrupted_DM_OD_LO           PIN_DM_OD_LO
#define Interrupted_DM_OD_HI           PIN_DM_OD_HI
#define Interrupted_DM_STRONG          PIN_DM_STRONG
#define Interrupted_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Interrupted_MASK               Interrupted__MASK
#define Interrupted_SHIFT              Interrupted__SHIFT
#define Interrupted_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Interrupted_PS                     (* (reg8 *) Interrupted__PS)
/* Data Register */
#define Interrupted_DR                     (* (reg8 *) Interrupted__DR)
/* Port Number */
#define Interrupted_PRT_NUM                (* (reg8 *) Interrupted__PRT) 
/* Connect to Analog Globals */                                                  
#define Interrupted_AG                     (* (reg8 *) Interrupted__AG)                       
/* Analog MUX bux enable */
#define Interrupted_AMUX                   (* (reg8 *) Interrupted__AMUX) 
/* Bidirectional Enable */                                                        
#define Interrupted_BIE                    (* (reg8 *) Interrupted__BIE)
/* Bit-mask for Aliased Register Access */
#define Interrupted_BIT_MASK               (* (reg8 *) Interrupted__BIT_MASK)
/* Bypass Enable */
#define Interrupted_BYP                    (* (reg8 *) Interrupted__BYP)
/* Port wide control signals */                                                   
#define Interrupted_CTL                    (* (reg8 *) Interrupted__CTL)
/* Drive Modes */
#define Interrupted_DM0                    (* (reg8 *) Interrupted__DM0) 
#define Interrupted_DM1                    (* (reg8 *) Interrupted__DM1)
#define Interrupted_DM2                    (* (reg8 *) Interrupted__DM2) 
/* Input Buffer Disable Override */
#define Interrupted_INP_DIS                (* (reg8 *) Interrupted__INP_DIS)
/* LCD Common or Segment Drive */
#define Interrupted_LCD_COM_SEG            (* (reg8 *) Interrupted__LCD_COM_SEG)
/* Enable Segment LCD */
#define Interrupted_LCD_EN                 (* (reg8 *) Interrupted__LCD_EN)
/* Slew Rate Control */
#define Interrupted_SLW                    (* (reg8 *) Interrupted__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Interrupted_PRTDSI__CAPS_SEL       (* (reg8 *) Interrupted__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Interrupted_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Interrupted__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Interrupted_PRTDSI__OE_SEL0        (* (reg8 *) Interrupted__PRTDSI__OE_SEL0) 
#define Interrupted_PRTDSI__OE_SEL1        (* (reg8 *) Interrupted__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Interrupted_PRTDSI__OUT_SEL0       (* (reg8 *) Interrupted__PRTDSI__OUT_SEL0) 
#define Interrupted_PRTDSI__OUT_SEL1       (* (reg8 *) Interrupted__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Interrupted_PRTDSI__SYNC_OUT       (* (reg8 *) Interrupted__PRTDSI__SYNC_OUT) 


#if defined(Interrupted__INTSTAT)  /* Interrupt Registers */

    #define Interrupted_INTSTAT                (* (reg8 *) Interrupted__INTSTAT)
    #define Interrupted_SNAP                   (* (reg8 *) Interrupted__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Interrupted_H */


/* [] END OF FILE */
