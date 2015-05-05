/*******************************************************************************
* File Name: Transmitting.h  
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

#if !defined(CY_PINS_Transmitting_H) /* Pins Transmitting_H */
#define CY_PINS_Transmitting_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Transmitting_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Transmitting__PORT == 15 && ((Transmitting__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Transmitting_Write(uint8 value) ;
void    Transmitting_SetDriveMode(uint8 mode) ;
uint8   Transmitting_ReadDataReg(void) ;
uint8   Transmitting_Read(void) ;
uint8   Transmitting_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Transmitting_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Transmitting_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Transmitting_DM_RES_UP          PIN_DM_RES_UP
#define Transmitting_DM_RES_DWN         PIN_DM_RES_DWN
#define Transmitting_DM_OD_LO           PIN_DM_OD_LO
#define Transmitting_DM_OD_HI           PIN_DM_OD_HI
#define Transmitting_DM_STRONG          PIN_DM_STRONG
#define Transmitting_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Transmitting_MASK               Transmitting__MASK
#define Transmitting_SHIFT              Transmitting__SHIFT
#define Transmitting_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Transmitting_PS                     (* (reg8 *) Transmitting__PS)
/* Data Register */
#define Transmitting_DR                     (* (reg8 *) Transmitting__DR)
/* Port Number */
#define Transmitting_PRT_NUM                (* (reg8 *) Transmitting__PRT) 
/* Connect to Analog Globals */                                                  
#define Transmitting_AG                     (* (reg8 *) Transmitting__AG)                       
/* Analog MUX bux enable */
#define Transmitting_AMUX                   (* (reg8 *) Transmitting__AMUX) 
/* Bidirectional Enable */                                                        
#define Transmitting_BIE                    (* (reg8 *) Transmitting__BIE)
/* Bit-mask for Aliased Register Access */
#define Transmitting_BIT_MASK               (* (reg8 *) Transmitting__BIT_MASK)
/* Bypass Enable */
#define Transmitting_BYP                    (* (reg8 *) Transmitting__BYP)
/* Port wide control signals */                                                   
#define Transmitting_CTL                    (* (reg8 *) Transmitting__CTL)
/* Drive Modes */
#define Transmitting_DM0                    (* (reg8 *) Transmitting__DM0) 
#define Transmitting_DM1                    (* (reg8 *) Transmitting__DM1)
#define Transmitting_DM2                    (* (reg8 *) Transmitting__DM2) 
/* Input Buffer Disable Override */
#define Transmitting_INP_DIS                (* (reg8 *) Transmitting__INP_DIS)
/* LCD Common or Segment Drive */
#define Transmitting_LCD_COM_SEG            (* (reg8 *) Transmitting__LCD_COM_SEG)
/* Enable Segment LCD */
#define Transmitting_LCD_EN                 (* (reg8 *) Transmitting__LCD_EN)
/* Slew Rate Control */
#define Transmitting_SLW                    (* (reg8 *) Transmitting__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Transmitting_PRTDSI__CAPS_SEL       (* (reg8 *) Transmitting__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Transmitting_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Transmitting__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Transmitting_PRTDSI__OE_SEL0        (* (reg8 *) Transmitting__PRTDSI__OE_SEL0) 
#define Transmitting_PRTDSI__OE_SEL1        (* (reg8 *) Transmitting__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Transmitting_PRTDSI__OUT_SEL0       (* (reg8 *) Transmitting__PRTDSI__OUT_SEL0) 
#define Transmitting_PRTDSI__OUT_SEL1       (* (reg8 *) Transmitting__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Transmitting_PRTDSI__SYNC_OUT       (* (reg8 *) Transmitting__PRTDSI__SYNC_OUT) 


#if defined(Transmitting__INTSTAT)  /* Interrupt Registers */

    #define Transmitting_INTSTAT                (* (reg8 *) Transmitting__INTSTAT)
    #define Transmitting_SNAP                   (* (reg8 *) Transmitting__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Transmitting_H */


/* [] END OF FILE */
