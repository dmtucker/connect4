/*******************************************************************************
* File Name: Pin_16.h  
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

#if !defined(CY_PINS_Pin_16_H) /* Pins Pin_16_H */
#define CY_PINS_Pin_16_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_16_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_16__PORT == 15 && ((Pin_16__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_16_Write(uint8 value) ;
void    Pin_16_SetDriveMode(uint8 mode) ;
uint8   Pin_16_ReadDataReg(void) ;
uint8   Pin_16_Read(void) ;
uint8   Pin_16_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_16_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pin_16_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pin_16_DM_RES_UP          PIN_DM_RES_UP
#define Pin_16_DM_RES_DWN         PIN_DM_RES_DWN
#define Pin_16_DM_OD_LO           PIN_DM_OD_LO
#define Pin_16_DM_OD_HI           PIN_DM_OD_HI
#define Pin_16_DM_STRONG          PIN_DM_STRONG
#define Pin_16_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pin_16_MASK               Pin_16__MASK
#define Pin_16_SHIFT              Pin_16__SHIFT
#define Pin_16_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_16_PS                     (* (reg8 *) Pin_16__PS)
/* Data Register */
#define Pin_16_DR                     (* (reg8 *) Pin_16__DR)
/* Port Number */
#define Pin_16_PRT_NUM                (* (reg8 *) Pin_16__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_16_AG                     (* (reg8 *) Pin_16__AG)                       
/* Analog MUX bux enable */
#define Pin_16_AMUX                   (* (reg8 *) Pin_16__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_16_BIE                    (* (reg8 *) Pin_16__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_16_BIT_MASK               (* (reg8 *) Pin_16__BIT_MASK)
/* Bypass Enable */
#define Pin_16_BYP                    (* (reg8 *) Pin_16__BYP)
/* Port wide control signals */                                                   
#define Pin_16_CTL                    (* (reg8 *) Pin_16__CTL)
/* Drive Modes */
#define Pin_16_DM0                    (* (reg8 *) Pin_16__DM0) 
#define Pin_16_DM1                    (* (reg8 *) Pin_16__DM1)
#define Pin_16_DM2                    (* (reg8 *) Pin_16__DM2) 
/* Input Buffer Disable Override */
#define Pin_16_INP_DIS                (* (reg8 *) Pin_16__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_16_LCD_COM_SEG            (* (reg8 *) Pin_16__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_16_LCD_EN                 (* (reg8 *) Pin_16__LCD_EN)
/* Slew Rate Control */
#define Pin_16_SLW                    (* (reg8 *) Pin_16__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_16_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_16__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_16_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_16__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_16_PRTDSI__OE_SEL0        (* (reg8 *) Pin_16__PRTDSI__OE_SEL0) 
#define Pin_16_PRTDSI__OE_SEL1        (* (reg8 *) Pin_16__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_16_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_16__PRTDSI__OUT_SEL0) 
#define Pin_16_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_16__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_16_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_16__PRTDSI__SYNC_OUT) 


#if defined(Pin_16__INTSTAT)  /* Interrupt Registers */

    #define Pin_16_INTSTAT                (* (reg8 *) Pin_16__INTSTAT)
    #define Pin_16_SNAP                   (* (reg8 *) Pin_16__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_16_H */


/* [] END OF FILE */
