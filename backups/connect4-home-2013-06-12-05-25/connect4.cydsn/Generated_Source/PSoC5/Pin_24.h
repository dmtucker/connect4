/*******************************************************************************
* File Name: Pin_24.h  
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

#if !defined(CY_PINS_Pin_24_H) /* Pins Pin_24_H */
#define CY_PINS_Pin_24_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_24_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_24__PORT == 15 && ((Pin_24__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_24_Write(uint8 value) ;
void    Pin_24_SetDriveMode(uint8 mode) ;
uint8   Pin_24_ReadDataReg(void) ;
uint8   Pin_24_Read(void) ;
uint8   Pin_24_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_24_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pin_24_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pin_24_DM_RES_UP          PIN_DM_RES_UP
#define Pin_24_DM_RES_DWN         PIN_DM_RES_DWN
#define Pin_24_DM_OD_LO           PIN_DM_OD_LO
#define Pin_24_DM_OD_HI           PIN_DM_OD_HI
#define Pin_24_DM_STRONG          PIN_DM_STRONG
#define Pin_24_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pin_24_MASK               Pin_24__MASK
#define Pin_24_SHIFT              Pin_24__SHIFT
#define Pin_24_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_24_PS                     (* (reg8 *) Pin_24__PS)
/* Data Register */
#define Pin_24_DR                     (* (reg8 *) Pin_24__DR)
/* Port Number */
#define Pin_24_PRT_NUM                (* (reg8 *) Pin_24__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_24_AG                     (* (reg8 *) Pin_24__AG)                       
/* Analog MUX bux enable */
#define Pin_24_AMUX                   (* (reg8 *) Pin_24__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_24_BIE                    (* (reg8 *) Pin_24__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_24_BIT_MASK               (* (reg8 *) Pin_24__BIT_MASK)
/* Bypass Enable */
#define Pin_24_BYP                    (* (reg8 *) Pin_24__BYP)
/* Port wide control signals */                                                   
#define Pin_24_CTL                    (* (reg8 *) Pin_24__CTL)
/* Drive Modes */
#define Pin_24_DM0                    (* (reg8 *) Pin_24__DM0) 
#define Pin_24_DM1                    (* (reg8 *) Pin_24__DM1)
#define Pin_24_DM2                    (* (reg8 *) Pin_24__DM2) 
/* Input Buffer Disable Override */
#define Pin_24_INP_DIS                (* (reg8 *) Pin_24__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_24_LCD_COM_SEG            (* (reg8 *) Pin_24__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_24_LCD_EN                 (* (reg8 *) Pin_24__LCD_EN)
/* Slew Rate Control */
#define Pin_24_SLW                    (* (reg8 *) Pin_24__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_24_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_24__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_24_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_24__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_24_PRTDSI__OE_SEL0        (* (reg8 *) Pin_24__PRTDSI__OE_SEL0) 
#define Pin_24_PRTDSI__OE_SEL1        (* (reg8 *) Pin_24__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_24_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_24__PRTDSI__OUT_SEL0) 
#define Pin_24_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_24__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_24_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_24__PRTDSI__SYNC_OUT) 


#if defined(Pin_24__INTSTAT)  /* Interrupt Registers */

    #define Pin_24_INTSTAT                (* (reg8 *) Pin_24__INTSTAT)
    #define Pin_24_SNAP                   (* (reg8 *) Pin_24__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_24_H */


/* [] END OF FILE */
