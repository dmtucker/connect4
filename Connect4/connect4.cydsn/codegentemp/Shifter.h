/*******************************************************************************
* File Name: Shifter.h  
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

#if !defined(CY_PINS_Shifter_H) /* Pins Shifter_H */
#define CY_PINS_Shifter_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Shifter_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Shifter__PORT == 15 && ((Shifter__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Shifter_Write(uint8 value) ;
void    Shifter_SetDriveMode(uint8 mode) ;
uint8   Shifter_ReadDataReg(void) ;
uint8   Shifter_Read(void) ;
uint8   Shifter_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Shifter_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Shifter_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Shifter_DM_RES_UP          PIN_DM_RES_UP
#define Shifter_DM_RES_DWN         PIN_DM_RES_DWN
#define Shifter_DM_OD_LO           PIN_DM_OD_LO
#define Shifter_DM_OD_HI           PIN_DM_OD_HI
#define Shifter_DM_STRONG          PIN_DM_STRONG
#define Shifter_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Shifter_MASK               Shifter__MASK
#define Shifter_SHIFT              Shifter__SHIFT
#define Shifter_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Shifter_PS                     (* (reg8 *) Shifter__PS)
/* Data Register */
#define Shifter_DR                     (* (reg8 *) Shifter__DR)
/* Port Number */
#define Shifter_PRT_NUM                (* (reg8 *) Shifter__PRT) 
/* Connect to Analog Globals */                                                  
#define Shifter_AG                     (* (reg8 *) Shifter__AG)                       
/* Analog MUX bux enable */
#define Shifter_AMUX                   (* (reg8 *) Shifter__AMUX) 
/* Bidirectional Enable */                                                        
#define Shifter_BIE                    (* (reg8 *) Shifter__BIE)
/* Bit-mask for Aliased Register Access */
#define Shifter_BIT_MASK               (* (reg8 *) Shifter__BIT_MASK)
/* Bypass Enable */
#define Shifter_BYP                    (* (reg8 *) Shifter__BYP)
/* Port wide control signals */                                                   
#define Shifter_CTL                    (* (reg8 *) Shifter__CTL)
/* Drive Modes */
#define Shifter_DM0                    (* (reg8 *) Shifter__DM0) 
#define Shifter_DM1                    (* (reg8 *) Shifter__DM1)
#define Shifter_DM2                    (* (reg8 *) Shifter__DM2) 
/* Input Buffer Disable Override */
#define Shifter_INP_DIS                (* (reg8 *) Shifter__INP_DIS)
/* LCD Common or Segment Drive */
#define Shifter_LCD_COM_SEG            (* (reg8 *) Shifter__LCD_COM_SEG)
/* Enable Segment LCD */
#define Shifter_LCD_EN                 (* (reg8 *) Shifter__LCD_EN)
/* Slew Rate Control */
#define Shifter_SLW                    (* (reg8 *) Shifter__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Shifter_PRTDSI__CAPS_SEL       (* (reg8 *) Shifter__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Shifter_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Shifter__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Shifter_PRTDSI__OE_SEL0        (* (reg8 *) Shifter__PRTDSI__OE_SEL0) 
#define Shifter_PRTDSI__OE_SEL1        (* (reg8 *) Shifter__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Shifter_PRTDSI__OUT_SEL0       (* (reg8 *) Shifter__PRTDSI__OUT_SEL0) 
#define Shifter_PRTDSI__OUT_SEL1       (* (reg8 *) Shifter__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Shifter_PRTDSI__SYNC_OUT       (* (reg8 *) Shifter__PRTDSI__SYNC_OUT) 


#if defined(Shifter__INTSTAT)  /* Interrupt Registers */

    #define Shifter_INTSTAT                (* (reg8 *) Shifter__INTSTAT)
    #define Shifter_SNAP                   (* (reg8 *) Shifter__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Shifter_H */


/* [] END OF FILE */
