/*******************************************************************************
* File Name: Remote_Toggle.h  
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

#if !defined(CY_PINS_Remote_Toggle_H) /* Pins Remote_Toggle_H */
#define CY_PINS_Remote_Toggle_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Remote_Toggle_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Remote_Toggle__PORT == 15 && ((Remote_Toggle__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Remote_Toggle_Write(uint8 value) ;
void    Remote_Toggle_SetDriveMode(uint8 mode) ;
uint8   Remote_Toggle_ReadDataReg(void) ;
uint8   Remote_Toggle_Read(void) ;
uint8   Remote_Toggle_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Remote_Toggle_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Remote_Toggle_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Remote_Toggle_DM_RES_UP          PIN_DM_RES_UP
#define Remote_Toggle_DM_RES_DWN         PIN_DM_RES_DWN
#define Remote_Toggle_DM_OD_LO           PIN_DM_OD_LO
#define Remote_Toggle_DM_OD_HI           PIN_DM_OD_HI
#define Remote_Toggle_DM_STRONG          PIN_DM_STRONG
#define Remote_Toggle_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Remote_Toggle_MASK               Remote_Toggle__MASK
#define Remote_Toggle_SHIFT              Remote_Toggle__SHIFT
#define Remote_Toggle_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Remote_Toggle_PS                     (* (reg8 *) Remote_Toggle__PS)
/* Data Register */
#define Remote_Toggle_DR                     (* (reg8 *) Remote_Toggle__DR)
/* Port Number */
#define Remote_Toggle_PRT_NUM                (* (reg8 *) Remote_Toggle__PRT) 
/* Connect to Analog Globals */                                                  
#define Remote_Toggle_AG                     (* (reg8 *) Remote_Toggle__AG)                       
/* Analog MUX bux enable */
#define Remote_Toggle_AMUX                   (* (reg8 *) Remote_Toggle__AMUX) 
/* Bidirectional Enable */                                                        
#define Remote_Toggle_BIE                    (* (reg8 *) Remote_Toggle__BIE)
/* Bit-mask for Aliased Register Access */
#define Remote_Toggle_BIT_MASK               (* (reg8 *) Remote_Toggle__BIT_MASK)
/* Bypass Enable */
#define Remote_Toggle_BYP                    (* (reg8 *) Remote_Toggle__BYP)
/* Port wide control signals */                                                   
#define Remote_Toggle_CTL                    (* (reg8 *) Remote_Toggle__CTL)
/* Drive Modes */
#define Remote_Toggle_DM0                    (* (reg8 *) Remote_Toggle__DM0) 
#define Remote_Toggle_DM1                    (* (reg8 *) Remote_Toggle__DM1)
#define Remote_Toggle_DM2                    (* (reg8 *) Remote_Toggle__DM2) 
/* Input Buffer Disable Override */
#define Remote_Toggle_INP_DIS                (* (reg8 *) Remote_Toggle__INP_DIS)
/* LCD Common or Segment Drive */
#define Remote_Toggle_LCD_COM_SEG            (* (reg8 *) Remote_Toggle__LCD_COM_SEG)
/* Enable Segment LCD */
#define Remote_Toggle_LCD_EN                 (* (reg8 *) Remote_Toggle__LCD_EN)
/* Slew Rate Control */
#define Remote_Toggle_SLW                    (* (reg8 *) Remote_Toggle__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Remote_Toggle_PRTDSI__CAPS_SEL       (* (reg8 *) Remote_Toggle__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Remote_Toggle_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Remote_Toggle__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Remote_Toggle_PRTDSI__OE_SEL0        (* (reg8 *) Remote_Toggle__PRTDSI__OE_SEL0) 
#define Remote_Toggle_PRTDSI__OE_SEL1        (* (reg8 *) Remote_Toggle__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Remote_Toggle_PRTDSI__OUT_SEL0       (* (reg8 *) Remote_Toggle__PRTDSI__OUT_SEL0) 
#define Remote_Toggle_PRTDSI__OUT_SEL1       (* (reg8 *) Remote_Toggle__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Remote_Toggle_PRTDSI__SYNC_OUT       (* (reg8 *) Remote_Toggle__PRTDSI__SYNC_OUT) 


#if defined(Remote_Toggle__INTSTAT)  /* Interrupt Registers */

    #define Remote_Toggle_INTSTAT                (* (reg8 *) Remote_Toggle__INTSTAT)
    #define Remote_Toggle_SNAP                   (* (reg8 *) Remote_Toggle__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Remote_Toggle_H */


/* [] END OF FILE */
