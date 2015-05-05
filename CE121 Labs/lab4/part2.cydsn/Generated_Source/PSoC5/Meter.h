/*******************************************************************************
* File Name: Meter.h  
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

#if !defined(CY_PINS_Meter_H) /* Pins Meter_H */
#define CY_PINS_Meter_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Meter_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Meter__PORT == 15 && ((Meter__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Meter_Write(uint8 value) ;
void    Meter_SetDriveMode(uint8 mode) ;
uint8   Meter_ReadDataReg(void) ;
uint8   Meter_Read(void) ;
uint8   Meter_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Meter_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Meter_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Meter_DM_RES_UP          PIN_DM_RES_UP
#define Meter_DM_RES_DWN         PIN_DM_RES_DWN
#define Meter_DM_OD_LO           PIN_DM_OD_LO
#define Meter_DM_OD_HI           PIN_DM_OD_HI
#define Meter_DM_STRONG          PIN_DM_STRONG
#define Meter_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Meter_MASK               Meter__MASK
#define Meter_SHIFT              Meter__SHIFT
#define Meter_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Meter_PS                     (* (reg8 *) Meter__PS)
/* Data Register */
#define Meter_DR                     (* (reg8 *) Meter__DR)
/* Port Number */
#define Meter_PRT_NUM                (* (reg8 *) Meter__PRT) 
/* Connect to Analog Globals */                                                  
#define Meter_AG                     (* (reg8 *) Meter__AG)                       
/* Analog MUX bux enable */
#define Meter_AMUX                   (* (reg8 *) Meter__AMUX) 
/* Bidirectional Enable */                                                        
#define Meter_BIE                    (* (reg8 *) Meter__BIE)
/* Bit-mask for Aliased Register Access */
#define Meter_BIT_MASK               (* (reg8 *) Meter__BIT_MASK)
/* Bypass Enable */
#define Meter_BYP                    (* (reg8 *) Meter__BYP)
/* Port wide control signals */                                                   
#define Meter_CTL                    (* (reg8 *) Meter__CTL)
/* Drive Modes */
#define Meter_DM0                    (* (reg8 *) Meter__DM0) 
#define Meter_DM1                    (* (reg8 *) Meter__DM1)
#define Meter_DM2                    (* (reg8 *) Meter__DM2) 
/* Input Buffer Disable Override */
#define Meter_INP_DIS                (* (reg8 *) Meter__INP_DIS)
/* LCD Common or Segment Drive */
#define Meter_LCD_COM_SEG            (* (reg8 *) Meter__LCD_COM_SEG)
/* Enable Segment LCD */
#define Meter_LCD_EN                 (* (reg8 *) Meter__LCD_EN)
/* Slew Rate Control */
#define Meter_SLW                    (* (reg8 *) Meter__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Meter_PRTDSI__CAPS_SEL       (* (reg8 *) Meter__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Meter_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Meter__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Meter_PRTDSI__OE_SEL0        (* (reg8 *) Meter__PRTDSI__OE_SEL0) 
#define Meter_PRTDSI__OE_SEL1        (* (reg8 *) Meter__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Meter_PRTDSI__OUT_SEL0       (* (reg8 *) Meter__PRTDSI__OUT_SEL0) 
#define Meter_PRTDSI__OUT_SEL1       (* (reg8 *) Meter__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Meter_PRTDSI__SYNC_OUT       (* (reg8 *) Meter__PRTDSI__SYNC_OUT) 


#if defined(Meter__INTSTAT)  /* Interrupt Registers */

    #define Meter_INTSTAT                (* (reg8 *) Meter__INTSTAT)
    #define Meter_SNAP                   (* (reg8 *) Meter__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Meter_H */


/* [] END OF FILE */
