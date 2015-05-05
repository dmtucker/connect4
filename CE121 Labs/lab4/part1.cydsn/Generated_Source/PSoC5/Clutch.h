/*******************************************************************************
* File Name: Clutch.h  
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

#if !defined(CY_PINS_Clutch_H) /* Pins Clutch_H */
#define CY_PINS_Clutch_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Clutch_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Clutch__PORT == 15 && ((Clutch__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Clutch_Write(uint8 value) ;
void    Clutch_SetDriveMode(uint8 mode) ;
uint8   Clutch_ReadDataReg(void) ;
uint8   Clutch_Read(void) ;
uint8   Clutch_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Clutch_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Clutch_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Clutch_DM_RES_UP          PIN_DM_RES_UP
#define Clutch_DM_RES_DWN         PIN_DM_RES_DWN
#define Clutch_DM_OD_LO           PIN_DM_OD_LO
#define Clutch_DM_OD_HI           PIN_DM_OD_HI
#define Clutch_DM_STRONG          PIN_DM_STRONG
#define Clutch_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Clutch_MASK               Clutch__MASK
#define Clutch_SHIFT              Clutch__SHIFT
#define Clutch_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Clutch_PS                     (* (reg8 *) Clutch__PS)
/* Data Register */
#define Clutch_DR                     (* (reg8 *) Clutch__DR)
/* Port Number */
#define Clutch_PRT_NUM                (* (reg8 *) Clutch__PRT) 
/* Connect to Analog Globals */                                                  
#define Clutch_AG                     (* (reg8 *) Clutch__AG)                       
/* Analog MUX bux enable */
#define Clutch_AMUX                   (* (reg8 *) Clutch__AMUX) 
/* Bidirectional Enable */                                                        
#define Clutch_BIE                    (* (reg8 *) Clutch__BIE)
/* Bit-mask for Aliased Register Access */
#define Clutch_BIT_MASK               (* (reg8 *) Clutch__BIT_MASK)
/* Bypass Enable */
#define Clutch_BYP                    (* (reg8 *) Clutch__BYP)
/* Port wide control signals */                                                   
#define Clutch_CTL                    (* (reg8 *) Clutch__CTL)
/* Drive Modes */
#define Clutch_DM0                    (* (reg8 *) Clutch__DM0) 
#define Clutch_DM1                    (* (reg8 *) Clutch__DM1)
#define Clutch_DM2                    (* (reg8 *) Clutch__DM2) 
/* Input Buffer Disable Override */
#define Clutch_INP_DIS                (* (reg8 *) Clutch__INP_DIS)
/* LCD Common or Segment Drive */
#define Clutch_LCD_COM_SEG            (* (reg8 *) Clutch__LCD_COM_SEG)
/* Enable Segment LCD */
#define Clutch_LCD_EN                 (* (reg8 *) Clutch__LCD_EN)
/* Slew Rate Control */
#define Clutch_SLW                    (* (reg8 *) Clutch__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Clutch_PRTDSI__CAPS_SEL       (* (reg8 *) Clutch__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Clutch_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Clutch__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Clutch_PRTDSI__OE_SEL0        (* (reg8 *) Clutch__PRTDSI__OE_SEL0) 
#define Clutch_PRTDSI__OE_SEL1        (* (reg8 *) Clutch__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Clutch_PRTDSI__OUT_SEL0       (* (reg8 *) Clutch__PRTDSI__OUT_SEL0) 
#define Clutch_PRTDSI__OUT_SEL1       (* (reg8 *) Clutch__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Clutch_PRTDSI__SYNC_OUT       (* (reg8 *) Clutch__PRTDSI__SYNC_OUT) 


#if defined(Clutch__INTSTAT)  /* Interrupt Registers */

    #define Clutch_INTSTAT                (* (reg8 *) Clutch__INTSTAT)
    #define Clutch_SNAP                   (* (reg8 *) Clutch__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Clutch_H */


/* [] END OF FILE */
