/*******************************************************************************
* File Name: Accelerator.h  
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

#if !defined(CY_PINS_Accelerator_H) /* Pins Accelerator_H */
#define CY_PINS_Accelerator_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Accelerator_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Accelerator__PORT == 15 && ((Accelerator__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Accelerator_Write(uint8 value) ;
void    Accelerator_SetDriveMode(uint8 mode) ;
uint8   Accelerator_ReadDataReg(void) ;
uint8   Accelerator_Read(void) ;
uint8   Accelerator_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Accelerator_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Accelerator_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Accelerator_DM_RES_UP          PIN_DM_RES_UP
#define Accelerator_DM_RES_DWN         PIN_DM_RES_DWN
#define Accelerator_DM_OD_LO           PIN_DM_OD_LO
#define Accelerator_DM_OD_HI           PIN_DM_OD_HI
#define Accelerator_DM_STRONG          PIN_DM_STRONG
#define Accelerator_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Accelerator_MASK               Accelerator__MASK
#define Accelerator_SHIFT              Accelerator__SHIFT
#define Accelerator_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Accelerator_PS                     (* (reg8 *) Accelerator__PS)
/* Data Register */
#define Accelerator_DR                     (* (reg8 *) Accelerator__DR)
/* Port Number */
#define Accelerator_PRT_NUM                (* (reg8 *) Accelerator__PRT) 
/* Connect to Analog Globals */                                                  
#define Accelerator_AG                     (* (reg8 *) Accelerator__AG)                       
/* Analog MUX bux enable */
#define Accelerator_AMUX                   (* (reg8 *) Accelerator__AMUX) 
/* Bidirectional Enable */                                                        
#define Accelerator_BIE                    (* (reg8 *) Accelerator__BIE)
/* Bit-mask for Aliased Register Access */
#define Accelerator_BIT_MASK               (* (reg8 *) Accelerator__BIT_MASK)
/* Bypass Enable */
#define Accelerator_BYP                    (* (reg8 *) Accelerator__BYP)
/* Port wide control signals */                                                   
#define Accelerator_CTL                    (* (reg8 *) Accelerator__CTL)
/* Drive Modes */
#define Accelerator_DM0                    (* (reg8 *) Accelerator__DM0) 
#define Accelerator_DM1                    (* (reg8 *) Accelerator__DM1)
#define Accelerator_DM2                    (* (reg8 *) Accelerator__DM2) 
/* Input Buffer Disable Override */
#define Accelerator_INP_DIS                (* (reg8 *) Accelerator__INP_DIS)
/* LCD Common or Segment Drive */
#define Accelerator_LCD_COM_SEG            (* (reg8 *) Accelerator__LCD_COM_SEG)
/* Enable Segment LCD */
#define Accelerator_LCD_EN                 (* (reg8 *) Accelerator__LCD_EN)
/* Slew Rate Control */
#define Accelerator_SLW                    (* (reg8 *) Accelerator__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Accelerator_PRTDSI__CAPS_SEL       (* (reg8 *) Accelerator__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Accelerator_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Accelerator__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Accelerator_PRTDSI__OE_SEL0        (* (reg8 *) Accelerator__PRTDSI__OE_SEL0) 
#define Accelerator_PRTDSI__OE_SEL1        (* (reg8 *) Accelerator__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Accelerator_PRTDSI__OUT_SEL0       (* (reg8 *) Accelerator__PRTDSI__OUT_SEL0) 
#define Accelerator_PRTDSI__OUT_SEL1       (* (reg8 *) Accelerator__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Accelerator_PRTDSI__SYNC_OUT       (* (reg8 *) Accelerator__PRTDSI__SYNC_OUT) 


#if defined(Accelerator__INTSTAT)  /* Interrupt Registers */

    #define Accelerator_INTSTAT                (* (reg8 *) Accelerator__INTSTAT)
    #define Accelerator_SNAP                   (* (reg8 *) Accelerator__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Accelerator_H */


/* [] END OF FILE */
