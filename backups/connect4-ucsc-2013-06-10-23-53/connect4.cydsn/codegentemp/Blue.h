/*******************************************************************************
* File Name: Blue.h  
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

#if !defined(CY_PINS_Blue_H) /* Pins Blue_H */
#define CY_PINS_Blue_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Blue_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Blue__PORT == 15 && ((Blue__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Blue_Write(uint8 value) ;
void    Blue_SetDriveMode(uint8 mode) ;
uint8   Blue_ReadDataReg(void) ;
uint8   Blue_Read(void) ;
uint8   Blue_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Blue_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Blue_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Blue_DM_RES_UP          PIN_DM_RES_UP
#define Blue_DM_RES_DWN         PIN_DM_RES_DWN
#define Blue_DM_OD_LO           PIN_DM_OD_LO
#define Blue_DM_OD_HI           PIN_DM_OD_HI
#define Blue_DM_STRONG          PIN_DM_STRONG
#define Blue_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Blue_MASK               Blue__MASK
#define Blue_SHIFT              Blue__SHIFT
#define Blue_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Blue_PS                     (* (reg8 *) Blue__PS)
/* Data Register */
#define Blue_DR                     (* (reg8 *) Blue__DR)
/* Port Number */
#define Blue_PRT_NUM                (* (reg8 *) Blue__PRT) 
/* Connect to Analog Globals */                                                  
#define Blue_AG                     (* (reg8 *) Blue__AG)                       
/* Analog MUX bux enable */
#define Blue_AMUX                   (* (reg8 *) Blue__AMUX) 
/* Bidirectional Enable */                                                        
#define Blue_BIE                    (* (reg8 *) Blue__BIE)
/* Bit-mask for Aliased Register Access */
#define Blue_BIT_MASK               (* (reg8 *) Blue__BIT_MASK)
/* Bypass Enable */
#define Blue_BYP                    (* (reg8 *) Blue__BYP)
/* Port wide control signals */                                                   
#define Blue_CTL                    (* (reg8 *) Blue__CTL)
/* Drive Modes */
#define Blue_DM0                    (* (reg8 *) Blue__DM0) 
#define Blue_DM1                    (* (reg8 *) Blue__DM1)
#define Blue_DM2                    (* (reg8 *) Blue__DM2) 
/* Input Buffer Disable Override */
#define Blue_INP_DIS                (* (reg8 *) Blue__INP_DIS)
/* LCD Common or Segment Drive */
#define Blue_LCD_COM_SEG            (* (reg8 *) Blue__LCD_COM_SEG)
/* Enable Segment LCD */
#define Blue_LCD_EN                 (* (reg8 *) Blue__LCD_EN)
/* Slew Rate Control */
#define Blue_SLW                    (* (reg8 *) Blue__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Blue_PRTDSI__CAPS_SEL       (* (reg8 *) Blue__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Blue_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Blue__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Blue_PRTDSI__OE_SEL0        (* (reg8 *) Blue__PRTDSI__OE_SEL0) 
#define Blue_PRTDSI__OE_SEL1        (* (reg8 *) Blue__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Blue_PRTDSI__OUT_SEL0       (* (reg8 *) Blue__PRTDSI__OUT_SEL0) 
#define Blue_PRTDSI__OUT_SEL1       (* (reg8 *) Blue__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Blue_PRTDSI__SYNC_OUT       (* (reg8 *) Blue__PRTDSI__SYNC_OUT) 


#if defined(Blue__INTSTAT)  /* Interrupt Registers */

    #define Blue_INTSTAT                (* (reg8 *) Blue__INTSTAT)
    #define Blue_SNAP                   (* (reg8 *) Blue__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Blue_H */


/* [] END OF FILE */
