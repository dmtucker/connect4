/*******************************************************************************
* File Name: Transmission.h  
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

#if !defined(CY_PINS_Transmission_H) /* Pins Transmission_H */
#define CY_PINS_Transmission_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Transmission_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Transmission__PORT == 15 && ((Transmission__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Transmission_Write(uint8 value) ;
void    Transmission_SetDriveMode(uint8 mode) ;
uint8   Transmission_ReadDataReg(void) ;
uint8   Transmission_Read(void) ;
uint8   Transmission_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Transmission_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Transmission_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Transmission_DM_RES_UP          PIN_DM_RES_UP
#define Transmission_DM_RES_DWN         PIN_DM_RES_DWN
#define Transmission_DM_OD_LO           PIN_DM_OD_LO
#define Transmission_DM_OD_HI           PIN_DM_OD_HI
#define Transmission_DM_STRONG          PIN_DM_STRONG
#define Transmission_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Transmission_MASK               Transmission__MASK
#define Transmission_SHIFT              Transmission__SHIFT
#define Transmission_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Transmission_PS                     (* (reg8 *) Transmission__PS)
/* Data Register */
#define Transmission_DR                     (* (reg8 *) Transmission__DR)
/* Port Number */
#define Transmission_PRT_NUM                (* (reg8 *) Transmission__PRT) 
/* Connect to Analog Globals */                                                  
#define Transmission_AG                     (* (reg8 *) Transmission__AG)                       
/* Analog MUX bux enable */
#define Transmission_AMUX                   (* (reg8 *) Transmission__AMUX) 
/* Bidirectional Enable */                                                        
#define Transmission_BIE                    (* (reg8 *) Transmission__BIE)
/* Bit-mask for Aliased Register Access */
#define Transmission_BIT_MASK               (* (reg8 *) Transmission__BIT_MASK)
/* Bypass Enable */
#define Transmission_BYP                    (* (reg8 *) Transmission__BYP)
/* Port wide control signals */                                                   
#define Transmission_CTL                    (* (reg8 *) Transmission__CTL)
/* Drive Modes */
#define Transmission_DM0                    (* (reg8 *) Transmission__DM0) 
#define Transmission_DM1                    (* (reg8 *) Transmission__DM1)
#define Transmission_DM2                    (* (reg8 *) Transmission__DM2) 
/* Input Buffer Disable Override */
#define Transmission_INP_DIS                (* (reg8 *) Transmission__INP_DIS)
/* LCD Common or Segment Drive */
#define Transmission_LCD_COM_SEG            (* (reg8 *) Transmission__LCD_COM_SEG)
/* Enable Segment LCD */
#define Transmission_LCD_EN                 (* (reg8 *) Transmission__LCD_EN)
/* Slew Rate Control */
#define Transmission_SLW                    (* (reg8 *) Transmission__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Transmission_PRTDSI__CAPS_SEL       (* (reg8 *) Transmission__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Transmission_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Transmission__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Transmission_PRTDSI__OE_SEL0        (* (reg8 *) Transmission__PRTDSI__OE_SEL0) 
#define Transmission_PRTDSI__OE_SEL1        (* (reg8 *) Transmission__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Transmission_PRTDSI__OUT_SEL0       (* (reg8 *) Transmission__PRTDSI__OUT_SEL0) 
#define Transmission_PRTDSI__OUT_SEL1       (* (reg8 *) Transmission__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Transmission_PRTDSI__SYNC_OUT       (* (reg8 *) Transmission__PRTDSI__SYNC_OUT) 


#if defined(Transmission__INTSTAT)  /* Interrupt Registers */

    #define Transmission_INTSTAT                (* (reg8 *) Transmission__INTSTAT)
    #define Transmission_SNAP                   (* (reg8 *) Transmission__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Transmission_H */


/* [] END OF FILE */
