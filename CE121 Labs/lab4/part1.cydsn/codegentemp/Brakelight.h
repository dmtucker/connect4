/*******************************************************************************
* File Name: Brakelight.h  
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

#if !defined(CY_PINS_Brakelight_H) /* Pins Brakelight_H */
#define CY_PINS_Brakelight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Brakelight_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Brakelight__PORT == 15 && ((Brakelight__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Brakelight_Write(uint8 value) ;
void    Brakelight_SetDriveMode(uint8 mode) ;
uint8   Brakelight_ReadDataReg(void) ;
uint8   Brakelight_Read(void) ;
uint8   Brakelight_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Brakelight_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Brakelight_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Brakelight_DM_RES_UP          PIN_DM_RES_UP
#define Brakelight_DM_RES_DWN         PIN_DM_RES_DWN
#define Brakelight_DM_OD_LO           PIN_DM_OD_LO
#define Brakelight_DM_OD_HI           PIN_DM_OD_HI
#define Brakelight_DM_STRONG          PIN_DM_STRONG
#define Brakelight_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Brakelight_MASK               Brakelight__MASK
#define Brakelight_SHIFT              Brakelight__SHIFT
#define Brakelight_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Brakelight_PS                     (* (reg8 *) Brakelight__PS)
/* Data Register */
#define Brakelight_DR                     (* (reg8 *) Brakelight__DR)
/* Port Number */
#define Brakelight_PRT_NUM                (* (reg8 *) Brakelight__PRT) 
/* Connect to Analog Globals */                                                  
#define Brakelight_AG                     (* (reg8 *) Brakelight__AG)                       
/* Analog MUX bux enable */
#define Brakelight_AMUX                   (* (reg8 *) Brakelight__AMUX) 
/* Bidirectional Enable */                                                        
#define Brakelight_BIE                    (* (reg8 *) Brakelight__BIE)
/* Bit-mask for Aliased Register Access */
#define Brakelight_BIT_MASK               (* (reg8 *) Brakelight__BIT_MASK)
/* Bypass Enable */
#define Brakelight_BYP                    (* (reg8 *) Brakelight__BYP)
/* Port wide control signals */                                                   
#define Brakelight_CTL                    (* (reg8 *) Brakelight__CTL)
/* Drive Modes */
#define Brakelight_DM0                    (* (reg8 *) Brakelight__DM0) 
#define Brakelight_DM1                    (* (reg8 *) Brakelight__DM1)
#define Brakelight_DM2                    (* (reg8 *) Brakelight__DM2) 
/* Input Buffer Disable Override */
#define Brakelight_INP_DIS                (* (reg8 *) Brakelight__INP_DIS)
/* LCD Common or Segment Drive */
#define Brakelight_LCD_COM_SEG            (* (reg8 *) Brakelight__LCD_COM_SEG)
/* Enable Segment LCD */
#define Brakelight_LCD_EN                 (* (reg8 *) Brakelight__LCD_EN)
/* Slew Rate Control */
#define Brakelight_SLW                    (* (reg8 *) Brakelight__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Brakelight_PRTDSI__CAPS_SEL       (* (reg8 *) Brakelight__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Brakelight_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Brakelight__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Brakelight_PRTDSI__OE_SEL0        (* (reg8 *) Brakelight__PRTDSI__OE_SEL0) 
#define Brakelight_PRTDSI__OE_SEL1        (* (reg8 *) Brakelight__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Brakelight_PRTDSI__OUT_SEL0       (* (reg8 *) Brakelight__PRTDSI__OUT_SEL0) 
#define Brakelight_PRTDSI__OUT_SEL1       (* (reg8 *) Brakelight__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Brakelight_PRTDSI__SYNC_OUT       (* (reg8 *) Brakelight__PRTDSI__SYNC_OUT) 


#if defined(Brakelight__INTSTAT)  /* Interrupt Registers */

    #define Brakelight_INTSTAT                (* (reg8 *) Brakelight__INTSTAT)
    #define Brakelight_SNAP                   (* (reg8 *) Brakelight__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Brakelight_H */


/* [] END OF FILE */
