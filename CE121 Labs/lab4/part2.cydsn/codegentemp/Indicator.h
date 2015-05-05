/*******************************************************************************
* File Name: Indicator.h  
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

#if !defined(CY_PINS_Indicator_H) /* Pins Indicator_H */
#define CY_PINS_Indicator_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Indicator_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Indicator__PORT == 15 && ((Indicator__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Indicator_Write(uint8 value) ;
void    Indicator_SetDriveMode(uint8 mode) ;
uint8   Indicator_ReadDataReg(void) ;
uint8   Indicator_Read(void) ;
uint8   Indicator_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Indicator_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Indicator_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Indicator_DM_RES_UP          PIN_DM_RES_UP
#define Indicator_DM_RES_DWN         PIN_DM_RES_DWN
#define Indicator_DM_OD_LO           PIN_DM_OD_LO
#define Indicator_DM_OD_HI           PIN_DM_OD_HI
#define Indicator_DM_STRONG          PIN_DM_STRONG
#define Indicator_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Indicator_MASK               Indicator__MASK
#define Indicator_SHIFT              Indicator__SHIFT
#define Indicator_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Indicator_PS                     (* (reg8 *) Indicator__PS)
/* Data Register */
#define Indicator_DR                     (* (reg8 *) Indicator__DR)
/* Port Number */
#define Indicator_PRT_NUM                (* (reg8 *) Indicator__PRT) 
/* Connect to Analog Globals */                                                  
#define Indicator_AG                     (* (reg8 *) Indicator__AG)                       
/* Analog MUX bux enable */
#define Indicator_AMUX                   (* (reg8 *) Indicator__AMUX) 
/* Bidirectional Enable */                                                        
#define Indicator_BIE                    (* (reg8 *) Indicator__BIE)
/* Bit-mask for Aliased Register Access */
#define Indicator_BIT_MASK               (* (reg8 *) Indicator__BIT_MASK)
/* Bypass Enable */
#define Indicator_BYP                    (* (reg8 *) Indicator__BYP)
/* Port wide control signals */                                                   
#define Indicator_CTL                    (* (reg8 *) Indicator__CTL)
/* Drive Modes */
#define Indicator_DM0                    (* (reg8 *) Indicator__DM0) 
#define Indicator_DM1                    (* (reg8 *) Indicator__DM1)
#define Indicator_DM2                    (* (reg8 *) Indicator__DM2) 
/* Input Buffer Disable Override */
#define Indicator_INP_DIS                (* (reg8 *) Indicator__INP_DIS)
/* LCD Common or Segment Drive */
#define Indicator_LCD_COM_SEG            (* (reg8 *) Indicator__LCD_COM_SEG)
/* Enable Segment LCD */
#define Indicator_LCD_EN                 (* (reg8 *) Indicator__LCD_EN)
/* Slew Rate Control */
#define Indicator_SLW                    (* (reg8 *) Indicator__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Indicator_PRTDSI__CAPS_SEL       (* (reg8 *) Indicator__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Indicator_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Indicator__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Indicator_PRTDSI__OE_SEL0        (* (reg8 *) Indicator__PRTDSI__OE_SEL0) 
#define Indicator_PRTDSI__OE_SEL1        (* (reg8 *) Indicator__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Indicator_PRTDSI__OUT_SEL0       (* (reg8 *) Indicator__PRTDSI__OUT_SEL0) 
#define Indicator_PRTDSI__OUT_SEL1       (* (reg8 *) Indicator__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Indicator_PRTDSI__SYNC_OUT       (* (reg8 *) Indicator__PRTDSI__SYNC_OUT) 


#if defined(Indicator__INTSTAT)  /* Interrupt Registers */

    #define Indicator_INTSTAT                (* (reg8 *) Indicator__INTSTAT)
    #define Indicator_SNAP                   (* (reg8 *) Indicator__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Indicator_H */


/* [] END OF FILE */
