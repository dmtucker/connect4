/*******************************************************************************
* File Name: R8.h  
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

#if !defined(CY_PINS_R8_H) /* Pins R8_H */
#define CY_PINS_R8_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "R8_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 R8__PORT == 15 && ((R8__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    R8_Write(uint8 value) ;
void    R8_SetDriveMode(uint8 mode) ;
uint8   R8_ReadDataReg(void) ;
uint8   R8_Read(void) ;
uint8   R8_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define R8_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define R8_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define R8_DM_RES_UP          PIN_DM_RES_UP
#define R8_DM_RES_DWN         PIN_DM_RES_DWN
#define R8_DM_OD_LO           PIN_DM_OD_LO
#define R8_DM_OD_HI           PIN_DM_OD_HI
#define R8_DM_STRONG          PIN_DM_STRONG
#define R8_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define R8_MASK               R8__MASK
#define R8_SHIFT              R8__SHIFT
#define R8_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R8_PS                     (* (reg8 *) R8__PS)
/* Data Register */
#define R8_DR                     (* (reg8 *) R8__DR)
/* Port Number */
#define R8_PRT_NUM                (* (reg8 *) R8__PRT) 
/* Connect to Analog Globals */                                                  
#define R8_AG                     (* (reg8 *) R8__AG)                       
/* Analog MUX bux enable */
#define R8_AMUX                   (* (reg8 *) R8__AMUX) 
/* Bidirectional Enable */                                                        
#define R8_BIE                    (* (reg8 *) R8__BIE)
/* Bit-mask for Aliased Register Access */
#define R8_BIT_MASK               (* (reg8 *) R8__BIT_MASK)
/* Bypass Enable */
#define R8_BYP                    (* (reg8 *) R8__BYP)
/* Port wide control signals */                                                   
#define R8_CTL                    (* (reg8 *) R8__CTL)
/* Drive Modes */
#define R8_DM0                    (* (reg8 *) R8__DM0) 
#define R8_DM1                    (* (reg8 *) R8__DM1)
#define R8_DM2                    (* (reg8 *) R8__DM2) 
/* Input Buffer Disable Override */
#define R8_INP_DIS                (* (reg8 *) R8__INP_DIS)
/* LCD Common or Segment Drive */
#define R8_LCD_COM_SEG            (* (reg8 *) R8__LCD_COM_SEG)
/* Enable Segment LCD */
#define R8_LCD_EN                 (* (reg8 *) R8__LCD_EN)
/* Slew Rate Control */
#define R8_SLW                    (* (reg8 *) R8__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define R8_PRTDSI__CAPS_SEL       (* (reg8 *) R8__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define R8_PRTDSI__DBL_SYNC_IN    (* (reg8 *) R8__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define R8_PRTDSI__OE_SEL0        (* (reg8 *) R8__PRTDSI__OE_SEL0) 
#define R8_PRTDSI__OE_SEL1        (* (reg8 *) R8__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define R8_PRTDSI__OUT_SEL0       (* (reg8 *) R8__PRTDSI__OUT_SEL0) 
#define R8_PRTDSI__OUT_SEL1       (* (reg8 *) R8__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define R8_PRTDSI__SYNC_OUT       (* (reg8 *) R8__PRTDSI__SYNC_OUT) 


#if defined(R8__INTSTAT)  /* Interrupt Registers */

    #define R8_INTSTAT                (* (reg8 *) R8__INTSTAT)
    #define R8_SNAP                   (* (reg8 *) R8__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_R8_H */


/* [] END OF FILE */
