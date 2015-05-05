/*******************************************************************************
* File Name: Speed.h  
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

#if !defined(CY_PINS_Speed_H) /* Pins Speed_H */
#define CY_PINS_Speed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Speed_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Speed__PORT == 15 && ((Speed__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Speed_Write(uint8 value) ;
void    Speed_SetDriveMode(uint8 mode) ;
uint8   Speed_ReadDataReg(void) ;
uint8   Speed_Read(void) ;
uint8   Speed_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Speed_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Speed_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Speed_DM_RES_UP          PIN_DM_RES_UP
#define Speed_DM_RES_DWN         PIN_DM_RES_DWN
#define Speed_DM_OD_LO           PIN_DM_OD_LO
#define Speed_DM_OD_HI           PIN_DM_OD_HI
#define Speed_DM_STRONG          PIN_DM_STRONG
#define Speed_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Speed_MASK               Speed__MASK
#define Speed_SHIFT              Speed__SHIFT
#define Speed_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Speed_PS                     (* (reg8 *) Speed__PS)
/* Data Register */
#define Speed_DR                     (* (reg8 *) Speed__DR)
/* Port Number */
#define Speed_PRT_NUM                (* (reg8 *) Speed__PRT) 
/* Connect to Analog Globals */                                                  
#define Speed_AG                     (* (reg8 *) Speed__AG)                       
/* Analog MUX bux enable */
#define Speed_AMUX                   (* (reg8 *) Speed__AMUX) 
/* Bidirectional Enable */                                                        
#define Speed_BIE                    (* (reg8 *) Speed__BIE)
/* Bit-mask for Aliased Register Access */
#define Speed_BIT_MASK               (* (reg8 *) Speed__BIT_MASK)
/* Bypass Enable */
#define Speed_BYP                    (* (reg8 *) Speed__BYP)
/* Port wide control signals */                                                   
#define Speed_CTL                    (* (reg8 *) Speed__CTL)
/* Drive Modes */
#define Speed_DM0                    (* (reg8 *) Speed__DM0) 
#define Speed_DM1                    (* (reg8 *) Speed__DM1)
#define Speed_DM2                    (* (reg8 *) Speed__DM2) 
/* Input Buffer Disable Override */
#define Speed_INP_DIS                (* (reg8 *) Speed__INP_DIS)
/* LCD Common or Segment Drive */
#define Speed_LCD_COM_SEG            (* (reg8 *) Speed__LCD_COM_SEG)
/* Enable Segment LCD */
#define Speed_LCD_EN                 (* (reg8 *) Speed__LCD_EN)
/* Slew Rate Control */
#define Speed_SLW                    (* (reg8 *) Speed__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Speed_PRTDSI__CAPS_SEL       (* (reg8 *) Speed__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Speed_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Speed__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Speed_PRTDSI__OE_SEL0        (* (reg8 *) Speed__PRTDSI__OE_SEL0) 
#define Speed_PRTDSI__OE_SEL1        (* (reg8 *) Speed__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Speed_PRTDSI__OUT_SEL0       (* (reg8 *) Speed__PRTDSI__OUT_SEL0) 
#define Speed_PRTDSI__OUT_SEL1       (* (reg8 *) Speed__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Speed_PRTDSI__SYNC_OUT       (* (reg8 *) Speed__PRTDSI__SYNC_OUT) 


#if defined(Speed__INTSTAT)  /* Interrupt Registers */

    #define Speed_INTSTAT                (* (reg8 *) Speed__INTSTAT)
    #define Speed_SNAP                   (* (reg8 *) Speed__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Speed_H */


/* [] END OF FILE */
