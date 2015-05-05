/*******************************************************************************
* File Name: ST_CP.h  
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

#if !defined(CY_PINS_ST_CP_H) /* Pins ST_CP_H */
#define CY_PINS_ST_CP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ST_CP_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ST_CP__PORT == 15 && ((ST_CP__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ST_CP_Write(uint8 value) ;
void    ST_CP_SetDriveMode(uint8 mode) ;
uint8   ST_CP_ReadDataReg(void) ;
uint8   ST_CP_Read(void) ;
uint8   ST_CP_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ST_CP_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ST_CP_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ST_CP_DM_RES_UP          PIN_DM_RES_UP
#define ST_CP_DM_RES_DWN         PIN_DM_RES_DWN
#define ST_CP_DM_OD_LO           PIN_DM_OD_LO
#define ST_CP_DM_OD_HI           PIN_DM_OD_HI
#define ST_CP_DM_STRONG          PIN_DM_STRONG
#define ST_CP_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ST_CP_MASK               ST_CP__MASK
#define ST_CP_SHIFT              ST_CP__SHIFT
#define ST_CP_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ST_CP_PS                     (* (reg8 *) ST_CP__PS)
/* Data Register */
#define ST_CP_DR                     (* (reg8 *) ST_CP__DR)
/* Port Number */
#define ST_CP_PRT_NUM                (* (reg8 *) ST_CP__PRT) 
/* Connect to Analog Globals */                                                  
#define ST_CP_AG                     (* (reg8 *) ST_CP__AG)                       
/* Analog MUX bux enable */
#define ST_CP_AMUX                   (* (reg8 *) ST_CP__AMUX) 
/* Bidirectional Enable */                                                        
#define ST_CP_BIE                    (* (reg8 *) ST_CP__BIE)
/* Bit-mask for Aliased Register Access */
#define ST_CP_BIT_MASK               (* (reg8 *) ST_CP__BIT_MASK)
/* Bypass Enable */
#define ST_CP_BYP                    (* (reg8 *) ST_CP__BYP)
/* Port wide control signals */                                                   
#define ST_CP_CTL                    (* (reg8 *) ST_CP__CTL)
/* Drive Modes */
#define ST_CP_DM0                    (* (reg8 *) ST_CP__DM0) 
#define ST_CP_DM1                    (* (reg8 *) ST_CP__DM1)
#define ST_CP_DM2                    (* (reg8 *) ST_CP__DM2) 
/* Input Buffer Disable Override */
#define ST_CP_INP_DIS                (* (reg8 *) ST_CP__INP_DIS)
/* LCD Common or Segment Drive */
#define ST_CP_LCD_COM_SEG            (* (reg8 *) ST_CP__LCD_COM_SEG)
/* Enable Segment LCD */
#define ST_CP_LCD_EN                 (* (reg8 *) ST_CP__LCD_EN)
/* Slew Rate Control */
#define ST_CP_SLW                    (* (reg8 *) ST_CP__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ST_CP_PRTDSI__CAPS_SEL       (* (reg8 *) ST_CP__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ST_CP_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ST_CP__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ST_CP_PRTDSI__OE_SEL0        (* (reg8 *) ST_CP__PRTDSI__OE_SEL0) 
#define ST_CP_PRTDSI__OE_SEL1        (* (reg8 *) ST_CP__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ST_CP_PRTDSI__OUT_SEL0       (* (reg8 *) ST_CP__PRTDSI__OUT_SEL0) 
#define ST_CP_PRTDSI__OUT_SEL1       (* (reg8 *) ST_CP__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ST_CP_PRTDSI__SYNC_OUT       (* (reg8 *) ST_CP__PRTDSI__SYNC_OUT) 


#if defined(ST_CP__INTSTAT)  /* Interrupt Registers */

    #define ST_CP_INTSTAT                (* (reg8 *) ST_CP__INTSTAT)
    #define ST_CP_SNAP                   (* (reg8 *) ST_CP__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ST_CP_H */


/* [] END OF FILE */
