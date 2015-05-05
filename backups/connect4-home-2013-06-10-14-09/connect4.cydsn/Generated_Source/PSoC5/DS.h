/*******************************************************************************
* File Name: DS.h  
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

#if !defined(CY_PINS_DS_H) /* Pins DS_H */
#define CY_PINS_DS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DS_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DS__PORT == 15 && ((DS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    DS_Write(uint8 value) ;
void    DS_SetDriveMode(uint8 mode) ;
uint8   DS_ReadDataReg(void) ;
uint8   DS_Read(void) ;
uint8   DS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DS_DM_RES_UP          PIN_DM_RES_UP
#define DS_DM_RES_DWN         PIN_DM_RES_DWN
#define DS_DM_OD_LO           PIN_DM_OD_LO
#define DS_DM_OD_HI           PIN_DM_OD_HI
#define DS_DM_STRONG          PIN_DM_STRONG
#define DS_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DS_MASK               DS__MASK
#define DS_SHIFT              DS__SHIFT
#define DS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DS_PS                     (* (reg8 *) DS__PS)
/* Data Register */
#define DS_DR                     (* (reg8 *) DS__DR)
/* Port Number */
#define DS_PRT_NUM                (* (reg8 *) DS__PRT) 
/* Connect to Analog Globals */                                                  
#define DS_AG                     (* (reg8 *) DS__AG)                       
/* Analog MUX bux enable */
#define DS_AMUX                   (* (reg8 *) DS__AMUX) 
/* Bidirectional Enable */                                                        
#define DS_BIE                    (* (reg8 *) DS__BIE)
/* Bit-mask for Aliased Register Access */
#define DS_BIT_MASK               (* (reg8 *) DS__BIT_MASK)
/* Bypass Enable */
#define DS_BYP                    (* (reg8 *) DS__BYP)
/* Port wide control signals */                                                   
#define DS_CTL                    (* (reg8 *) DS__CTL)
/* Drive Modes */
#define DS_DM0                    (* (reg8 *) DS__DM0) 
#define DS_DM1                    (* (reg8 *) DS__DM1)
#define DS_DM2                    (* (reg8 *) DS__DM2) 
/* Input Buffer Disable Override */
#define DS_INP_DIS                (* (reg8 *) DS__INP_DIS)
/* LCD Common or Segment Drive */
#define DS_LCD_COM_SEG            (* (reg8 *) DS__LCD_COM_SEG)
/* Enable Segment LCD */
#define DS_LCD_EN                 (* (reg8 *) DS__LCD_EN)
/* Slew Rate Control */
#define DS_SLW                    (* (reg8 *) DS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DS_PRTDSI__CAPS_SEL       (* (reg8 *) DS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DS_PRTDSI__OE_SEL0        (* (reg8 *) DS__PRTDSI__OE_SEL0) 
#define DS_PRTDSI__OE_SEL1        (* (reg8 *) DS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DS_PRTDSI__OUT_SEL0       (* (reg8 *) DS__PRTDSI__OUT_SEL0) 
#define DS_PRTDSI__OUT_SEL1       (* (reg8 *) DS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DS_PRTDSI__SYNC_OUT       (* (reg8 *) DS__PRTDSI__SYNC_OUT) 


#if defined(DS__INTSTAT)  /* Interrupt Registers */

    #define DS_INTSTAT                (* (reg8 *) DS__INTSTAT)
    #define DS_SNAP                   (* (reg8 *) DS__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DS_H */


/* [] END OF FILE */
