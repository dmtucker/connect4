/*******************************************************************************
* File Name: Error.h  
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

#if !defined(CY_PINS_Error_H) /* Pins Error_H */
#define CY_PINS_Error_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Error_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Error__PORT == 15 && ((Error__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Error_Write(uint8 value) ;
void    Error_SetDriveMode(uint8 mode) ;
uint8   Error_ReadDataReg(void) ;
uint8   Error_Read(void) ;
uint8   Error_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Error_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Error_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Error_DM_RES_UP          PIN_DM_RES_UP
#define Error_DM_RES_DWN         PIN_DM_RES_DWN
#define Error_DM_OD_LO           PIN_DM_OD_LO
#define Error_DM_OD_HI           PIN_DM_OD_HI
#define Error_DM_STRONG          PIN_DM_STRONG
#define Error_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Error_MASK               Error__MASK
#define Error_SHIFT              Error__SHIFT
#define Error_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Error_PS                     (* (reg8 *) Error__PS)
/* Data Register */
#define Error_DR                     (* (reg8 *) Error__DR)
/* Port Number */
#define Error_PRT_NUM                (* (reg8 *) Error__PRT) 
/* Connect to Analog Globals */                                                  
#define Error_AG                     (* (reg8 *) Error__AG)                       
/* Analog MUX bux enable */
#define Error_AMUX                   (* (reg8 *) Error__AMUX) 
/* Bidirectional Enable */                                                        
#define Error_BIE                    (* (reg8 *) Error__BIE)
/* Bit-mask for Aliased Register Access */
#define Error_BIT_MASK               (* (reg8 *) Error__BIT_MASK)
/* Bypass Enable */
#define Error_BYP                    (* (reg8 *) Error__BYP)
/* Port wide control signals */                                                   
#define Error_CTL                    (* (reg8 *) Error__CTL)
/* Drive Modes */
#define Error_DM0                    (* (reg8 *) Error__DM0) 
#define Error_DM1                    (* (reg8 *) Error__DM1)
#define Error_DM2                    (* (reg8 *) Error__DM2) 
/* Input Buffer Disable Override */
#define Error_INP_DIS                (* (reg8 *) Error__INP_DIS)
/* LCD Common or Segment Drive */
#define Error_LCD_COM_SEG            (* (reg8 *) Error__LCD_COM_SEG)
/* Enable Segment LCD */
#define Error_LCD_EN                 (* (reg8 *) Error__LCD_EN)
/* Slew Rate Control */
#define Error_SLW                    (* (reg8 *) Error__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Error_PRTDSI__CAPS_SEL       (* (reg8 *) Error__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Error_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Error__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Error_PRTDSI__OE_SEL0        (* (reg8 *) Error__PRTDSI__OE_SEL0) 
#define Error_PRTDSI__OE_SEL1        (* (reg8 *) Error__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Error_PRTDSI__OUT_SEL0       (* (reg8 *) Error__PRTDSI__OUT_SEL0) 
#define Error_PRTDSI__OUT_SEL1       (* (reg8 *) Error__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Error_PRTDSI__SYNC_OUT       (* (reg8 *) Error__PRTDSI__SYNC_OUT) 


#if defined(Error__INTSTAT)  /* Interrupt Registers */

    #define Error_INTSTAT                (* (reg8 *) Error__INTSTAT)
    #define Error_SNAP                   (* (reg8 *) Error__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Error_H */


/* [] END OF FILE */
