/*******************************************************************************
* File Name: C1_R.h  
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

#if !defined(CY_PINS_C1_R_H) /* Pins C1_R_H */
#define CY_PINS_C1_R_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "C1_R_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 C1_R__PORT == 15 && ((C1_R__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    C1_R_Write(uint8 value) ;
void    C1_R_SetDriveMode(uint8 mode) ;
uint8   C1_R_ReadDataReg(void) ;
uint8   C1_R_Read(void) ;
uint8   C1_R_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define C1_R_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define C1_R_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define C1_R_DM_RES_UP          PIN_DM_RES_UP
#define C1_R_DM_RES_DWN         PIN_DM_RES_DWN
#define C1_R_DM_OD_LO           PIN_DM_OD_LO
#define C1_R_DM_OD_HI           PIN_DM_OD_HI
#define C1_R_DM_STRONG          PIN_DM_STRONG
#define C1_R_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define C1_R_MASK               C1_R__MASK
#define C1_R_SHIFT              C1_R__SHIFT
#define C1_R_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define C1_R_PS                     (* (reg8 *) C1_R__PS)
/* Data Register */
#define C1_R_DR                     (* (reg8 *) C1_R__DR)
/* Port Number */
#define C1_R_PRT_NUM                (* (reg8 *) C1_R__PRT) 
/* Connect to Analog Globals */                                                  
#define C1_R_AG                     (* (reg8 *) C1_R__AG)                       
/* Analog MUX bux enable */
#define C1_R_AMUX                   (* (reg8 *) C1_R__AMUX) 
/* Bidirectional Enable */                                                        
#define C1_R_BIE                    (* (reg8 *) C1_R__BIE)
/* Bit-mask for Aliased Register Access */
#define C1_R_BIT_MASK               (* (reg8 *) C1_R__BIT_MASK)
/* Bypass Enable */
#define C1_R_BYP                    (* (reg8 *) C1_R__BYP)
/* Port wide control signals */                                                   
#define C1_R_CTL                    (* (reg8 *) C1_R__CTL)
/* Drive Modes */
#define C1_R_DM0                    (* (reg8 *) C1_R__DM0) 
#define C1_R_DM1                    (* (reg8 *) C1_R__DM1)
#define C1_R_DM2                    (* (reg8 *) C1_R__DM2) 
/* Input Buffer Disable Override */
#define C1_R_INP_DIS                (* (reg8 *) C1_R__INP_DIS)
/* LCD Common or Segment Drive */
#define C1_R_LCD_COM_SEG            (* (reg8 *) C1_R__LCD_COM_SEG)
/* Enable Segment LCD */
#define C1_R_LCD_EN                 (* (reg8 *) C1_R__LCD_EN)
/* Slew Rate Control */
#define C1_R_SLW                    (* (reg8 *) C1_R__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define C1_R_PRTDSI__CAPS_SEL       (* (reg8 *) C1_R__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define C1_R_PRTDSI__DBL_SYNC_IN    (* (reg8 *) C1_R__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define C1_R_PRTDSI__OE_SEL0        (* (reg8 *) C1_R__PRTDSI__OE_SEL0) 
#define C1_R_PRTDSI__OE_SEL1        (* (reg8 *) C1_R__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define C1_R_PRTDSI__OUT_SEL0       (* (reg8 *) C1_R__PRTDSI__OUT_SEL0) 
#define C1_R_PRTDSI__OUT_SEL1       (* (reg8 *) C1_R__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define C1_R_PRTDSI__SYNC_OUT       (* (reg8 *) C1_R__PRTDSI__SYNC_OUT) 


#if defined(C1_R__INTSTAT)  /* Interrupt Registers */

    #define C1_R_INTSTAT                (* (reg8 *) C1_R__INTSTAT)
    #define C1_R_SNAP                   (* (reg8 *) C1_R__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_C1_R_H */


/* [] END OF FILE */
