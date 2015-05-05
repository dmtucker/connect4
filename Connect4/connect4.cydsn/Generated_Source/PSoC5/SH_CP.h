/*******************************************************************************
* File Name: SH_CP.h  
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

#if !defined(CY_PINS_SH_CP_H) /* Pins SH_CP_H */
#define CY_PINS_SH_CP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SH_CP_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SH_CP__PORT == 15 && ((SH_CP__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SH_CP_Write(uint8 value) ;
void    SH_CP_SetDriveMode(uint8 mode) ;
uint8   SH_CP_ReadDataReg(void) ;
uint8   SH_CP_Read(void) ;
uint8   SH_CP_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SH_CP_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SH_CP_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SH_CP_DM_RES_UP          PIN_DM_RES_UP
#define SH_CP_DM_RES_DWN         PIN_DM_RES_DWN
#define SH_CP_DM_OD_LO           PIN_DM_OD_LO
#define SH_CP_DM_OD_HI           PIN_DM_OD_HI
#define SH_CP_DM_STRONG          PIN_DM_STRONG
#define SH_CP_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SH_CP_MASK               SH_CP__MASK
#define SH_CP_SHIFT              SH_CP__SHIFT
#define SH_CP_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SH_CP_PS                     (* (reg8 *) SH_CP__PS)
/* Data Register */
#define SH_CP_DR                     (* (reg8 *) SH_CP__DR)
/* Port Number */
#define SH_CP_PRT_NUM                (* (reg8 *) SH_CP__PRT) 
/* Connect to Analog Globals */                                                  
#define SH_CP_AG                     (* (reg8 *) SH_CP__AG)                       
/* Analog MUX bux enable */
#define SH_CP_AMUX                   (* (reg8 *) SH_CP__AMUX) 
/* Bidirectional Enable */                                                        
#define SH_CP_BIE                    (* (reg8 *) SH_CP__BIE)
/* Bit-mask for Aliased Register Access */
#define SH_CP_BIT_MASK               (* (reg8 *) SH_CP__BIT_MASK)
/* Bypass Enable */
#define SH_CP_BYP                    (* (reg8 *) SH_CP__BYP)
/* Port wide control signals */                                                   
#define SH_CP_CTL                    (* (reg8 *) SH_CP__CTL)
/* Drive Modes */
#define SH_CP_DM0                    (* (reg8 *) SH_CP__DM0) 
#define SH_CP_DM1                    (* (reg8 *) SH_CP__DM1)
#define SH_CP_DM2                    (* (reg8 *) SH_CP__DM2) 
/* Input Buffer Disable Override */
#define SH_CP_INP_DIS                (* (reg8 *) SH_CP__INP_DIS)
/* LCD Common or Segment Drive */
#define SH_CP_LCD_COM_SEG            (* (reg8 *) SH_CP__LCD_COM_SEG)
/* Enable Segment LCD */
#define SH_CP_LCD_EN                 (* (reg8 *) SH_CP__LCD_EN)
/* Slew Rate Control */
#define SH_CP_SLW                    (* (reg8 *) SH_CP__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SH_CP_PRTDSI__CAPS_SEL       (* (reg8 *) SH_CP__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SH_CP_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SH_CP__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SH_CP_PRTDSI__OE_SEL0        (* (reg8 *) SH_CP__PRTDSI__OE_SEL0) 
#define SH_CP_PRTDSI__OE_SEL1        (* (reg8 *) SH_CP__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SH_CP_PRTDSI__OUT_SEL0       (* (reg8 *) SH_CP__PRTDSI__OUT_SEL0) 
#define SH_CP_PRTDSI__OUT_SEL1       (* (reg8 *) SH_CP__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SH_CP_PRTDSI__SYNC_OUT       (* (reg8 *) SH_CP__PRTDSI__SYNC_OUT) 


#if defined(SH_CP__INTSTAT)  /* Interrupt Registers */

    #define SH_CP_INTSTAT                (* (reg8 *) SH_CP__INTSTAT)
    #define SH_CP_SNAP                   (* (reg8 *) SH_CP__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SH_CP_H */


/* [] END OF FILE */
