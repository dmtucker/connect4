/*******************************************************************************
* File Name: Taillight.h  
* Version 1.80
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

#if !defined(CY_PINS_Taillight_H) /* Pins Taillight_H */
#define CY_PINS_Taillight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Taillight_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Taillight__PORT == 15 && ((Taillight__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Taillight_Write(uint8 value) ;
void    Taillight_SetDriveMode(uint8 mode) ;
uint8   Taillight_ReadDataReg(void) ;
uint8   Taillight_Read(void) ;
uint8   Taillight_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Taillight_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Taillight_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Taillight_DM_RES_UP          PIN_DM_RES_UP
#define Taillight_DM_RES_DWN         PIN_DM_RES_DWN
#define Taillight_DM_OD_LO           PIN_DM_OD_LO
#define Taillight_DM_OD_HI           PIN_DM_OD_HI
#define Taillight_DM_STRONG          PIN_DM_STRONG
#define Taillight_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Taillight_MASK               Taillight__MASK
#define Taillight_SHIFT              Taillight__SHIFT
#define Taillight_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Taillight_PS                     (* (reg8 *) Taillight__PS)
/* Data Register */
#define Taillight_DR                     (* (reg8 *) Taillight__DR)
/* Port Number */
#define Taillight_PRT_NUM                (* (reg8 *) Taillight__PRT) 
/* Connect to Analog Globals */                                                  
#define Taillight_AG                     (* (reg8 *) Taillight__AG)                       
/* Analog MUX bux enable */
#define Taillight_AMUX                   (* (reg8 *) Taillight__AMUX) 
/* Bidirectional Enable */                                                        
#define Taillight_BIE                    (* (reg8 *) Taillight__BIE)
/* Bit-mask for Aliased Register Access */
#define Taillight_BIT_MASK               (* (reg8 *) Taillight__BIT_MASK)
/* Bypass Enable */
#define Taillight_BYP                    (* (reg8 *) Taillight__BYP)
/* Port wide control signals */                                                   
#define Taillight_CTL                    (* (reg8 *) Taillight__CTL)
/* Drive Modes */
#define Taillight_DM0                    (* (reg8 *) Taillight__DM0) 
#define Taillight_DM1                    (* (reg8 *) Taillight__DM1)
#define Taillight_DM2                    (* (reg8 *) Taillight__DM2) 
/* Input Buffer Disable Override */
#define Taillight_INP_DIS                (* (reg8 *) Taillight__INP_DIS)
/* LCD Common or Segment Drive */
#define Taillight_LCD_COM_SEG            (* (reg8 *) Taillight__LCD_COM_SEG)
/* Enable Segment LCD */
#define Taillight_LCD_EN                 (* (reg8 *) Taillight__LCD_EN)
/* Slew Rate Control */
#define Taillight_SLW                    (* (reg8 *) Taillight__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Taillight_PRTDSI__CAPS_SEL       (* (reg8 *) Taillight__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Taillight_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Taillight__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Taillight_PRTDSI__OE_SEL0        (* (reg8 *) Taillight__PRTDSI__OE_SEL0) 
#define Taillight_PRTDSI__OE_SEL1        (* (reg8 *) Taillight__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Taillight_PRTDSI__OUT_SEL0       (* (reg8 *) Taillight__PRTDSI__OUT_SEL0) 
#define Taillight_PRTDSI__OUT_SEL1       (* (reg8 *) Taillight__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Taillight_PRTDSI__SYNC_OUT       (* (reg8 *) Taillight__PRTDSI__SYNC_OUT) 


#if defined(Taillight__INTSTAT)  /* Interrupt Registers */

    #define Taillight_INTSTAT                (* (reg8 *) Taillight__INTSTAT)
    #define Taillight_SNAP                   (* (reg8 *) Taillight__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Taillight_H */


/* [] END OF FILE */
