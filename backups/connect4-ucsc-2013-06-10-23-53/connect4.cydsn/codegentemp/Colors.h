/*******************************************************************************
* File Name: Colors.h  
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

#if !defined(CY_PINS_Colors_H) /* Pins Colors_H */
#define CY_PINS_Colors_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Colors_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Colors__PORT == 15 && ((Colors__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Colors_Write(uint8 value) ;
void    Colors_SetDriveMode(uint8 mode) ;
uint8   Colors_ReadDataReg(void) ;
uint8   Colors_Read(void) ;
uint8   Colors_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Colors_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Colors_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Colors_DM_RES_UP          PIN_DM_RES_UP
#define Colors_DM_RES_DWN         PIN_DM_RES_DWN
#define Colors_DM_OD_LO           PIN_DM_OD_LO
#define Colors_DM_OD_HI           PIN_DM_OD_HI
#define Colors_DM_STRONG          PIN_DM_STRONG
#define Colors_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Colors_MASK               Colors__MASK
#define Colors_SHIFT              Colors__SHIFT
#define Colors_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Colors_PS                     (* (reg8 *) Colors__PS)
/* Data Register */
#define Colors_DR                     (* (reg8 *) Colors__DR)
/* Port Number */
#define Colors_PRT_NUM                (* (reg8 *) Colors__PRT) 
/* Connect to Analog Globals */                                                  
#define Colors_AG                     (* (reg8 *) Colors__AG)                       
/* Analog MUX bux enable */
#define Colors_AMUX                   (* (reg8 *) Colors__AMUX) 
/* Bidirectional Enable */                                                        
#define Colors_BIE                    (* (reg8 *) Colors__BIE)
/* Bit-mask for Aliased Register Access */
#define Colors_BIT_MASK               (* (reg8 *) Colors__BIT_MASK)
/* Bypass Enable */
#define Colors_BYP                    (* (reg8 *) Colors__BYP)
/* Port wide control signals */                                                   
#define Colors_CTL                    (* (reg8 *) Colors__CTL)
/* Drive Modes */
#define Colors_DM0                    (* (reg8 *) Colors__DM0) 
#define Colors_DM1                    (* (reg8 *) Colors__DM1)
#define Colors_DM2                    (* (reg8 *) Colors__DM2) 
/* Input Buffer Disable Override */
#define Colors_INP_DIS                (* (reg8 *) Colors__INP_DIS)
/* LCD Common or Segment Drive */
#define Colors_LCD_COM_SEG            (* (reg8 *) Colors__LCD_COM_SEG)
/* Enable Segment LCD */
#define Colors_LCD_EN                 (* (reg8 *) Colors__LCD_EN)
/* Slew Rate Control */
#define Colors_SLW                    (* (reg8 *) Colors__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Colors_PRTDSI__CAPS_SEL       (* (reg8 *) Colors__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Colors_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Colors__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Colors_PRTDSI__OE_SEL0        (* (reg8 *) Colors__PRTDSI__OE_SEL0) 
#define Colors_PRTDSI__OE_SEL1        (* (reg8 *) Colors__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Colors_PRTDSI__OUT_SEL0       (* (reg8 *) Colors__PRTDSI__OUT_SEL0) 
#define Colors_PRTDSI__OUT_SEL1       (* (reg8 *) Colors__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Colors_PRTDSI__SYNC_OUT       (* (reg8 *) Colors__PRTDSI__SYNC_OUT) 


#if defined(Colors__INTSTAT)  /* Interrupt Registers */

    #define Colors_INTSTAT                (* (reg8 *) Colors__INTSTAT)
    #define Colors_SNAP                   (* (reg8 *) Colors__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Colors_H */


/* [] END OF FILE */
